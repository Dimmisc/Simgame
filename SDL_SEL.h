#ifndef _SDL_SEL_H_
#define _SDL_SEL_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct SEL_ConsoleWindow{
    SDL_Window *Window;
    SDL_Surface *Surface;
    SDL_Renderer *Render;
    SDL_Texture *Texture;
    char Error[30];
    int SIZETEXTURE;
    int LENTEXTURES;
    int SIZESURFACE;
    int LENSURFACES;
}SEL_ConsoleWindow;

SEL_ConsoleWindow *SEL_initMainW(ConsoleWindow *ARG){
    int width = 100, height = 100, x = 0, y = 0;
    ARG->Window = SDL_CreateWindow("Simagame", x, y, width, height, SDL_WINDOW_SHOWN);
    return ARG;
}

int SEL_CloseCW(ConsoleWindow *ARG){

    SDL_DestroyWindow( ARG->Window );
    return 0;
}

extern SEL_ConsoleWindow *SEL_initMainW();
extern int SEL_CloseCW();

#endif
