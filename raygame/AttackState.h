#include "State.h"
#pragma once

class AttackState : public State {
public:
	AttackState(Agent* target, float speed) : m_target(target), m_speed(speed) {}
	virtual ~AttackState() {}
	virtual void update(Agent* gameObject, float deltaTime);

private:
	float m_speed;
	Agent* m_target;
};