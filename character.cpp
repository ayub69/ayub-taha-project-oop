
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
// using these classes to draw the characters
class Character {
public:
    Character(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
    ~Character();
    void draw();
   
    void destroy(); //to destroy
    void handlekeypress(SDL_Rect& characterrect, const SDL_Event& event);
    SDL_Rect objectRect;
private:
    SDL_Texture* objectTexture;
    //SDL_Rect objectRect;
    SDL_Renderer* objectRenderer;
};

Character::Character(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height) {
    objectRenderer = renderer;

    SDL_Surface* objectSurface = IMG_Load(imagePath);
    objectTexture = SDL_CreateTextureFromSurface(objectRenderer, objectSurface);
    SDL_FreeSurface(objectSurface);

    objectRect.x = x;
    objectRect.y = y;
    objectRect.w = width;
    objectRect.h = height; 
}

Character::~Character() {
    SDL_DestroyTexture(objectTexture);
}

void Character:: destroy(){
    // Check if the object is below the screen
{
        // If the object is below the screen, delete it
        delete this;
    }
}

void Character::draw() {
    SDL_RenderCopy(objectRenderer, objectTexture, NULL, &objectRect);
    
}
class Spaceship : public Character {
public:
    Spaceship(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

Spaceship::Spaceship(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height)
    : Character(renderer, imagePath, x, y, width, height) {
   }

class Rocket : public Character {
public:
    Rocket(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

Rocket::Rocket(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height)
    : Character(renderer, imagePath, x, y, width, height) {
   }

class Jet : public Character {
public:
    Jet(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

Jet::Jet(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height)
    : Character(renderer, imagePath, x, y, width, height) {
   }