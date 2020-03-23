#include "SeekBehaviour.h"

SeekBehaviour::SeekBehaviour()
{
}

SeekBehaviour::~SeekBehaviour()
{
}

Vector2 SeekBehaviour::update(Agent * agent, float deltaTime)
{
	//If the target is null, return a zero vector
	if (agent == nullptr)
	{
		return Vector2({ 0,0 });
	}

	//Get this agent’s position

	//Get the position of the target agent

	//Calculate the vector describing the direction to the target and normalize it
	//Multiply the direction by the speed we want the agent to move
	//Subtract the agent’s current velocity from the result to get the force we need to apply
	//return the force


	return Vector2();
}
