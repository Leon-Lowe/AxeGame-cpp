#include "raylib.h"

int main()
{
    const int SCREEN_WIDTH = 1080;
    const int SCREEN_HEIGHT = 720;
    const char* WINDOW_NAME = "Axe Game";

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);

    bool running = true;

    while(running)
    {
        BeginDrawing();
        ClearBackground(GRAY);
        EndDrawing();
    }

    return 0;
}