#include "Behaviour.h"
#include "Agent.h"

void Agent::update(float deltaTime)
{
	//Force is equal to zero
	Vector2 totalForce = { 0.0f, 0.0f };

	//foreach Behaviour in Behaviour list
	for (auto i = m_behaviourList.begin(); i != m_behaviourList.end(); i++)
	{
		// Call the Behaviour’s Update function
		Vector2 force = (*i)->update(this, deltaTime);

		// Add the returned value to Force
		totalForce += force;
	}	
	//Add Force multiplied by delta time to Velocity
	addForce(totalForce * deltaTime);

	//Add Velocity multiplied by delta time to Position
	m_position += m_velocity * (deltaTime);
}

void Agent::draw()
{
	DrawRectangle(m_position.x, m_position.y, 10, 10, m_color);
}

void Agent::addBehaviour(Behaviour* behaviour)
{
	// Add Behaviour to the Behaviour List
	m_behaviourList.insert(m_behaviourList.end(), behaviour);
}

void Agent::addForce(Vector2 force)
{
	m_velocity += force;
}
