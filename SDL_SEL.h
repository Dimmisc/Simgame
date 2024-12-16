#ifndef _SDL_SEL_H_
#define _SDL_SEL_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "AreaBox.h"


typedef struct SGL_ConsoleWindow{
    SDL_Window *window;
    SDL_Surface *surface;
    SDL_Renderer *render;
    sprite **shownSprites;
    char Error[30];
    int lsS;
} SEL_ConsoleWindow;

typedef struct WindowSettings{
    char name[];
    int width;
    int height;
    int x;
    int y;
} WindowSettings;

int SEL_init(SEL_ConsoleWindow *ARG, WindowSettings *settings){
    int succes = 0;
    ARG->window = SDL_CreateWindow(settings.name,
                                   settings.x,
                                   settings.y,
                                   settings.width,
                                   settings.height,
                                   SDL_WINDOW_SHOWN
                                   );
    if (ARG->window == NULL){
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
    }
    else {
        ARG->render = SDL_CreateRenderer(ARG->window, -1, SDL_RENDERER_ACCELERATED);
        if (ARG->render == NULL){
            printf( "Render could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else {
            succes = 1;
        }
    }
    return succes;
}

int SEL_UpdateScreen(SEL_ConsoleWindow *ARG){
    int succes = 1;
    SDL_RenderClear(ARG->render);
    for (int i=0;i<ARG->lsS; i++)
        SDL_RenderCopyEx(ARG->render,
                         ARG->shownSprites[i]->spriteTexture,
                         NULL,
                         &ARG->shownSprites[i]->arguments->parametres,
                         &ARG->shownSprites[i]->arguments->center,
                         );
    SDL_RenderPresent(ARG->render);
    return succes;
}

int SEL_QUIT(SEL_ConsoleWindow *ARG){
    CloseArea();
    SDL_DestroyRenderer(ARG->render);
    SDL_FreeSurface(ARG->surface);
    SDL_DestroyWindow( ARG->Window );
    SDL_QUIT();
    return 0;
}

extern SEL_ConsoleWindow *SEL_initMainW();
extern int SEL_CloseCW();

#endif
