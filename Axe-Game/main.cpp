/*
    * main.cpp
    * Create a game where 
    * Created by Leon Lowe
*/

#include "raylib.h"

int main()
{
    //Window Variables
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;
    const char* WINDOW_NAME = "Axe Game";
    const Color WINDOW_COLOUR = GRAY;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);

    //Circle Variables
    int circleX = 55;
    int circleY = SCREEN_HEIGHT / 2;
    int CIRCLE_RADIUS = 50;
    const Color CIRCLE_COLOUR = BLUE;
    const int CIRCLE_SPEED = 3;

    //Axe Variables
    int axeX = SCREEN_WIDTH / 2;
    int axeY = 0;
    const int AXE_WIDTH = 100;
    const int AXE_HEIGHT = 50;
    const Color AXE_COLOUR = RED;
    const int AXE_SPEED = 5;
    int axeDirection = 1;

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
        DrawCircle(circleX, circleY, CIRCLE_RADIUS, CIRCLE_COLOUR);
        DrawRectangle(axeX, axeY, AXE_WIDTH, AXE_HEIGHT, AXE_COLOUR);

        //Move Axe
        axeY += (axeDirection * AXE_SPEED);
        if((axeY + AXE_HEIGHT) >= SCREEN_HEIGHT || axeY <= 0)
        {
            axeDirection *= -1;
        }
        
        //Horizontal Movement
        if (IsKeyDown(KEY_D) && circleX <= (SCREEN_WIDTH - CIRCLE_RADIUS))
        {
            circleX += (1 * CIRCLE_SPEED);
        }
        if (IsKeyDown(KEY_A) && circleX >= (0 + CIRCLE_RADIUS))
        {
            circleX += (-1 * CIRCLE_SPEED);
        }

        //Vertical Movement
        if (IsKeyDown(KEY_W) && circleY >= (0 + CIRCLE_RADIUS))
        {
            circleY += (-1 * CIRCLE_SPEED);
        }
        if (IsKeyDown(KEY_S) && circleY <= (SCREEN_HEIGHT - CIRCLE_RADIUS))
        {
            circleY += (1 * CIRCLE_SPEED);
        }
        //End Game Logic

        EndDrawing();
    }

    return 0;
}