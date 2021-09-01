#include "raylib.h"
#include "raymath.h"
#include "character.h"
#include "prop.h"
#include "enemy.h"
#include "baseCharacter.h"

int main()
{
    //initiating window
    const int winWidth{384}, winHeight{384};
    InitWindow(winWidth, winHeight, "rpg");

    // Loading worldmap
    Texture2D worldMap = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    // Rectangle worldMapRec{0.0, 0.0, worldMap.width, worldMap.height};
    Vector2 worldMapPos{0.0, 0.0};
    const float mapScale{4.0f};

    //making a character object
    Character knight{winWidth, winHeight};

    //making a prop object
    prop props[2]{
            prop{Vector2{600.0f, 300.0f}, LoadTexture("nature_tileset/Rock.png")},
            prop{Vector2{400.0f, 500.0f}, LoadTexture("nature_tileset/Log.png")}
        };

    enemy goblin{
        Vector2{},
        LoadTexture("characters/goblin_idle_spritesheet.png"),
        LoadTexture("characters/goblin_run_spritesheet.png"),
    };

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

        //rendering props on screen
        for (auto prop : props) //for each item in props
        {
            prop.Render(knight.getWorldPos());
        }

        //calling the character movement and animation logic
        knight.tick(GetFrameTime());

        //defining movement border
        if(knight.getWorldPos().x < 0.0f ||
           knight.getWorldPos().y < 0.0f ||
           knight.getWorldPos().x + winWidth > worldMap.width * mapScale ||
           knight.getWorldPos().y + winHeight > worldMap.height * mapScale)
        {
            knight.undoMovement();
        }

        //checks prop collision
        for (auto prop : props)
        {
            if (CheckCollisionRecs(prop.getCollisionRec(knight.getWorldPos()), knight.getCollisionRec()))
            {
                knight.undoMovement();
            }
        }

        goblin.tick(GetFrameTime());

        //end drawing the window
        EndDrawing();
    }
    //unload worldmap
    UnloadTexture(worldMap);
    //close window
    CloseWindow();
}