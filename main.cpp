#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include <iostream>
#include "game.hpp"
#include "object.hpp"

/// 

Mix_Music* bgMusic = nullptr;
Mix_Music* bgMusic2 = nullptr;

bool loadMedia() {
    bgMusic = Mix_LoadMUS("intromusic.wav");
    if (bgMusic == NULL) {
        printf("Unable to load music: %s\n", Mix_GetError());
        return false;
    }

    bgMusic2 = Mix_LoadMUS("intromusic2.wav");
    if (bgMusic2 == NULL) {
        printf("Unable to load second music: %s\n", Mix_GetError());
        return false;
    }

    return true;
}


int main() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }
    
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        return 1;
    }

    // Load media, including background music
        if (!loadMedia()) {
            printf("Failed to load media!\n");
            return 1;
        }
    Mix_PlayMusic(bgMusic, -1);  


   
    SDL_Window *window = SDL_CreateWindow("Cosmic Escape", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    

    SDL_Surface *backgroundSurface = IMG_Load("bg.png");
   
    SDL_Texture *backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
    SDL_FreeSurface(backgroundSurface);
    
// buttons for levels 
    SDL_Rect noobbutton = {84, 378, 96, 30};
    
    SDL_Rect amaturebutton ={220, 379, 159, 30};
    SDL_Rect probutton = {415, 379, 62, 25};
    
   
// buttons for characters
    SDL_Rect spaceshipButton = {232, 133, 82, 80};
    SDL_Rect jetButton = {349, 128, 90, 60};
    SDL_Rect rocketButton = {143, 130, 46, 87};
    // Button "Play"

    SDL_Rect playButtonRect = {77, 500, 120, 40};


    // Button "Quit"
    SDL_Rect quitButtonRect = {281, 496, 110, 40};
  
    char selected_character;
    int selected_level;

    bool quit = false;
    SDL_Event event;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_MOUSEBUTTONDOWN:
           
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        int mouseX = event.button.x;
                        int mouseY = event.button.y;
                        //noob button clicked;
                        if (mouseX >= noobbutton.x && mouseX <= noobbutton.x + noobbutton.w &&
                            mouseY >= noobbutton.y && mouseY <= noobbutton.y + noobbutton.h) {
                            selected_level=1;
                        }
                        //amature button clicked
                        if (mouseX >= amaturebutton.x && mouseX <= amaturebutton.x + amaturebutton.w &&
                            mouseY >= amaturebutton.y && mouseY <= amaturebutton.y + amaturebutton.h) {
                            selected_level=2;
                        }
                        //pro button clicked 
                        if (mouseX >= probutton.x && mouseX <= probutton.x + probutton.w &&
                            mouseY >= probutton.y && mouseY <= probutton.y + probutton.h) {
                            selected_level=4;
                        }
                        //ROCKET BUTTON CLICKED
                        if (mouseX >= rocketButton.x && mouseX <= rocketButton.x + rocketButton.w &&
                            mouseY >= rocketButton.y && mouseY <= rocketButton.y + rocketButton.h) {
                           selected_character='r';
                        }
                        //jet button clicked 
                        if (mouseX >= jetButton.x && mouseX <= jetButton.x + jetButton.w &&
                            mouseY >= jetButton.y && mouseY <= jetButton.y + jetButton.h) {
                            selected_character='j';
                            //std:: cout<< selected_character;
                        }
                        //spaceship button clicked
                        if (mouseX >= spaceshipButton.x && mouseX <= spaceshipButton.x + spaceshipButton.w &&
                            mouseY >= spaceshipButton.y && mouseY <= spaceshipButton.y + spaceshipButton.h) {
                            selected_character='s';
                        }
                        // Check if "Quit" button is clicked
                        if (mouseX >= quitButtonRect.x && mouseX <= quitButtonRect.x + quitButtonRect.w &&
                            mouseY >= quitButtonRect.y && mouseY <= quitButtonRect.y + quitButtonRect.h) {
                            quit = true;
                        }

                       // Check if "Play" button is clicked
                        if (mouseX >= playButtonRect.x && mouseX <= playButtonRect.x + playButtonRect.w &&
                            mouseY >= playButtonRect.y && mouseY <= playButtonRect.y + playButtonRect.h) {
                            // Stop the first music
                            Mix_HaltMusic();
                            SDL_Delay(100);

                            // Play second music
                            Mix_PlayMusic(bgMusic2, -1);  // -1 plays the music in an infinite loop

                            // // Destroy the window and exit the program
                            // SDL_DestroyWindow(window);
                            // quit = true;

                            if (selected_character and selected_level){
                            Game* g=new Game;
                            g->runGame(selected_character,selected_level);
                            SDL_DestroyWindow(window);
                            quit = true;
                            }
                            // call class game
                           // std::system("clang++ game.cpp -o game.out -lSDL2 -lSDL2_image && ./game.out");
                        }
                    }
                    break;
                    case SDL_WINDOWEVENT:
                    if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
                        quit = true;
                }
                    break;
            }
        }


        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    Mix_FreeMusic(bgMusic);
    Mix_FreeMusic(bgMusic2);

    return 0;
    // Mix_Quit();

}

