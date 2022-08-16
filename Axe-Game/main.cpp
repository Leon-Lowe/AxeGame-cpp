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

    //Finish Variables
    const int FIN_X = SCREEN_WIDTH - 50;
    const int FIN_Y = 0;
    const int FIN_WIDTH = 50;
    const int FIN_HEIGHT = SCREEN_HEIGHT;
    const Color FIN_COLOUR = GREEN;

    //Fin Edges
    int lFinX = FIN_X;
    int rFinX = FIN_X + FIN_WIDTH;
    int uFinY = FIN_Y;
    int bFinY = FIN_Y + FIN_HEIGHT;

    //Main Game Loop
    bool running = true;

    SetTargetFPS(60);

    bool collisionWithAxe = false;
    bool collisionWithFin = false;

    while(running)
    {
        if(WindowShouldClose() == true)
        {
            running = false;
        }

        BeginDrawing();
        ClearBackground(WINDOW_COLOUR);

        if (collisionWithAxe)
        {
            DrawText("You Died!", 75, SCREEN_HEIGHT / 4, 250, RED);
        }
        else if (collisionWithFin)
        {
            DrawText("You Win!", 150, SCREEN_HEIGHT / 4, 250, GREEN);
        }
        else
        {
            DrawCircle(circleX, circleY, CIRCLE_RADIUS, CIRCLE_COLOUR);
            DrawRectangle(axeX, axeY, AXE_WIDTH, AXE_HEIGHT, AXE_COLOUR);
            DrawRectangle(FIN_X, FIN_Y, FIN_WIDTH, FIN_HEIGHT, FIN_COLOUR);

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

            //Collision Detection

            //Circle Edges
            int lCircleX = circleX - CIRCLE_RADIUS;
            int rCircleX = circleX + CIRCLE_RADIUS;
            int uCircleY = circleY - CIRCLE_RADIUS;
            int bCircleY = circleY + CIRCLE_RADIUS;

            //Axe Edges
            int lAxeX = axeX;
            int rAxeX = axeX + AXE_WIDTH;
            int uAxeY = axeY;
            int bAxeY = axeY + AXE_HEIGHT;

            //Check for Collision
            if((bAxeY >= uCircleY) && (uAxeY <= bCircleY) && (lAxeX <= rCircleX) && (rAxeX >= lCircleX))
            {
                collisionWithAxe = true;
            }

            if((bFinY >= uCircleY) && (uFinY <= bCircleY) && (lFinX <= rCircleX) && (rFinX >= lCircleX))
            {
                collisionWithFin = true;
            }
        }

        EndDrawing();
    }

    return 0;
}