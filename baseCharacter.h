#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H
#include "raylib.h"

class baseCharacter
{
public:
    baseCharacter();
    Vector2 getWorldPos() { return worldPos; }
    void undoMovement();
    Rectangle getCollisionRec();
    virtual void tick(float deltaTime);
protected:
    Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};

    Vector2 screenPos{};
    Vector2 worldPos{};
    Vector2 worldPosLastFrame{};

    //setting linear direction variable
    float rightLeft{1.0f}; //1 means facing right -1 means facing left

    //animation variables
    float runningTime{};
    int frame{};
    int maxFrame{6};
    float updateTime{1.0f / 12.0f};
    float speed{4.0f};
    float width{};
    float height{};
    float scale{4.0f};

private:

};

#endif