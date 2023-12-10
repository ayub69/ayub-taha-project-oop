
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
// classes created here for objects that will be drawn on screen using polymorphism and inheritance
class GameObject {
public:
    GameObject(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
    ~GameObject();
    void draw();
    void update(int selected_level); //  method for updating position of alien and asteroid according to level
    void updatep(); //to update planet and powerups
    void updatel();// to update lighnting
    void destroy(); //to destroy
  
    SDL_Rect objectRect;
private:
    SDL_Texture* objectTexture;
    //SDL_Rect objectRect;
    SDL_Renderer* objectRenderer;
};

GameObject::GameObject(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height) {
    objectRenderer = renderer;

    SDL_Surface* objectSurface = IMG_Load(imagePath);
    objectTexture = SDL_CreateTextureFromSurface(objectRenderer, objectSurface);
    SDL_FreeSurface(objectSurface);

    objectRect.x = x;
    objectRect.y = y;
    objectRect.w = width;
    objectRect.h = height; 
}

GameObject::~GameObject() {
    SDL_DestroyTexture(objectTexture);
}

void GameObject:: destroy(){
    // Check if the object is below the screen
{
        // If the object is below the screen, delete it
        delete this;
    }
}
void GameObject::update(int selected_level) {
    // Update the object's position (e.g., move it downwards)
    objectRect.y += selected_level; // Adjust the value according to your needs
}
void GameObject :: updatep(){
    objectRect.y+=1;
}
void GameObject :: updatel(){
    objectRect.x-=15;
}
void GameObject::draw() {
    SDL_RenderCopy(objectRenderer, objectTexture, NULL, &objectRect);
    
}
class Alien : public GameObject {
public:
    Alien(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

Alien::Alien(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height)
    : GameObject(renderer, imagePath, x, y, width, height) {
   }

class Alien2 : public GameObject {
public:
    Alien2(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

Alien2::Alien2(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height)
    : GameObject(renderer, imagePath, x, y, width, height) {
   }

class Asteroid1 : public GameObject {
public:
    Asteroid1(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

Asteroid1::Asteroid1(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height)
    : GameObject(renderer, imagePath, x, y, width, height) {
   }

class Asteroid2 : public GameObject {
public:
    Asteroid2(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

Asteroid2::Asteroid2(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height)
    : GameObject(renderer, imagePath, x, y, width, height) {
   }

class Planet : public GameObject {
public:
    Planet(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

Planet::Planet(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height)
    : GameObject(renderer, imagePath, x, y, width, height) {
    }
//-------------------------------------------------------------------
class Planet2 : public GameObject {
public:
    Planet2(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

Planet2::Planet2(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height)
    : GameObject(renderer, imagePath, x, y, width, height) {
    // Additional initialization specific to Planet if needed
}
class Planet3 : public GameObject {
public:
    Planet3(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

Planet3::Planet3(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height)
    : GameObject(renderer, imagePath, x, y, width, height) {
    // Additional initialization specific to Planet if needed
}
class Planet4 : public GameObject {
public:
    Planet4(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

Planet4::Planet4(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height)
    : GameObject(renderer, imagePath, x, y, width, height) {
    // Additional initialization specific to Planet if needed
}
class Planet5 : public GameObject {
public:
    Planet5(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

Planet5::Planet5(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height)
    : GameObject(renderer, imagePath, x, y, width, height) {
    // Additional initialization specific to Planet if needed
}
class Sun: public GameObject {
public:
    Sun(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};
Sun::Sun(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height)
    : GameObject(renderer, imagePath, x, y, width, height) {
    // Additional initialization specific to Planet if needed
}

class won : public GameObject {
public:
    won(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

won::won(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height)
    : GameObject(renderer, imagePath, x, y, width, height) {
   }

class Powerup1 : public GameObject {
public:
    Powerup1(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);

};
Powerup1::Powerup1(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height)
    : GameObject(renderer, imagePath, x, y, width, height) {
}

class Powerup2 : public GameObject {
public:
    Powerup2(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

Powerup2::Powerup2(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height)
    : GameObject(renderer, imagePath, x, y, width, height) {
}
class Powerup3 : public GameObject {
public:
    Powerup3(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

Powerup3::Powerup3(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height)
    : GameObject(renderer, imagePath, x, y, width, height) {
}

class Powerup4 : public GameObject {
public:
    Powerup4(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

Powerup4::Powerup4(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height)
    : GameObject(renderer, imagePath, x, y, width, height) {
}
//-------
class lost : public GameObject {
public:
    lost(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

lost::lost(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height)
    : GameObject(renderer, imagePath, x, y, width, height) {
}
//------------------------------
class noobimage : public GameObject {
public:
    noobimage(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

noobimage::noobimage(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height)
    : GameObject(renderer, imagePath, x, y, width, height) {
}

class amateurimage : public GameObject {
public:
    amateurimage(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

amateurimage::amateurimage(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height)
    : GameObject(renderer, imagePath, x, y, width, height) {
}
class proimage : public GameObject {
public:
    proimage(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height);
};

proimage::proimage(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height)
    : GameObject(renderer, imagePath, x, y, width, height) {
}



