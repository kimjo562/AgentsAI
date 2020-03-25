#include "WanderBehaviour.h"
#include <cstdlib>

Vector2 WanderBehaviour::update(Agent * agent, float deltaTime)
{
	float randRange = ((float)RAND_MAX) / 2;

	// Start with a random target on the edge of the circle with a set radius around the agent
	Vector2 targetPos = Vector2{ (float)rand() - randRange / 2, (float)rand() - randRange / 2 }.normalize() * m_radius;
	// Add a randomized vector to the target, with a magnitude specified by a jitter amount
	targetPos += Vector2{ (float)rand() - randRange / 2, (float)rand() - randRange / 2 }.normalize() * m_jitter;
	// Bring the target back to the radius of the sphere by normalizing it and scaling by the radius
	Vector2 distance = agent->getPosition() - targetPos;
	targetPos = targetPos.normalize() * sqrt((distance.x * distance.x) + (distance.y * distance.y)) * m_radius;

	// Add the agents heading, multiplied by the distance to the target
	Vector2 heading = agent->getVelocity().normalize();
	targetPos += heading * 250;

	if (agent == nullptr) return { 0, 0 };

	 //m_prevTarget.x = targetPos.x;
     //m_prevTarget.y = targetPos.y;

	//Seek target
	Vector2 pos = agent->getPosition();

	//Calculate the vector describing the direction to the target and normalize it 
	Vector2 direction = targetPos - pos;
	direction = direction.normalize();
	//Multiply the direction by the speed we want the agent to move
	direction = direction * 75;
	//Subtract the agent’s current velocity from the result to get the force we need to apply
	Vector2 force = direction - agent->getVelocity();
	return Vector2();
}

// https://gamedevelopment.tutsplus.com/tutorials/understanding-steering-behaviors-wander--gamedev-1624