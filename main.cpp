#include "raylib.h"
#include "raymath.h"
#include "includes/character.h"

int main()
{
    //initiating window
    const int winWidth{500}, winHeight{500};
    InitWindow(winWidth, winHeight, "rpg");

    // Loading worldmap
    Texture2D worldMap = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    // Rectangle worldMapRec{0.0, 0.0, worldMap.width, worldMap.height};
    Vector2 worldMapPos{0.0, 0.0};

    //making a character object
    Character knight;
    knight.setScreenPos(winWidth, winHeight);

    //setting target fps(frames per second)
    SetTargetFPS(60);
    //main game logic
    while (!WindowShouldClose()) //while x or esc isnt pressed
    {
        //start drawing the window
        BeginDrawing();
        //refresh each frame with white
        ClearBackground(WHITE);

        //getting world pos of character and moving map pos with input direction
        worldMapPos = Vector2Scale(knight.getWorldPos(), -1);

        //drawing worldmap on window after all operations done on it
        DrawTextureEx(worldMap, worldMapPos, 0.0, 4.0, WHITE);

        //calling the character movement and animation logic
        knight.tick(GetFrameTime());

        //end drawing the window
        EndDrawing();
    }
    //unload worldmap
    UnloadTexture(worldMap);
    //close window
    CloseWindow();
}