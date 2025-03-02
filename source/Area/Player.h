#ifndef _Player_H_
#define _Player_H_

#include <SDL.h>

#include "sprites/sprite.h"


typedef struct Player {
    SDL_Texture *spriteTexture;
    parametresSprite arguments;
    SDL_RendererFlip reflaction;
    char name[15];
    int SWidth;
    int SHeight;
} Player;



#endif