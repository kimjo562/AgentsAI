#include "Agent.h"
#include "Behaviour.h"
#pragma once

class ArrivalBehaviour : public Behaviour
{
public:
	ArrivalBehaviour() {}
	virtual ~ArrivalBehaviour() {}

	virtual Vector2 update(Agent* agent, float deltaTime);
	void setTarget(Agent* agent) { m_target = agent; }

private:
	Agent* m_target;
	float m_radius = 1;
	float m_distance = 0;
};