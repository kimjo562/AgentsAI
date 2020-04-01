#include "Agent.h"
#pragma once

class SteeringForce
{
public:
	virtual Vector2 GetForce(Agent* agent) = 0;

};