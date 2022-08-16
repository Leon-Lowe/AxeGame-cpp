/*
    * main.cpp
    * Create a game where 
    * Created by Leon Lowe
*/

#include "raylib.h"

int main()
{
    //Window Variables
    const int SCREEN_WIDTH = 1080;
    const int SCREEN_HEIGHT = 720;
    const char* WINDOW_NAME = "Axe Game";
    const Color WINDOW_COLOUR = GRAY;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);

    //Circle Variables
    int circleX = SCREEN_WIDTH / 2;
    int circleY = SCREEN_HEIGHT / 2;
    int circleRadius = 50;
    const Color CIRCLE_COLOUR = BLUE;
    const int CIRCLE_SPEED = 3;

    //Main Game Loop
    bool running = true;

    SetTargetFPS(60);

    while(running)
    {
        if(WindowShouldClose() == true)
        {
            running = false;
        }

        BeginDrawing();
        ClearBackground(WINDOW_COLOUR);

        //Begin Game Logic
        DrawCircle(circleX, circleY, circleRadius, CIRCLE_COLOUR);
        
        //Horizontal Movement
        if (IsKeyDown(KEY_D) && circleX <= (SCREEN_WIDTH - circleRadius))
        {
            circleX += (1 * CIRCLE_SPEED);
        }
        if (IsKeyDown(KEY_A) && circleX >= (0 + circleRadius))
        {
            circleX += (-1 * CIRCLE_SPEED);
        }

        //Vertical Movement
        if (IsKeyDown(KEY_W) && circleY >= (0 + circleRadius))
        {
            circleY += (-1 * CIRCLE_SPEED);
        }
        if (IsKeyDown(KEY_S) && circleY <= (SCREEN_HEIGHT - circleRadius))
        {
            circleY += (1 * CIRCLE_SPEED);
        }
        //End Game Logic

        EndDrawing();
    }

    return 0;
}