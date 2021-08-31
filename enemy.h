#include "raylib.h"

class enemy
{
public:
    enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture);
    Vector2 getWorldPos() { return worldPos; }
    void tick(float deltaTime);
    void undoMovement();
    Rectangle getCollisionRec();
private:
    Texture2D texture{LoadTexture("characters/goblin_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("characters/goblin_idle_spritesheet.png")};
    Texture2D run{LoadTexture("characters/goblin_run_spritesheet.png")};

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
};