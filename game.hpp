// Game.h
#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>





class Game {
public:
    Game();
    ~Game();
    void runGame(char selected_character, int selected_level);
SDL_Texture* charactertexture;
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* backgroundTexture;
   // SDL_Texture* charactertexture;
    SDL_Rect spaceshipRect;


};

#endif // GAME_H
