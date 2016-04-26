#include "Agent.h"
#include <iostream>

#undef RIGHT
#undef LEFT

tankNet::TankBattleCommand Agent::update(tankNet::TankBattleStateData * state, float deltaTime ) {



	dt = deltaTime;
	prevState = currentState;
	currentState = *state;

	cannonFwrd = andMath::vec2{ currentState.cannonForward[0], currentState.cannonForward[2] };
	currentPos = andMath::vec2{ currentState.position[0],	currentState.position[2] };

		command.msg = tankNet::TankBattleMessage::GAME;
		command.tankMove = tankNet::TankMovementOptions::HALT;
		command.cannonMove = tankNet::CannonMovementOptions::HALT;

		switch (turretState) {
		case SCAN: scan(); break;
		case AIM : aim (); break;
		case FIRE: fire(); break;
		}

		switch (bodyState) {
		case PATROL : patrol (); break;
		case PRESS  : press  (); break;
		case RETREAT: retreat(); break;
		}

		return command;
	}

	// Turret Functions 
	void Agent::scan()
	{ 
		command.fireWish = false;
		command.cannonMove = tankNet::CannonMovementOptions::LEFT;

		//iterate through enemies to check if their in view
		for (int target = 0; target < currentState.playerCount - 1; ++target) {
			if (currentState.tacticoolData[target].inSight && currentState.canFire) {
				curTarget = andMath::vec2{ currentState.tacticoolData[target].lastKnownPosition[0], currentState.tacticoolData[target].lastKnownPosition[2] };

				targetID = target;
				//std::cout << andMath::dot(cannonFwrd, andMath::vec2(curTarget - currentPos).normal()) << std::endl;
				std::cout << "CF:" << cannonFwrd[0] << " " << cannonFwrd[2] << std::endl;
				std::cout << "CT:" << curTarget[0] << " " << curTarget[2] << std::endl;
				std::cout << "CP:" << currentPos[0] << " " << currentPos[2] << std::endl;
				if (andMath::dot(cannonFwrd, andMath::vec2(curTarget - currentPos).normal()) > 0.87f) {
					turretState = TurretState::FIRE;
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
			currentState.tacticoolData[targetID].lastKnownPosition;
			//prevState.tacticoolData[targetID].lastKnownPosition;


			// Evaluate where we want to point
			// Determine direction to the target (target - current.position)
			// May take into account the displacement or velocity of the target
			// target displacement : current.pos - previous.position
			// Determine if we're to the left or right		: is the cross negative or positive?
			// Determine if we're lined up enough to shoot  : is the dot product close to .91?
		} // whenever leave the state, set isAiming to false
	}

	void Agent::fire()
	{
		command.fireWish = true;
		/*todo rotate turret in chosen direction*/
		command.fireWish = true;
		//todo rotate turret in chosen direction
		command.fireWish = true;
		turretState = TurretState::SCAN;
	}

	//Tank Drive Fuctions 
	void Agent::patrol()
	{
		//myPos
		//way I am facing

	}

	void Agent::press()
	{

	}

	void Agent::retreat()
	{
		
	}
