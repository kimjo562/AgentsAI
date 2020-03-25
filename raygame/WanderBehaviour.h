#include "Behaviour.h"
#pragma once
class WanderBehaviour : public Behaviour
{
public:
	WanderBehaviour() {}
	virtual ~WanderBehaviour() {}

	virtual Vector2 update(Agent* agent, float deltaTime);

private:
	float m_radius = 1;
	float m_distance = 0;
	float m_jitter = 0;
	Agent* m_prevTarget = nullptr;
};

