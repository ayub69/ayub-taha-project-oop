#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "game.hpp"


/// 

int main() {
   

    SDL_Window *window = SDL_CreateWindow("Cosmic Escape", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    

    SDL_Surface *backgroundSurface = IMG_Load("backgroundscreen.jpeg");
   
    SDL_Texture *backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
    SDL_FreeSurface(backgroundSurface);

// buttons for levels 
    SDL_Rect noobbutton = {100, 220, 125, 50};
    SDL_Rect amaturebutton ={280, 220, 150, 50};
    SDL_Rect probutton = {500, 220, 125, 50};
    

// buttons for characters
    SDL_Rect spaceshipButton = {100, 370, 150, 50};
    SDL_Rect jetButton = {320, 370, 125, 50};
    SDL_Rect rocketButton = {520, 370, 150, 50};
    // Button "Play"

    SDL_Rect playButtonRect = {100, 500, 100, 50};


    // Button "Quit"s
    SDL_Rect quitButtonRect = {300, 500, 100, 50};
  
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
                            quit = true;
                            Game g;
                            g.runGame(selected_character,selected_level);
                            // call class game
                           // std::system("clang++ game.cpp -o game.out -lSDL2 -lSDL2_image && ./game.out");
                        }
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

    return 0;
}
