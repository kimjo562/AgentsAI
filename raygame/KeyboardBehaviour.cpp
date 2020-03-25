#include "KeyboardBehaviour.h"
KeyboardBehaviour::KeyboardBehaviour()
{

}

KeyboardBehaviour::~KeyboardBehaviour()
{
}

Vector2 KeyboardBehaviour::update(Agent* agent, float deltaTime)
{
	Vector2 force = { 0, 0 };
	if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) force.y = -150.0f;
	if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) force.y = 150.0f;
	if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) force.x = -150.0f;
	if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) force.x = 150.0f;

	if (IsKeyDown(KEY_SPACE)) 
	{
		if (agent->getVelocity().x > 1 || agent->getVelocity().x < -1)
		{

		}
	} 
	return force;
}