#include "Behaviour.h"
#include "Agent.h"
#pragma once

class KeyboardBehaviour : public Behaviour
{
public:
	KeyboardBehaviour();
	virtual ~KeyboardBehaviour();
	virtual Vector2 update(Agent* agent, float deltaTime);
};