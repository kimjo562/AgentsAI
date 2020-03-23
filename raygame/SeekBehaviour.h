#include "Agent.h"
#include "Behaviour.h"
#pragma once

class SeekBehaviour : public Behaviour
{
public:
	SeekBehaviour();
	virtual ~SeekBehaviour();
	virtual Vector2 update(Agent* agent, float deltaTime);
	void setTarget(Agent* agent) { m_target = agent; }
private:
	Agent* m_target;
};