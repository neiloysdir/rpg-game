#include"raylib.h"

class Character
{
public:
    Vector2 getWorldPos() { return worldPos; }
    void setScreenPos(int width, int height);
    void tick(float deltaTime);

private:
    Texture2D texture = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D idle = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D run = LoadTexture("characters/knight_run_spritesheet.png");

    Vector2 screenPos;
    Vector2 worldPos;

    //setting linear direction variable
    float rightLeft{1.0f}; //1 means facing right -1 means facing left

    //animation variables
    float runningTime{};
    int frame{};
    const int maxFrame{6};
    const float updateTime{1.0f / 12.0f};
    const float speed{4.0f};
};