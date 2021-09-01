#include "raylib.h"
#include "baseCharacter.h"

class enemy : public baseCharacter
{
public:
    enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture);
    void tick(float deltaTime);
private:
};