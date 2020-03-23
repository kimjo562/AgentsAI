#include "Agent.h"
#include "raylib.h"

void Agent::update(float deltaTime)
{
	//Force is equal to zero
	Vector2 force = { 0, 0 };

	//foreach Behaviour in Behaviour list
	for (auto i = m_BehaviourList.begin(); i < m_BehaviourList.end(); i++)
	{
		Behaviour* ptr = *i;
		// Call the Behaviour’s Update function and add the returned value to Force
		// Behaviour list* = new Behaviour();
		// i->update();

		// force += (*i)->update(this, deltaTime);
	}	

	force = /* the returned value */

	//Add Force multiplied by delta time to Velocity
	m_Velocity = m_Velocity + (force * deltaTime);

	//Add Velocity multiplied by delta time to Position
	m_Position = m_Position * (deltaTime);
}

void Agent::draw()
{
	DrawRectangle(m_Position.x, m_Position.y, 10, 10, PURPLE);
}

void Agent::addBehaviour(Behaviour * behaviour)
{

}
