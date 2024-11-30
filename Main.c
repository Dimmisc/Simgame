#include <SDL2/SDL.h>
#include <stdio.h>
#include "AreaBox.h"

unsigned int height=1080, width=1920, layots=8;

SDL_Window *Window = NULL;

SDL_Surface *Surface = NULL;

SDL_Surface *Image = NULL;

int main(int arc, char *argv[]){
    Areamap *map = Area(height, width, layots);


    printf("Hello, World!");

    return 0;
}
