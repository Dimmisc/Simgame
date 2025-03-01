#include <SDL.h>

#include "sprite.h"


typedef struct parametresSprite {
    SDL_Rect parametres;
    double rotation;
    SDL_Point center_rotation;
    int layot;
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
