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
#include "Behaviour.h"
#include "KeyboardBehaviour.h"
#include "SeekBehaviour.h"
#include "Agent.h"


int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);

	Agent* player = new Agent();
	player->setPosition({ 100.0f, 100.0f });
	KeyboardBehaviour* keyboardBehaviour = new KeyboardBehaviour();
	player->addBehaviour(keyboardBehaviour);

	Agent* enemy = new Agent();
	enemy->setPosition({ 300.0f, 300.0f });
	SeekBehaviour* seekBehaviour = new SeekBehaviour();
	seekBehaviour->setTarget(player);
	enemy->addBehaviour(seekBehaviour);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		player->update(GetFrameTime());
		enemy->update(GetFrameTime());
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