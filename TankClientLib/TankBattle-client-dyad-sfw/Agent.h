#pragma once
#include "TankBattleHeaders.h"
#include "VMMath.h"

class Agent {
public:
	Agent();
	enum TurretState {SCAN, AIM, FIRE} turretState = SCAN;
	enum BodyState	 {PATROL, PRESS, RETREAT} bodyState = PATROL;
	
	//tankNet::TankBattleStateData current, previous;
	tankNet::TankBattleCommand commandCurr;
	tankNet::TankBattleCommand commandPrev;
	

	tankNet::TankBattleCommand update(tankNet::TankBattleStateData * state, float deltaTime);

	andMath::vec2 cannonFwrd;
	andMath::vec2 currentPos;
	andMath::vec2 currentFwrd;
	andMath::vec2 prevPos;
	andMath::vec2 curTarget;
	unsigned targetID;

	float dt;
	float currentDT;
	bool needNewPatrolTarget = true;

	tankNet::TankBattleStateData currentState;
	tankNet::TankBattleStateData prevState;

	tankNet::TankTacticalInfo currentTactical;
	tankNet::TankTacticalInfo previousTactical;

	float randTimer;
	bool isAiming;
	int frameCount;

	// turret state functions
	void scan();
	void aim();
	void fire();

	// movement state functions
	void patrol();
	void press();
	void retreat();

	void moveTo(const andMath::vec2 &position);
	bool lookTo(const andMath::vec2 &direction, float tolerance = .97f);
};