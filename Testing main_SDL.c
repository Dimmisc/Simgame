#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Event event;
unsigned int quit = 1;

typedef struct SDLWindow{
    SDL_Window* window;
    SDL_Surface* ScreenSurface;
} SDLWindow;

int main(int argc, char *argv[]){

    SDLWindow Window1 = {NULL, NULL};

    while (quit == 1){

        while (SDL_PollEvent(&event) != 0){

            if (event.type == SDL_QUIT){
                quit = 0;
            }
            if (event.type == SDL_SCANCODE_W){
                printf("You are pressing W");
            }
        }
    }

    SDL_DestroyWindow(Window1.window);
    SDL_Quit();
    printf("helloWorld");
    return 0;
}
