#include "FleeBehaviour.h"

Vector2 FleeBehaviour::update(Agent * agent, float deltaTime)
{
	//If the target is null
	if (agent == nullptr)
	{
		// return a zero vector
		return Vector2({ 0,0 });
	}

	//Get this agent�s position
	Vector2 pos = agent->getPosition();
	//Get the position of the target agent
	Vector2 targetPos = m_target->getPosition();

	//Calculate the vector describing the direction to the target and normalize it 
	Vector2 direction = pos - targetPos;
	direction = direction.normalize();
	//Multiply the direction by the speed we want the agent to move
	direction = direction * 75;
	//Subtract the agent�s current velocity from the result to get the force we need to apply
	Vector2 force = direction - agent->getVelocity();

	//return the force
	return force;
}