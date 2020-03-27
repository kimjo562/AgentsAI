#include "raylib.h"
#include <vector>
#pragma once

class Behaviour;

class Agent
{
public:
	Agent() {}
	virtual ~Agent() {}

	// Update the agent and its behaviours
	virtual void update(float deltaTime);

	// Draw the agent
	virtual void draw();

	// Add a behaviour to the agent
	void addBehaviour(Behaviour* behaviour);

	// Add a force to the agent's velocity
	void addForce(Vector2 force);

	// Movement functions
	void setPosition(Vector2 position) { m_Position = position; }
	Vector2 getPosition() { return m_Position; }
	void setVelocity(Vector2 velocity) { m_Velocity = velocity; }
	Vector2 getVelocity() { return m_Velocity; }

	//Speed functions
	void setSpeed(float speed) { m_speed = speed; }
	float getSpeed() { return m_speed; }

	// Color Function
	void setColor(Color color) { m_color = color; }
	Color getColor() { return m_color; }

protected:
	std::vector<Behaviour*> m_BehaviourList;
	Vector2 m_Position = {0, 0};
	Vector2 m_Velocity = {0, 0};

	float m_speed = 200.0f;
	Color m_color = VIOLET;
};