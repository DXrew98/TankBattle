#include "Agent.h"
#include "VMMath.h"


	tankNet::TankBattleCommand Agent::update() {

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
	}

	// Turret Functions 
	void Agent::scan()
	{ 
		
	}

	void Agent::aim()
	{

	}

	void Agent::fire()
	{

	}

	//Tank Drive Fuctions 
	void Agent::patrol()
	{

	}

	void Agent::press()
	{

	}

	void Agent::retreat()
	{

	}
