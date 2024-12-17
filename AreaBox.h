#ifndef _AreaBox_H_
#define _AreaBox_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>

typedef struct ParametresES{
    SDL_Rect parametres;
    double rotation;
    SDL_Point centerrotation;
    int layot;
}ParametresES;
SDL_point slam;

typedef struct sprite{
    SDL_Texture *spriteTexture;
    ParametresES arguments;
    char name[15];
    SDL_RendererFlip reflaction;
} sprite;

typedef struct flexsprite{
    SDL_Texture *spriteTexture;
    ParametresES arguments;
    char name[15];
    int typemove; 
    SDL_RendererFlip reflaction;
} flexsprite;

typedef struct effect{
    const double rotation;
    int posx;
    int posy;
    int layot;
    char name[15];
} effect;

typedef struct Areamap{
    sprite* solidsprites;
    FlexSprites* flexingsprites;
    char error[30];
    int mapwidth;
    int mapheight;
    int maplayots
    int sizesprites;
    int sizeflexingsprites;
    //effect* effects;
    //int sizeffects;
} Areamap;


Areamap folder = NULL;
int i = 0;

 Areamap *Area(unsigned int inwidth, unsigned int inheight, unsigned int inlayots){
    folder.mapheight = inheight;
    folder.mapwidth = inwidth;
    folder.maplayots = inlayots;
    //folder.sizeffects = 0;
    folder.sizesprites = 0;
    folder.sprites = (sprite*) malloc(sizeof(sprite) * 1);
    //folder.effects = (effect*) malloc(sizeof(effect) * 1);
    return &folder;
}

Areamap *CreateSprite(char name[15], int x, int y, int angle){
    folder.sizesprites++;
    folder.sprites = realloc(folder.sprites, (sizeof(sprite) * folder.sizesprites));
    folder.sprites[folder.sizesprites].arguments.parametres.x = x;
    folder.sprites[folder.sizesprites].arguments.parametres.y = y;
    folder.sprites[folder.sizesprites].layot = 0;
    folder.sprites[folder.sizesprites].rotation = angle;
    folder.sprites[folder.sizesprites].reflaction = NULL;
    strncpy(folder.sprites[folder.sizesprites].name, name, 15);
    return &folder;
}

Areamap *ChangePositionSprite(char namesprite[15], SDL_Rect *Argchange){
    int succes = 0;
    i = 0;
    while (strcmp(folder.sprites[i].name, namesprite) == 0 && i < folder.sizesprites - 1){
        i++;
    }
    if (i == folder.sizesprites) {
        strcpy(folder.error, "No sprite with this name");
    }
    else {
        folder.sprites[i].arguments.parametres.x = Argchange.posx;
        folder.sprites[i].arguments.parametres.y = Argchange.posy;
        succes = 1;
    }
    return succes;
}

sprite *ReturnNSprite(int n){
    if (n <= folder.sizesprites){
        return &folder.sprites[n];
    }
    else {
        strcpy(folder.error, "Error in function ReturnNSprite");
        return 0;
    }
}

void CloseArea(){
    i = 0;
    free(folder.sprites);
}

char AreaGetError(){
    return *folder.error;
}

/*extern Areamap *moveup();
extern Areamap *movedown();
extern Areamap *moveleft();
extern Areamap *moveright();*/
extern char Areaerror();
extern void CloseArea();
extern sprite *ReturnNSprite();
extern Areamap *CreateSprite();
extern Areamap *Area();
#endif
/*
Areamap *moveright(char namesp byrite[15], int speed){
    while (strcmp(folder.sprites[i].name, namesprite) == 0 && i < folder.sizesprites - 1){
        i++;
    }
    if (strcmp(namesprite, folder.sprites[i].name) == 0){
        strcpy(folder.error, "No sprite with this name");
        return &folder;
    }
    folder.sprites[i].posy++;
    i = 0;
    return &folder;
}

Areamap *moveleft(char namesprite[15], int speed){
    while (strcmp(folder.sprites[i].name, namesprite) == 0 && i < folder.sizesprites - 1){
        i++;
    }
    if (strcmp(namesprite, folder.sprites[i].name) == 0){
        strcpy(folder.error, "No sprite with this name");
        return &folder;
    }
    folder.sprites[i].posy -= 1;
    i = 0;
    return &folder;
}

Areamap *moveup(char namesprite[15], int speed){
    while (strcmp(folder.sprites[i].name, namesprite) == 0 && i < folder.sizesprites - 1){
        i++;
    }
    if (strcmp(namesprite, folder.sprites[i].name) == 0){
        strcpy(folder.error, "No sprite with this name");
        return &folder;
    }
    folder.sprites[i].posx++;
    i = 0;
    return &folder;
}

Areamap *movedown(char namesprite[15], int speed){
    while (strcmp(folder.sprites[i].name, namesprite) == 0 && i < folder.sizesprites - 1){
        i++;
    }
    if (strcmp(namesprite, folder.sprites[i].name) == 0){
        strcpy(folder.error, "No sprite with this name");
        return &folder;
    }
    folder.sprites[i].posx -= 1;
    i = 0;
    return &folder;
}
*/
