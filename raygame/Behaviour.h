#include "Agent.h"
#include "raylib.h"
#pragma once

class Behaviour 
{
public:

	// Empty constructors and destructors for base class
	Behaviour() {}
	virtual ~Behaviour() {}

	// pure virtual function for executing the behaviour
	virtual Vector2 update(Agent* agent, float deltaTime) = 0;
};