#include "baseCharacter.h"

baseCharacter::baseCharacter()
{
    
}


void baseCharacter::undoMovement()
{
    worldPos = worldPosLastFrame;
}

Rectangle baseCharacter::getCollisionRec()
{
    return Rectangle{
        screenPos.x,
        screenPos.y,
        width * scale,
        height * scale
    };
}

void baseCharacter::tick(float deltaTime)
{
    worldPosLastFrame = worldPos;

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
    Rectangle source{frame * width, 0.0f, rightLeft * width, height}; //rectangle source is sprite sheet source where we are using first sprite
    Rectangle dest{screenPos.x, screenPos.y, scale * width, scale * height};   //character location on screen
    DrawTexturePro(texture, source, dest, Vector2{}, 0.0f, WHITE);
}