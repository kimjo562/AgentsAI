#include "FiniteStateMachine.h"
#include "Transition.h"
#include "Agent.h"

eBehaviourResult FiniteStateMachine::execute(Agent* agent, float deltaTime)
{
	if (m_currentState != nullptr)
	{
		Transition* transition = m_currentState->getTriggeredTransition(agent);
		if (transition != nullptr) {
			m_currentState->exit(agent);
			m_currentState = transition->getTargetState();
			m_currentState->init(agent);
		}

		m_currentState->update(agent, deltaTime);
		return eBehaviourResult::SUCCESS;
	}
	return eBehaviourResult::FAILURE;
}
