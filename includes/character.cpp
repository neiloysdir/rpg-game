#include "character.h"
#include "raymath.h"

void Character::setScreenPos(int width, int height)
{
    screenPos = {
        (float)width / 2.0f - 4.0f * (0.5f * (float)texture.width / 6.0f),
        (float)height / 2.0f - 4.0f * (0.5f * (float)texture.height)};
    //half of window and width to position character on window center but since its gonna be
    //positioned in 0,0 we need to subtract half the character width and height as well so its centered
    //multiplied by 4 cause we are gonna scale to 4
}

void Character::tick(float deltaTime)
{
    //set player direction
    Vector2 direction{0.0, 0.0}; //set within main game loop because we need direction to become 0 each frame
    if (IsKeyDown(KEY_A))
        direction.x -= 1.0; //A for left
    if (IsKeyDown(KEY_D))
        direction.x += 1.0; //D for right
    if (IsKeyDown(KEY_W))
        direction.y -= 1.0; //W for up
    if (IsKeyDown(KEY_S))
        direction.y += 1.0; //S for down
    if (Vector2Length(direction) != 0.0)
    {
        //worldmap position = worldmap position + normalized version of input directions multiplied by a speed factor
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));
        direction.x < 0.0f ? rightLeft = -1.0f : rightLeft = 1.0f; //ternary operation, if else, sets character left or right based on input
        texture = run;                                             //if running set knight to running spritesheet
    }
    else
    {
        texture = idle; //if not running set knight to idle spritesheet
    }

    //update animation frame
    runningTime += deltaTime;      //like delta time
    if (runningTime >= updateTime) //everytime 12frames pass increase frame count set running time to default and if suprass max number of frames set frame to starting sprite
    {
        frame++;
        runningTime = 0.0f;
        if (frame > maxFrame)
            frame = 0;
    }

    //drawing character
    Rectangle source{frame * (float)texture.width / 6.0f, 0.0f, rightLeft * (float)texture.width / 6.0f, (float)texture.height}; //rectangle source is sprite sheet source where we are using first sprite
    Rectangle dest{screenPos.x, screenPos.y, 4.0f * (float)texture.width / 6.0f, 4.0f * (float)texture.height};                  //character location on screen
    DrawTexturePro(texture, source, dest, Vector2{}, 0.0f, WHITE);
}