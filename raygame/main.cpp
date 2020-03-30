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
#include "ScreenBehaviour.h"
#include "FiniteStateMachine.h"
#include "IdleState.h"
#include "EnemyAttackState.h"
#include "WithinRangeCondition.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 980;
	int screenHeight = 550;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);

	Agent* player = new Agent();
	player->setPosition(Vector2{ 200.0f, 200.0f });
	player->setSpeed(200.0f);
	player->setColor(VIOLET);
	// Create and add the keyboard Behaviour
	KeyboardBehaviour* keyboardBehaviour = new KeyboardBehaviour();
	player->addBehaviour(keyboardBehaviour);
	ScreenBehaviour* screenBehaviour = new ScreenBehaviour();
	player->addBehaviour(screenBehaviour);

	// Create the enemy
	Agent* enemy = new Agent();
	enemy->setPosition(Vector2{ 300.0f, 300.0f });
	enemy->setSpeed(175.0f);
	enemy->setColor(LIME);
	// Create the enemy's FSM
	FSM* enemyFSM = new FSM();
	// Create and add the states
	IdleState* idleState = new IdleState();
	enemyFSM->addState(idleState);
	EnemyAttackState* attackState = new EnemyAttackState(player, 175.0f);
	enemyFSM->addState(attackState);
	// Create and add the condition
	Condition* withinRangeCondition = new WithinRangeCondition(player, 200);
	enemyFSM->addCondition(withinRangeCondition);
	// Create and add the Transition
	Transition* toAttackTransition = new Transition(attackState, withinRangeCondition);
	enemyFSM->addTransition(toAttackTransition);
	idleState->addTransition(toAttackTransition);
	// Set current state to idle
	enemyFSM->setCurrentState(idleState);

	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		float deltaTime = GetFrameTime();
		player->update(deltaTime);
		enemy->update(deltaTime);

		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(BLACK);

		player->draw();
		enemy->draw();

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}