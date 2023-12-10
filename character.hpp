#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Character {
public:
    Character(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
    ~Character();
    void draw();
    
    void destroy();
    void handlekeypress(SDL_Rect& characterrect, const SDL_Event& event);
    SDL_Rect objectRect;

private:
    SDL_Texture* objectTexture;
    SDL_Renderer* objectRenderer;
};
class Spaceship : public Character {
public:
    Spaceship(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

class Rocket : public Character {
public:
    Rocket(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

class Jet : public Character {
public:
    Jet(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};
#endif 