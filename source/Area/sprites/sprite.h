#ifndef _Sprite_H_
#define _Sprite_H_

#include <SDL.h>


typedef struct parametresSprite {
    SDL_Rect parametres;
    double rotation;
    SDL_Point center_rotation;
    unsigned short int layot;
} parametresSprite;

typedef struct sprite {
    SDL_Texture *spriteTexture;
    parametresSprite arguments;
    SDL_RendererFlip reflaction;
    char name[15];
} sprite;

typedef struct FlexSprite {
    SDL_Texture *spriteTexture;
    parametresSprite arguments;
    char name[15];
    SDL_RendererFlip reflaction;
    int typemove;
} FlexSprite;


#endif