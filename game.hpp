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
    void playSoundEffect(const char *soundFilePath);
    void playSoundEffectwin(const char *soundFilePath);
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* backgroundTexture;
   // SDL_Texture* charactertexture;
    SDL_Rect spaceshipRect;
    static void handleKeyPress1(SDL_Rect& characterrect, const SDL_Event& event,char selected_character, int selected_level);
    void playSoundEffect(const char *soundFilePath);
    void playSoundEffectwin(const char *soundFilePath);


};

#endif // GAME_H
