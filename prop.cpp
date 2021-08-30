#include "prop.h"
#include "raymath.h"

prop::prop(Vector2 pos, Texture2D tex)
{
    worldPos = pos;
    texture = tex;
}

void prop::Render (Vector2 knightPos)
{
    Vector2 screenPos { Vector2Subtract(worldPos, knightPos) };
    DrawTextureEx(texture, screenPos, 0.0f, scale, WHITE);
}