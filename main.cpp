#include "raylib.h"
#include "raymath.h"

class Character
{
    public:
        Vector2 getWorldPos() { return worldPos; }
    private:
        Texture2D texture;
        Texture2D idle;
        Texture2D run;

        Vector2 screenPos;
        Vector2 worldPos;

        //setting linear direction variable
        float rightLeft{1.0f}; //1 means facing right -1 means facing left

        //animation variables
        float runningTime{};
        int frame{};
        const int maxFrame{6};
        const float updateTime{1.0f/12.0f};
};

int main()
{
    //initiating window
    const int winWidth{500}, winHeight{500};
    InitWindow(winWidth, winHeight, "rpg");

    float speed{4.0};

    // Loading worldmap
    Texture2D worldMap = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    // Rectangle worldMapRec{0.0, 0.0, worldMap.width, worldMap.height};
    Vector2 worldMapPos{0.0, 0.0};

    //Loading character
    Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D knightIdle = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D knightRun = LoadTexture("characters/knight_run_spritesheet.png");
    Vector2 knightPos{
        (float)winWidth/2.0f - 4.0f * (0.5f*(float)knight.width/6.0f),
        (float)winHeight/2.0f - 4.0f * (0.5f*(float)knight.height)
    }; //half of window and width to position character on window center but since its gonna be
    //positioned in 0,0 we need to subtract half the character width and height as well so its centered
    //multiplied by 4 cause we are gonna scale to 4

    //setting linear direction variable
    float rightLeft{1.0f}; //1 means facing right -1 means facing left

    //animation variables
    float runningTime{};
    int frame{};
    const int maxFrame{6};
    const float updateTime{1.0f/12.0f};

    //setting target fps(frames per second)
    SetTargetFPS(60);
    //main game logic
    while(!WindowShouldClose()) //while x or esc isnt pressed
    {
        //start drawing the window
        BeginDrawing();
        //refresh each frame with white
        ClearBackground(WHITE);

        //set player direction
        Vector2 direction{0.0, 0.0}; //set within main game loop because we need direction to become 0 each frame
        if(IsKeyDown(KEY_A)) direction.x -= 1.0; //A for left
        if(IsKeyDown(KEY_D)) direction.x += 1.0; //D for right
        if(IsKeyDown(KEY_W)) direction.y -= 1.0; //W for up
        if(IsKeyDown(KEY_S)) direction.y += 1.0; //S for down
        if(Vector2Length(direction) != 0.0)
        {
            //worldmap position = worldmap position - normalized version of input directions multiplied by a speed factor
            worldMapPos = Vector2Subtract(worldMapPos, Vector2Scale(Vector2Normalize(direction), speed));
            direction.x < 0.0f ? rightLeft = -1.0f : rightLeft = 1.0f; //ternary operation, if else, sets character left or right based on input
            knight = knightRun; //if running set knight to running spritesheet
        }
        else
        {
            knight = knightIdle; //if not running set knight to idle spritesheet
        }

        //drawing worldmap on window after all operations done on it
        DrawTextureEx(worldMap, worldMapPos, 0.0, 4.0, WHITE);

        //update animation frame
        runningTime += GetFrameTime(); //like delta time
        if (runningTime >= updateTime) //everytime 12frames pass increase frame count set running time to default and if suprass max number of frames set frame to starting sprite
        {
            frame++;
            runningTime = 0.0f;
            if(frame > maxFrame) frame = 0;
        }

        //drawing character
        Rectangle source{ frame * (float)knight.width/6.0f, 0.0f, rightLeft * (float)knight.width/6.0f, (float)knight.height}; //rectangle source is sprite sheet source where we are using first sprite
        Rectangle dest{knightPos.x, knightPos.y, 4.0f * (float)knight.width/6.0f, 4.0f * (float)knight.height}; //character location on screen
        DrawTexturePro(knight, source, dest, Vector2{}, 0.0f, WHITE);

        //end drawing the window
        EndDrawing();
    }
    //unload worldmap
    UnloadTexture(worldMap);
    UnloadTexture(knight);
    UnloadTexture(knightIdle);
    UnloadTexture(knightRun);
    //close window
    CloseWindow();
}