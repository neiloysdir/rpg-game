#include "raylib.h"

class prop
{
    public:
        prop(Vector2 pos, Texture2D tex);
    private:
        Texture2D texture{};
        Vector2 worldPos{};
        float scale{4.0f};
};