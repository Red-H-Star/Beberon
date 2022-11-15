#include <SDL.h>
#include <stdio.h>

//screen dimensions costants
const int SCREEN_WIDTH = 310;
const int SCREEN_HEIGHT = 552;

//Declarations
SDL_Window* window = NULL;
SDL_Surface* surface = NULL;
SDL_Renderer* renderer = NULL;

//function to free the memory and close the sdl application
void close() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer = NULL;
    window = NULL;
    SDL_Quit();
}

int main(int argc, char* args[]) {

    //Window and renderer init
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
        //Create window
        window = SDL_CreateWindow("Beberon", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        }
        //Create renderer
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }

    //setup for event handling
    bool quit = false;
    SDL_Event event;

    // [Create Home content]

    //Define areas 
    SDL_Rect title_rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 5 };
    SDL_Rect window_rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

    //Background
    SDL_SetRenderDrawColor(renderer, 188, 203, 222, 255);
    SDL_RenderClear(renderer);

    //Title and buttons

    SDL_RenderSetViewport(renderer, &title_rect);
    SDL_SetRenderDrawColor(renderer, 194, 221, 230, 255);
    SDL_RenderFillRect(renderer, &title_rect);


    //Separation Line
    SDL_RenderSetViewport(renderer, &window_rect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT / 5, SCREEN_WIDTH, SCREEN_HEIGHT / 5);
    SDL_RenderPresent(renderer);
    SDL_Delay(0);

    //main loop which first handles events
    while (!quit) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT)
                quit = true;
        }
    }

    //End the application
    close();
    return 0;
}