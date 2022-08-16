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
    int rectX = SCREEN_WIDTH / 2;
    int rectY = 0;
    const int RECT_WIDTH = 100;
    const int RECT_HEIGHT = 50;
    const Color RECT_COLOUR = RED;
    const int RECT_SPEED = 5;

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
        DrawRectangle(rectX, rectY, RECT_WIDTH, RECT_HEIGHT, RECT_COLOUR);

        //Move Axe
        rectY += (1 * RECT_SPEED);
        
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