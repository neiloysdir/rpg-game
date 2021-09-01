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