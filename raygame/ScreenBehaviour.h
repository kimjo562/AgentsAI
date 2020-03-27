#include "Behaviour.h"
#pragma once

class ScreenBehaviour : public Behaviour
{
public:
	ScreenBehaviour() {}
	virtual ~ScreenBehaviour() {}

	virtual Vector2 update(Agent* agent, float deltaTime);
};

