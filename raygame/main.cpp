/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "Agent.h"
#include "Behaviour.h"
#include "KeyboardBehaviour.h"
#include "ArrivalBehaviour.h"
#include "SeekBehaviour.h"
#include "FleeBehaviour.h"
#include "WanderBehaviour.h"
#include "PursueBehaviour.h"
#include "EvadeBehaviour.h"
#include "ScreenBehaviour.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 980;
	int screenHeight = 550;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);

	Agent* player = new Agent();
	player->setPosition({ 200.0f, 200.0f });
	player->setSpeed(200.0f);
	player->setColor(VIOLET);
	KeyboardBehaviour* keyboardBehaviour = new KeyboardBehaviour();
	player->addBehaviour(keyboardBehaviour);
	ScreenBehaviour* screenBehaviour = new ScreenBehaviour();
	player->addBehaviour(screenBehaviour);

	Agent* seek = new Agent();
	seek->setPosition({ 400.0f, 400.0f });
	seek->setSpeed(175.0f);
	seek->setColor(ORANGE);
	SeekBehaviour* seekBehaviour = new SeekBehaviour();
	seek->addBehaviour(seekBehaviour);
	seekBehaviour->setTarget(player);
	seek->addBehaviour(screenBehaviour);

	Agent* pursue = new Agent();
	pursue->setPosition({ 420.0f, 420.0f });
	pursue->setSpeed(175.0f);
	pursue->setColor(RED);
	PursueBehaviour* pursuitBehaviour = new PursueBehaviour();
	pursue->addBehaviour(pursuitBehaviour);
	pursuitBehaviour->setTarget(player);
	pursue->addBehaviour(screenBehaviour);

	Agent* flee = new Agent();
	flee->setPosition({ 300.0f, 300.0f });
	flee->setSpeed(150.0f);
	flee->setColor(BLUE);
	FleeBehaviour* fleeBehaviour = new FleeBehaviour();
	flee->addBehaviour(fleeBehaviour);
	fleeBehaviour->setTarget(player);
	flee->addBehaviour(screenBehaviour);

	Agent* evade = new Agent();
	evade->setPosition({ 320.0f, 320.0f });
	evade->setSpeed(150.0f);
	evade->setColor(SKYBLUE);
	EvadeBehaviour* evadeBehaviour = new EvadeBehaviour();
	evade->addBehaviour(evadeBehaviour);
	evadeBehaviour->setTarget(player);
	evade->addBehaviour(screenBehaviour);

	Agent* wander = new Agent();
	wander->setPosition({ 500.0f, 500.0f });
	wander->setSpeed(100.0f);
	wander->setColor(LIME);
	WanderBehaviour* wanderBehaviour = new WanderBehaviour();
	wander->addBehaviour(wanderBehaviour);
	wander->addBehaviour(screenBehaviour);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		float deltaTime = GetFrameTime();
		player->update(deltaTime);
		seek->update(deltaTime);
		pursue->update(deltaTime);
		flee->update(deltaTime);
		evade->update(deltaTime);
		wander->update(deltaTime);
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(BLACK);

		player->draw();
		seek->draw();
		pursue->draw();
		flee->draw();
		evade->draw();
		wander->draw();

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}