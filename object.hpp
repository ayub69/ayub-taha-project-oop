#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class GameObject {
public:
    GameObject(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
    ~GameObject();
    void draw();
    void update(int selected_level);
    void update();
    void updatel();
    void destroy();
 
    SDL_Rect objectRect;

private:
    SDL_Texture* objectTexture;
    SDL_Renderer* objectRenderer;
};

class Alien : public GameObject {
public:
    Alien(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

class Alien2 : public GameObject {
public:
    Alien2(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

class Asteroid1 : public GameObject {
public:
    Asteroid1(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

class Asteroid2 : public GameObject {
public:
    Asteroid2(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

class Planet : public GameObject {
public:
    Planet(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

class Planet2 : public GameObject {
public:
    Planet2(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

class Planet3 : public GameObject {
public:
    Planet3(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

class Planet4 : public GameObject {
public:
    Planet4(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

class Planet5 : public GameObject {
public:
    Planet5(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

class Sun : public GameObject {
public:
    Sun(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};



class won : public GameObject {
public:
    won(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

class Powerup1 : public GameObject {
public:
    Powerup1(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

class Powerup2 : public GameObject {
public:
    Powerup2(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

class Powerup3 : public GameObject {
public:
    Powerup3(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};
class Powerup4 : public GameObject {
public:
    Powerup4(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

class lost : public GameObject {
public:
    lost(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

class noobimage : public GameObject {
public:
    noobimage(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

class amateurimage : public GameObject {
public:
    amateurimage(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

class proimage : public GameObject {
public:
    proimage(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

#endif // GAMEOBJECT_HPP
