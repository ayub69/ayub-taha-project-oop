#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "object.hpp"
#include <vector>
#include "collision.hpp"

//#include "character.hpp"
// character 
// character 


// game.cpp



class Game {
public:
    Game();
    ~Game();
    void runGame(char selected_character , int selected_level);
    
   // SDL_Surface* charactersurface=IMG_Load("jet.png");
    SDL_Surface* charactersurface = IMG_Load("spaceship.png");
private:
   
    SDL_Renderer* renderer;
    SDL_Texture* backgroundTexture;
    SDL_Texture* charactertexture;
    SDL_Rect characterrect;

    static void handleKeyPress1(SDL_Rect& characterrect, const SDL_Event& event);
    
};
SDL_Window* window;

Game::Game() {
    window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_Surface* backgroundSurface = IMG_Load("blackspace.jpeg");
    backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
    SDL_FreeSurface(backgroundSurface);
    charactertexture = SDL_CreateTextureFromSurface(renderer, charactersurface);
    SDL_FreeSurface(charactersurface);

    characterrect.x = 375;
    characterrect.y = 500;
    characterrect.w = 50;
    characterrect.h = 50; // Adjust the position and size based on your coordinates

}

Game::~Game() {
    SDL_DestroyTexture(backgroundTexture);
   SDL_DestroyTexture(charactertexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::runGame(char selected_character, int selected_level) {

    const char character_img[14]="spaceship.png";

    bool pause=false;
    bool quit = false;
    SDL_Event event;
    Alien *alien = new Alien(renderer, "alien.png", rand()%800, 0, 75, 75); 
   //vector<GameObject> object_list;
    Asteroid1 *asteroid = new Asteroid1(renderer, "meteor1.png", rand()%800, 0, 75, 75); 
    Asteroid2 *asteroid2 = new Asteroid2(renderer, "meteor2.png", rand()%800, 0, 75, 75); 
    Alien2 *alien2 = new Alien2(renderer, "alien2.png", rand()%800, 0, 75, 75); 
    Planet planet(renderer, "planet1.png", 300, 0, 200, 200);
    Planet2 planet2(renderer, "planet2.png", 500, 0, 300, 300);
    Planet3 planet3(renderer, "planet3.png", 300, -100, 300, 300);
    Planet4 planet4(renderer, "planet4.png", 500, 0, 300, 300);
    Planet5 planet5(renderer, "planet5.png", 300, -100, 300, 300);
    Sun sun(renderer, "sun.png", -200, -200, 500, 500);
    //Spaceship *character= new Spaceship(renderer, "spaceship.png", 375, 500, 50, 50);
    won won1(renderer, "won.png",200,200,300,300);
    Spaceship spaceship(renderer, character_img, 375, 500, 50, 50);
    Jet jet (renderer, "jet.png", 375, 500, 50, 50);
   Rocket rocket (renderer, "rocket.png", 375, 500, 50, 50);
   Powerup1 powerup1(renderer,  "powerup 1.png", 150, 0, 200, 200);
    Powerup2 *lightning=new Powerup2(renderer,  "lightning.png", 800, 200, 250, 250);
   Powerup3 bolt(renderer,  "bolt.png", rand()%800, -100, 100, 100);
    bool alien11, alien22, planet1, asteroid11, asteroid22,bolt1,lightning1;
    alien11 = false;
    alien22 = false;
    planet1 = false;
    asteroid11 = false;
    asteroid22 = false;
    bolt1=true;
    lightning1=false;
    
    static int framecount=60;
    int frames=0;
    int lightcount=0;
    while (!quit) {
        //character.draw();
        frames+=selected_level;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
            }
             if (selected_character=='j'){
        handleKeyPress1(jet.objectRect, event); 
    } else if (selected_character=='r'){
        handleKeyPress1(rocket.objectRect, event); 
    } else if (selected_character=='s'){
       handleKeyPress1(spaceship.objectRect, event); 
    }
            // Handle key presses
        }

        SDL_RenderClear(renderer);

        // Update background position (vertical wrap-around effect)
        static int backgroundOffsetY = 0;
        backgroundOffsetY = (backgroundOffsetY + 1) % 600; // Adjust based on your background size

        // Draw background
        SDL_Rect backgroundRect1 = {0, backgroundOffsetY - 600, 800, 600};
        SDL_Rect backgroundRect2 = {0, backgroundOffsetY, 800, 600};
        SDL_RenderCopy(renderer, backgroundTexture, NULL, &backgroundRect1);
        SDL_RenderCopy(renderer, backgroundTexture, NULL, &backgroundRect2);
        planet.draw();
        planet.updatep();
       sun.draw();
       
         if (selected_character=='j'){
        jet.draw();
        
    } else if (selected_character=='r'){
        rocket.draw();
    } else if (selected_character=='s'){
        spaceship.draw();
    }
       if (pause==false){
        // Draw scaled-down character
        if (frames%framecount==0){
            //std::cout<< frames<<std::endl;
            int object= rand()%4;
                //std::cout<<object<<std::endl;
            if (object==0){
                //objects_list.push_back(new Alien(renderer, "alien.png", rand()%600, rand()%400, 75, 75));
                 //Alien *alien=new Alien(renderer, "alien.png", rand()%600, rand()%400, 75, 75); 
                alien11 = true;
               // alien->draw();
                //alien->update();
            } if (object==1){
                alien22 = true;
                // alien2.draw();
                // alien2.update();
            } if (object==2){
                asteroid22 = true;
                // asteroid2.draw();
                // asteroid2.update();

            }if (object==3){
                asteroid11=true;
               // asteroid.draw();
              //  asteroid.update();
            }
        }
        
        if (lightning1 and lightcount<=2){
            lightning->draw();
                lightning->updatel();
                    if (Collision::checkCollision(lightning->objectRect, alien->objectRect)) {
                        alien11=false;
                    }
                     if (Collision::checkCollision(lightning->objectRect, alien2->objectRect)) {
                        alien22=false;;
                    }
                    if (Collision::checkCollision(lightning->objectRect, asteroid->objectRect)) {
                       asteroid11=false;
                    }
                    if (Collision::checkCollision(lightning->objectRect, asteroid2->objectRect)) {
                        asteroid22=false;
                    }
        }
        
       

        if(planet.objectRect.y>=600){
                //std::cout<<"works";
               
                //planet.destroy();
                planet2.draw();
                planet2.updatep();
            }
        if (planet2.objectRect.y>=600){
            planet3.draw();
            planet3.updatep();
                if (bolt1){
                bolt.draw();
                bolt.updatep();
                }
        }

        if (planet3.objectRect.y>=600){
            //std::cout<<"planet4";
            planet4.draw();
            
                planet4.updatep();
        }
        if (planet4.objectRect.y>=600){
           // std::cout<<"planet5";
            planet5.draw();
                planet5.updatep();
        }if (planet5.objectRect.y>=500){
           // std::cout<<"planet5";
            won1.draw();
            pause=true;

        }
        if (alien11){
            alien->draw();
            alien->update(selected_level);
            if(alien->objectRect.y>=600){
                //std::cout<<"works";
                alien11=false;
                alien->destroy();
                alien = new Alien (renderer, "alien.png", rand()%800, 0, 75, 75);
            }

        }
        if(alien22){
            alien2->draw();
            alien2->update(selected_level);
            if(alien2->objectRect.y>=600){
                //std::cout<<"works";
                alien22=false;
                alien2->destroy();
                alien2 = new Alien2 (renderer, "alien2.png", rand()%800, 0, 75, 75);
            }
        }
        if (asteroid11){
            asteroid->draw();
            asteroid->update(selected_level);
            if (asteroid -> objectRect.y>=600){
                asteroid11=false;
                asteroid->destroy();
                asteroid = new Asteroid1(renderer, "meteor1.png", rand()%800, 0, 75, 75);
            }
        }
        if(asteroid22){
      
            asteroid2->draw();
            asteroid2->update(selected_level);
            if (asteroid2 -> objectRect.y>=600){
                asteroid22=false;
                asteroid2->destroy();
                asteroid2= new Asteroid2(renderer, "meteor2.png", rand()%800, 0, 75, 75);
        }
        }
        // for (auto & e: object_list)
        // {
        //     e.draw();
        //     e.update();
        // }
        
       }
       if (planet5.objectRect.y>=600){
           // std::cout<<"planet5";
            won1.draw();
            

        }
      // SDL_RenderCopy(renderer, charactertexture, NULL, &characterrect);
          if (selected_character=='j'){
            if (Collision::checkCollision(jet.objectRect, alien->objectRect)) {
                pause=true;
            }
            if (Collision::checkCollision(jet.objectRect, alien2->objectRect)) {
                pause=true;
            }
            if (Collision::checkCollision(jet.objectRect, asteroid->objectRect)) {
                pause=true;
            }
            if (Collision::checkCollision(jet.objectRect, asteroid2->objectRect)) {
                pause=true;
            }
            if (Collision::checkCollision(jet.objectRect, bolt.objectRect)) {
                bolt1=false;
                lightning1=true;
                
            }
        
    } else if (selected_character=='r'){
        if (Collision::checkCollision(rocket.objectRect, alien->objectRect)) {
                pause=true;
            }
            if (Collision::checkCollision(rocket.objectRect, alien2->objectRect)) {
                pause=true;
            }
            if (Collision::checkCollision(rocket.objectRect, asteroid->objectRect)) {
                pause=true;
            }
            if (Collision::checkCollision(rocket.objectRect, asteroid2->objectRect)) {
                pause=true;
            }
            if (Collision::checkCollision(rocket.objectRect, bolt.objectRect)) {
                bolt1=false;
                lightning1=true;
                
            }
    } else if (selected_character=='s'){
        if (Collision::checkCollision(spaceship.objectRect, alien->objectRect)) {
                pause=true;
            }
            if (Collision::checkCollision(spaceship.objectRect, alien2->objectRect)) {
                    pause=true;
            }
            if (Collision::checkCollision(spaceship.objectRect, asteroid->objectRect)) {
                pause=true;
            }
            if (Collision::checkCollision(spaceship.objectRect, asteroid2->objectRect)) {
                pause=true;
            }
            if (Collision::checkCollision(spaceship.objectRect, bolt.objectRect)) {
                bolt1=false;
                lightning1=true;
                
            }
    }
       SDL_RenderPresent(renderer);
    
    }
    }
void Game::handleKeyPress1(SDL_Rect& characterrect, const SDL_Event& event) {
    const Uint8* currentKeyStates = SDL_GetKeyboardState(nullptr);
    int movementSpeed = 5;
    int screenWidth = 800;
    int screenHeight = 600;

    if (currentKeyStates[SDL_SCANCODE_LEFT]) {
        characterrect.x -= 10;
        if (characterrect.x < 0) {
            characterrect.x = 0; // Keep character within the left edge of the screen
        }
    }

    if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
        characterrect.x += 10;
        if (characterrect.x + characterrect.w > screenWidth) {
            characterrect.x = screenWidth - characterrect.w; // Keep character within the right edge of the screen
        }
    }

    if (currentKeyStates[SDL_SCANCODE_UP]) {
        characterrect.y -= 3;
        if (characterrect.y +characterrect.h < 0) {
            characterrect.y = 0; // Keep character within the top edge of the screen
        }
    }

    if (currentKeyStates[SDL_SCANCODE_DOWN]) {
        characterrect.y += 3;
        if (characterrect.y + characterrect.h > screenHeight) {
            characterrect.y = screenHeight - characterrect.h; // Keep character within the bottom edge of the screen
        }
    }
}



