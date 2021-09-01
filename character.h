#include "raylib.h"
#include "baseCharacter.h"

class Character : public baseCharacter
{
public:
    Character(int winWidth, int winHeight);
    void tick(float deltaTime);
private:

};