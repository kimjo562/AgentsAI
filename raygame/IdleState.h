#include "State.h"
#pragma once

// just does nothing
class IdleState : public State 
{
public:
	IdleState() {}
	virtual ~IdleState() {}

	virtual void update(Agent* agent, float deltaTime) {}
};