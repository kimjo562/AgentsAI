#include "ArrivalBehaviour.h"

void ArrivalBehaviour::update(Agent * agent, float deltaTime)
{
	//If the target is null
	if (agent == nullptr || m_target == nullptr)
	{
		// return a zero vector
		return;
	}

	//Get this agent’s position
	Vector2 pos = agent->getPosition();
	//Get the position of the target agent
	Vector2 targetPos = m_target->getPosition();
	Vector2 desiredVel = agent->getVelocity() - m_target->getVelocity();
	
	//Calculate the vector describing the direction to the target and normalize it
	Vector2 direction = targetPos - pos;
	direction = direction.normalize();
	//Multiply the direction by the speed we want the agent to move
	direction = direction * agent->getSpeed();

	//Subtract the agent’s current velocity from the result to get the force we need to apply
	Vector2 force = direction - agent->getVelocity() - desiredVel;

	//return the force
	agent->addForce(force * deltaTime);
}

// https://gamedevelopment.tutsplus.com/tutorials/understanding-steering-behaviors-flee-and-arrival--gamedev-1303