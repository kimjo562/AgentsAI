#include "Behaviour.h"
#pragma once

class PursueBehaviour : public Behaviour
{
public:
	PursueBehaviour() {}
	virtual ~PursueBehaviour() {}

	virtual Vector2 update(Agent* agent, float deltaTime);
	void setTarget(Agent* agent) { m_target = agent; }

private:
	Agent* m_target;
};