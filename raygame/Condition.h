#include "Behaviour.h"
#pragma once

class Condition : public Behaviour 
{
public:
	Condition() {}
	virtual ~Condition() {}
	virtual bool test(Agent* agent) const = 0;
	virtual eBehaviourResult execute(Agent* agent, float deltaTime)
	{
		if (test(agent))
			return eBehaviourResult::SUCCESS;
		return eBehaviourResult::FAILURE;
	}
};