#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <math.h>

//screen dimensions constants
const int SCREEN_WIDTH = 310;
const int SCREEN_HEIGHT = 552;

//Declarations
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* text_texture = NULL;
TTF_Font* text_font = NULL;
SDL_Color text_color = { 0, 0, 0, 255 }; /*No allocation freeing for color elements ?*/
const char* current_page = NULL;
int homebW = SCREEN_WIDTH * 0.7;
int homebH = SCREEN_HEIGHT * 0.1;

// ----------- Home -----------

//Define Text Positions
SDL_Rect title_pos = { SCREEN_WIDTH * 0.1 , 0, SCREEN_WIDTH * 0.8, SCREEN_HEIGHT * 0.18 };
SDL_Rect registering_pos = { SCREEN_WIDTH * 0.15, SCREEN_HEIGHT * 0.05, homebW, homebH };
SDL_Rect alarm_pos = { SCREEN_WIDTH * 0.15, SCREEN_HEIGHT * 0.25, homebW, homebH };
SDL_Rect shopping_pos = { SCREEN_WIDTH * 0.15, SCREEN_HEIGHT * 0.45, homebW, homebH };
SDL_Rect exit_pos = { SCREEN_WIDTH * 0.15, SCREEN_HEIGHT * 0.65, homebW, homebH };

//Define areas 
SDL_Rect window_zone = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
SDL_Rect button_zone = { 0, SCREEN_HEIGHT * 0.2, SCREEN_WIDTH, SCREEN_HEIGHT * 0.8 };
SDL_Rect title_zone = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT * 0.2 };

// ----------- Feeding -----------

//Define Text Positions
SDL_Rect add_pos = { SCREEN_WIDTH * 0.65, SCREEN_HEIGHT * 0.2, SCREEN_WIDTH * 0.30, SCREEN_HEIGHT * 0.08 };
SDL_Rect addEX_pos = { SCREEN_WIDTH * 0.03, SCREEN_HEIGHT * 0.215, SCREEN_WIDTH * 0.55, SCREEN_HEIGHT * 0.05 };

//Define areas 
SDL_Rect feeder_zone = { 0, SCREEN_HEIGHT * 0.28, SCREEN_WIDTH, SCREEN_HEIGHT * 0.9};

/* === Possible upgrade : making a rect array to use "RenderFillRects" instead of repeating command === */
SDL_Rect feeding_rect = { SCREEN_WIDTH * 0.1, SCREEN_HEIGHT * 0.03, SCREEN_WIDTH * 0.8, SCREEN_HEIGHT * 0.15 };
SDL_Rect reminder_rect = { SCREEN_WIDTH * 0.1, SCREEN_HEIGHT * 0.23, SCREEN_WIDTH * 0.8, SCREEN_HEIGHT * 0.15 };
SDL_Rect shopping_rect = { SCREEN_WIDTH * 0.1, SCREEN_HEIGHT * 0.43, SCREEN_WIDTH * 0.8, SCREEN_HEIGHT * 0.15 };
SDL_Rect exit_rect = { SCREEN_WIDTH * 0.12, SCREEN_HEIGHT * 0.63, SCREEN_WIDTH * 0.76, SCREEN_HEIGHT * 0.15 };

//function to free the memory and close the sdl application
void close() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(text_texture);
    TTF_CloseFont(text_font);
    renderer = NULL;
    window = NULL;
    TTF_Quit();
    SDL_Quit();
    printf("Cleared ressources : Closing application\n");
}

//==================================== MAKE SURE CLOSE FUNCTION WORKS PROPERLY ===============================

void RenderText(SDL_Renderer* renderer, const SDL_Rect rect, const char* content) {

    if (!text_font) {
        if (!TTF_OpenFont("../arial.ttf", 99)) {
            printf("TTF_OpenFont: %s\n", TTF_GetError());
        }
        else {
            text_font = TTF_OpenFont("../arial.ttf", 99);
            printf("Created Font Ressouce\n");
        }
    }

    SDL_Rect currentRect = rect;
    SDL_Surface* text_surface = TTF_RenderText_Blended(text_font, content, text_color);
    SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);

    if (!TTF_RenderText_Solid(text_font, content, text_color)) {
        printf("SDL failed to create surface. SDL_Error: %s\n", SDL_GetError());
    }
    if (!SDL_CreateTextureFromSurface(renderer, text_surface)) {
        printf("SDL failed to create texture. SDL_Error: %s\n", SDL_GetError());
    }
    if (SDL_RenderCopy(renderer, text_texture, NULL, &currentRect) < 0) {
        printf("SDL failed to render copy. SDL_Error: %s\n", SDL_GetError());
    }

    SDL_FreeSurface(text_surface);
}

void loadImage(const SDL_Rect rect, const char path[], SDL_Renderer* renderer)
{
    SDL_Surface* image_surface = NULL;
    SDL_Texture* image_texture = NULL;
    image_surface = SDL_LoadBMP(path);
    if (!image_surface)
    {
        printf("Erreur SDL_LoadBMP : %s", SDL_GetError());
    }
    image_texture = SDL_CreateTextureFromSurface(renderer, image_surface);
    SDL_FreeSurface(image_surface);
    if (!image_texture)
    {
        printf("Erreur SDL_CreateTextureFromSurface : %s", SDL_GetError());
    }

    SDL_SetRenderTarget(renderer, image_texture);
    SDL_RenderCopy(renderer, image_texture, NULL, &rect);
    SDL_SetRenderTarget(renderer, NULL);
}


void RenderHome(SDL_Renderer* renderer) {

    current_page = "home";
    SDL_RenderSetViewport(renderer, &window_zone);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    // Build Page Below

    //Background
    SDL_SetRenderDrawColor(renderer, 188, 203, 222, 255);
    SDL_RenderClear(renderer);

    //Title

    SDL_RenderSetViewport(renderer, &title_zone);
    SDL_SetRenderDrawColor(renderer, 194, 221, 230, 255);
    SDL_RenderFillRect(renderer, &title_zone);

    //Title Text

    RenderText(renderer, title_pos, "BEBERON");

    //Buttons
    SDL_RenderSetViewport(renderer, &button_zone);
    SDL_SetRenderDrawColor(renderer, 230, 233, 240, 255);
    SDL_RenderFillRect(renderer, &feeding_rect);
    SDL_RenderFillRect(renderer, &reminder_rect);
    SDL_RenderFillRect(renderer, &shopping_rect);
    SDL_RenderFillRect(renderer, &exit_rect);

    //Add Buttons Text

    RenderText(renderer, registering_pos, "Feeding Manager");
    RenderText(renderer, alarm_pos, "Reminder Manager");
    RenderText(renderer, shopping_pos, "Shopping List");
    RenderText(renderer, exit_pos, "Quit Application");

    //Separation Line
    SDL_RenderSetViewport(renderer, &window_zone);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT * 0.2, SCREEN_WIDTH, SCREEN_HEIGHT * 0.2);

    //Render elements
    SDL_RenderPresent(renderer);
    SDL_Delay(0);
}

void RenderFeeding(SDL_Renderer * renderer) {

    current_page = "feeding";
    SDL_RenderSetViewport(renderer, &window_zone);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Build Page Below

    //Background
    SDL_SetRenderDrawColor(renderer, 188, 203, 222, 255);
    SDL_RenderClear(renderer);

    //Title

    SDL_RenderSetViewport(renderer, &title_zone);
    SDL_SetRenderDrawColor(renderer, 194, 221, 230, 255);
    SDL_RenderFillRect(renderer, &title_zone);

    //Separation Line
    SDL_RenderSetViewport(renderer, &window_zone);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT * 0.2, SCREEN_WIDTH, SCREEN_HEIGHT * 0.2);

    //Title Text

    RenderText(renderer, title_pos, "Feeding Manager");

    //Button Add Visual + Text

    SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT * 0.28, SCREEN_WIDTH, SCREEN_HEIGHT * 0.28);
    SDL_RenderDrawLine(renderer, SCREEN_WIDTH * 0.60, SCREEN_HEIGHT * 0.28, SCREEN_WIDTH * 0.60, SCREEN_HEIGHT * 0.2);
    RenderText(renderer, add_pos, "ADD");
    RenderText(renderer, addEX_pos, "Register a new bottle >");

    //Feeding bottle object template

    SDL_RenderSetViewport(renderer, &feeder_zone);
    SDL_SetRenderDrawColor(renderer, 230, 233, 240, 255);

    int feeder_id = 0;

    int object_start_y = 0; /* + previous rect y value (= 0 for first rect) */
    int object_end_y = SCREEN_HEIGHT * 0.10;

    SDL_Rect FeedObjectRect = { 0, object_start_y, SCREEN_WIDTH, object_end_y};
    SDL_RenderFillRect(renderer, &FeedObjectRect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 0, 0, SCREEN_WIDTH, 0);
    SDL_RenderDrawLine(renderer, 0, object_end_y, SCREEN_WIDTH, object_end_y);
    SDL_RenderDrawLine(renderer, SCREEN_WIDTH * 0.85, object_start_y, SCREEN_WIDTH * 0.85, object_end_y);
    SDL_RenderDrawLine(renderer, SCREEN_WIDTH * 0.68, object_start_y, SCREEN_WIDTH * 0.68, object_end_y);
    SDL_Rect name_pos = { SCREEN_WIDTH * 0.02, object_start_y + SCREEN_HEIGHT * 0.013, SCREEN_WIDTH * 0.5, object_end_y - SCREEN_HEIGHT * 0.02 };
    SDL_Rect bin_pos = { SCREEN_WIDTH * 0.85, object_start_y + SCREEN_HEIGHT * 0.013, SCREEN_WIDTH * 0.16, object_end_y - SCREEN_HEIGHT * 0.02 };
    SDL_Rect mod_pos = { SCREEN_WIDTH * 0.70, object_start_y + SCREEN_HEIGHT * 0.013, SCREEN_WIDTH * 0.14, object_end_y - SCREEN_HEIGHT * 0.02 };

    // [FIND A WAY TO AUTO RENDER feeder_id INTO RenderText ("....%d", feeder_id)]
    RenderText(renderer, name_pos, "Feeder Bottle #1");
    loadImage(bin_pos, "../Pictures/trash bin.bmp", renderer);
    loadImage(mod_pos, "../Pictures/modify.bmp", renderer);

    //Render elements
    SDL_RenderPresent(renderer);
    SDL_Delay(0);
}

int main(int argc, char* args[]) {

    //Window, renderer & TTF init
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
        //Initialize TTF extension
        TTF_Init();
    }

    RenderFeeding(renderer);

    //setup for event handling
    bool quit = false;
    SDL_Event event;

    // [Create Feeding content]

    //main loop which first handles events
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0) {
            //Button Event Manager

            if (event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEBUTTONDOWN) {
                printf("x = %d\n", event.button.x);
                printf("y = %d\n", event.button.y);
            }


            //============= HOME ===================

            /*Feeding Manager (no effect yet)*/
            if (current_page == "home" && event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEBUTTONDOWN && event.button.x >= static_cast<int>(SCREEN_WIDTH * 0.1) && event.button.x <= static_cast<int>(SCREEN_WIDTH * 0.9) && event.button.y >= static_cast<int>(SCREEN_HEIGHT * 0.229) && event.button.y <= static_cast<int>(SCREEN_HEIGHT * 0.375)) {
                printf("Feeding Button Clicked\n");
                RenderFeeding(renderer);
            }

            /*Reminder Manager (no effect yet)*/
            if (current_page == "home" && event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEBUTTONDOWN && event.button.x >= static_cast<int>(SCREEN_WIDTH * 0.1) && event.button.x <= static_cast<int>(SCREEN_WIDTH * 0.9) && event.button.y >= static_cast<int>(SCREEN_HEIGHT * 0.428) && event.button.y <= static_cast<int>(SCREEN_HEIGHT * 0.557)) {
                printf("Reminder Button Clicked\n");
            }

            /*Shopping list (no effect yet)*/
            if (current_page == "home" && event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEBUTTONDOWN && event.button.x >= static_cast<int>(SCREEN_WIDTH * 0.1) && event.button.x <= static_cast<int>(SCREEN_WIDTH * 0.9) && event.button.y >= static_cast<int>(SCREEN_HEIGHT * 0.629) && event.button.y <= static_cast<int>(SCREEN_HEIGHT * 0.774)) {
                printf("Shopping Button Clicked\n");
            }

            /*Exit*/
            if (current_page == "home" && event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEBUTTONDOWN && event.button.x >= static_cast<int>(SCREEN_WIDTH * 0.12) && event.button.x <= static_cast<int>(SCREEN_WIDTH * 0.88) && event.button.y >= static_cast<int>(SCREEN_HEIGHT * 0.83) && event.button.y <= static_cast<int>(SCREEN_HEIGHT * 0.98)) {
                printf("Exit Button Clicked\n");
                quit = true;
            }


            //============= FEEDING ===================
            if (current_page == "feeding" && event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEBUTTONDOWN && event.button.x >= static_cast<int>(SCREEN_WIDTH * 0.604) && event.button.x <= static_cast<int>(SCREEN_WIDTH) && event.button.y >= static_cast<int>(SCREEN_HEIGHT * 0.2) && event.button.y <= static_cast<int>(SCREEN_HEIGHT * 0.278)) {
                printf("Add Button Clicked\n");
            }

            //Quit Event Manager
            if (event.type == SDL_QUIT) {
                quit = true;
                close();
            }
        }
    }

    //End the application
    return 0;
}