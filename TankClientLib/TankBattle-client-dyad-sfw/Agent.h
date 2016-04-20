#pragma once
#include "TankBattleHeaders.h"

class Agent {

	tankNet::TankBattleStateData *Self;
	tankNet::TankBattleCommand Command;


	

	// turret state functions
	void scan();
	void aim();
	void fire();

	// movement state functions
	void patrol();
	void press();
	void retreat();
};