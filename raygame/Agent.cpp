#include "Agent.h"
#include "raylib.h"

void Agent::update(float deltaTime)
{
	//Force is equal to zero
	//for each Behaviour in Behaviour list
	//Call the Behaviour’s Update function and add the returned value to Force
	//Add Force multiplied by delta time to Velocity
	//Add Velocity multiplied by delta time to Position
}

void Agent::draw()
{
	DrawRectangle(m_Position.x, m_Position.y, 10, 10, MAROON);
}

void Agent::addBehaviour(Behaviour * behaviour)
{
}
