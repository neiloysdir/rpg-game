#include "raylib.h"
#include "baseCharacter.h"

class Character : public baseCharacter
{
public:
    Character(int winWidth, int winHeight);
    virtual void tick(float deltaTime) override;
private:

};