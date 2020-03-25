#include "Agent.h"
#include "Behaviour.h"
#pragma once

class FleeBehaviour : public Behaviour
{
public:
	FleeBehaviour() {}
	virtual ~FleeBehaviour() {}

	virtual Vector2 update(Agent* agent, float deltaTime);
	void setTarget(Agent* agent) { m_target = agent; }

private:
	Agent* m_target = nullptr;
};