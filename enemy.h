#include "raylib.h"
#include "baseCharacter.h"
#include "character.h"

class enemy : public baseCharacter
{
public:
    enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture);
    virtual void tick(float deltaTime) override;
    void setTarget(Character* character) { target = character; }
private:
    Character* target;
};