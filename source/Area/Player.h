#ifndef _Player_H_
#define _Player_H_


#include <SDL.h>

#include "sprites/sprite.h"

typedef struct Player{
    SDL_Texture *texture;
    double x;
    double y;
    float angle;
    int SWIDTH;
    int SHEIGT;
} Player;



#endif