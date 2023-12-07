#include <SDL2/SDL.h>

class Collision {
public:
    static bool checkCollision(const SDL_Rect& rect1, const SDL_Rect& rect2) {
        return (
            rect1.x < rect2.x + rect2.w &&
            rect1.x + rect1.w > rect2.x &&
            rect1.y < rect2.y + rect2.h &&
            rect1.y + rect1.h > rect2.y
        );
    }
};


