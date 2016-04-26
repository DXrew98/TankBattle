#pragma once
#include "TankBattleHeaders.h"
#include "VMMath.h"

class Agent {
public:
	enum TurretState {SCAN, AIM, FIRE} turretState = SCAN;
	enum BodyState	 {PATROL, PRESS, RETREAT} bodyState = PATROL;
	
	//tankNet::TankBattleStateData current, previous;
	tankNet::TankBattleCommand command;

	tankNet::TankBattleCommand update(tankNet::TankBattleStateData * state, float deltaTime);

	andMath::vec2 cannonFwrd;
	andMath::vec2 currentPos;
	andMath::vec2 curTarget;
	unsigned targetID;

	float dt;

	tankNet::TankBattleStateData currentState;
	tankNet::TankBattleStateData prevState;

	bool isAiming;

	// turret state functions
	void scan();
	void aim();
	void fire();

	// movement state functions
	void patrol();
	void press();
	void retreat();
};