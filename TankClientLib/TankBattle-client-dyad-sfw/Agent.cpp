#include "Agent.h"
#include <iostream>

#undef RIGHT
#undef LEFT

Agent::Agent() {
	currentDT = 0.0f;
	randTimer = 0;
	frameCount = 0;
}

tankNet::TankBattleCommand Agent::update(tankNet::TankBattleStateData * state, float deltaTime ) {



	dt = deltaTime;
	prevState = currentState;
	currentState = *state;
	
	commandPrev = commandCurr;

	
	cannonFwrd = andMath::vec2{ currentState.cannonForward[0],	currentState.cannonForward[2] };
	currentPos = andMath::vec2{ currentState.position[0],		currentState.position[2] };
	currentFwrd = andMath::vec2{ currentState.forward[0],		currentState.forward[2] };
	prevPos	   = andMath::vec2{ prevState.position[0],			prevState.position[2] };
	
	commandCurr.msg = tankNet::TankBattleMessage::GAME;
	commandCurr.tankMove = tankNet::TankMovementOptions::HALT;
	commandCurr.cannonMove = tankNet::CannonMovementOptions::HALT;

	switch (turretState) {
		case SCAN: scan(); break;
		case AIM : aim (); break;
		case FIRE: fire(); break;
		}

	switch (bodyState) {
		case PATROL : patrol (); break;
		//case PRESS  : press  (); break;
		//case RETREAT: retreat(); break;
		}
	
	

	if (commandPrev.tankMove == commandCurr.tankMove
		&& commandCurr.tankMove < tankNet::TankMovementOptions::BACK
		&& (prevPos - currentPos).mag() < .1f)
		frameCount++;
	else frameCount = 0;

	if (frameCount > 24)
	{
		needNewPatrolTarget = true;
		std::cout << "Obstacle Hit" << std::endl;
	}


		return commandCurr;
	}

	// Turret Functions 
	void Agent::scan()
	{ 
		commandCurr.fireWish = false;
		commandCurr.cannonMove = tankNet::CannonMovementOptions::LEFT;

		//iterate through enemies to check if their in view
		for (int target = 0; target < currentState.playerCount - 1; ++target) {
			if (currentState.tacticoolData[target].inSight && currentState.canFire) {
				curTarget = andMath::vec2{ currentState.tacticoolData[target].lastKnownPosition[0], currentState.tacticoolData[target].lastKnownPosition[2] };

				targetID = target;
				if (andMath::dot(cannonFwrd, andMath::vec2(curTarget - currentPos).normal()) > 0.87f) {
					turretState = TurretState::AIM;
				}
				break;
			}
		}
	}

	void Agent::aim()
	{
		if (!isAiming)
		{
			isAiming = true;
		}
		else
		{
			
			//prevState.tacticoolData[targetID].lastKnownPosition;

			// Evaluate where we want to point
			//cannonFwrd = andMath::vec2{ currentState.tacticoolData[targetID].lastKnownPosition[0], currentState.tacticoolData[targetID].lastKnownPosition[2] };
			curTarget = andMath::vec2{ currentState.tacticoolData[targetID].lastKnownPosition[0], currentState.tacticoolData[targetID].lastKnownPosition[2] };

			// get cannon forward vec2
			// get direction


			if (lookTo(andMath::vec2{ currentState.tacticoolData[targetID].lastKnownDirection[0],
								      currentState.tacticoolData[targetID].lastKnownDirection[2] }))
			{
				turretState = TurretState::FIRE;
				isAiming = false;
			}

			if (!currentState.tacticoolData[targetID].inSight)
			{
				turretState = TurretState::SCAN;
				isAiming = false;
				needNewPatrolTarget = true;
			}

			//andMath::vec2 cannonRight = -cannonFwrd.perp();
			//if (dot(cannonFwrd, curTarget) < 0.98f) {
			//	if (dot(cannonRight, curTarget) >= 0.0f) {
			//		commandCurr.cannonMove = tankNet::CannonMovementOptions::RIGHT;
			//	}
			//	else {
			//		commandCurr.cannonMove = tankNet::CannonMovementOptions::LEFT;
			//	}
			//}
			//else {
			//	turretState = TurretState::FIRE;
			//}

			// Determine direction to the target (target - current.position)
			// May take into account the displacement or velocity of the target
			// target displacement : current.pos - previous.position
			// Determine if we're to the left or right		: is the cross negative or positive?
			// Determine if we're lined up enough to shoot  : is the dot product close to .91?
		} // whenever leave the state, set isAiming to false
	}

	void Agent::fire()
	{
		commandCurr.fireWish = true;
		turretState = TurretState::AIM;

	}


	void Agent::moveTo(const andMath::vec2 &position)
	{
		vec2 desired = (position - currentPos).normal();
		
		if (andMath::dot(currentFwrd, desired.perp()) > 0)
			commandCurr.tankMove = tankNet::TankMovementOptions::RIGHT;

		if (andMath::dot(currentFwrd, desired.perp()) < 0)
			commandCurr.tankMove = tankNet::TankMovementOptions::LEFT;

		if (andMath::dot(desired, currentFwrd) > .87f) // 60 degree flex-range
			commandCurr.tankMove = tankNet::TankMovementOptions::FWRD;
		
		if (andMath::dot(desired, currentFwrd) < -.87f)
			commandCurr.tankMove = tankNet::TankMovementOptions::BACK;
		
	}
	bool Agent::lookTo(const andMath::vec2 &direction, float tolerance)
	{	
		if (andMath::dot(cannonFwrd, direction.perp()) > 0)
			commandCurr.cannonMove = tankNet::CannonMovementOptions::RIGHT;

		if (andMath::dot(cannonFwrd, direction.perp()) < 0)
			commandCurr.cannonMove = tankNet::CannonMovementOptions::LEFT;

		return andMath::dot(cannonFwrd, direction) > tolerance;

	}


	//Tank Drive Fuctions 
	void Agent::patrol()
	{
		if (andMath::distance(curTarget, currentPos) <= 20)
			needNewPatrolTarget = true;
				
		if(needNewPatrolTarget)
		{
			needNewPatrolTarget = false;
			curTarget = andMath::vec2::random() * vec2 { 50, 50 };
		}

		moveTo(curTarget);
		/*
		andMath::vec2 targetFrwd = andMath::vec2(curTarget - currentPos).normal();

		if (andMath::dot(currentFwrd, andMath::vec2(curTarget - currentPos).normal()) > 0.87f) {
			commandCurr.tankMove = tankNet::TankMovementOptions::FWRD;
		}
		else {
			commandCurr.tankMove = tankNet::TankMovementOptions::LEFT;
		}

		if (andMath::dot(currentFwrd, curTarget) > 0.87f) {
			bodyState = BodyState::PRESS;
		}*/
	}

	void Agent::press()
	{
		commandCurr.tankMove = tankNet::TankMovementOptions::FWRD;
	}

	void Agent::retreat()
	{
		currentDT += dt;
		commandCurr.tankMove = tankNet::TankMovementOptions::BACK;
		std::cout << "dt: " << dt << " curr: " << currentDT << std::endl;
		if (currentDT > 4) {
				commandCurr.tankMove = tankNet::TankMovementOptions::HALT;
				bodyState = BodyState::PATROL;
				currentDT = 0.0f;
		}
	}
