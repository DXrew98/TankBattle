#pragma once
#include "TankBattleHeaders.h"

class Agent {
public:
	enum TurretState {SCAN, AIM, FIRE};
	enum BodyState	 {PATROL, PRESS, RETREAT};
	
	TurretState turretState;
	BodyState bodyState;

	tankNet::TankBattleStateData *Self;
	tankNet::TankBattleCommand Command;

	tankNet::TankBattleCommand update();

	// turret state functions
	void scan();
	void aim();
	void fire();

	// movement state functions
	void patrol();
	void press();
	void retreat();
};