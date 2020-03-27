#include "Behaviour.h"
#include "Agent.h"
#include "raylib.h"

void Agent::update(float deltaTime)
{
	//Force is equal to zero
	Vector2 totalForce = { 0, 0 };

	//foreach Behaviour in Behaviour list
	for (auto i = m_BehaviourList.begin(); i != m_BehaviourList.end(); i++)
	{
		// Call the Behaviour’s Update function
		Vector2 force = (*i)->update(this, deltaTime);

		// Add the returned value to Force
		totalForce += force;
	}	
	//Add Force multiplied by delta time to Velocity
	addForce(totalForce * deltaTime);

	//Add Velocity multiplied by delta time to Position
	m_Position += m_Velocity * (deltaTime);
}

void Agent::draw()
{
	DrawRectangle(m_Position.x, m_Position.y, 10, 10, m_color);
}

void Agent::addBehaviour(Behaviour* behaviour)
{
	// Add Behaviour to the Behaviour List
	m_BehaviourList.insert(m_BehaviourList.end(), behaviour);
}

void Agent::addForce(Vector2 force)
{
	m_Velocity += force;
}
