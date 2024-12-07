#ifndef _AreaBox_H_
#define _AreaBox_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    int posx;
    int posy;
    int layot;
    char name[15];
} sprite;

typedef struct{
    int posx;
    int posy;
    int layot;
    char name[15];
} effect;

typedef struct{
  int mapwidth;
  int mapheight;
  int maplayots;
  sprite* sprites;
  effect* effects;
  char error[30];
  int sizeffects;
  int sizesprites;
} Areamap;

Areamap folder = {0,0,0};
int i = 0;

 Areamap *Area(unsigned int inwidth, unsigned int inheight, unsigned int inlayots){
    folder.mapheight = inheight;
    folder.mapwidth = inwidth;
    folder.maplayots = inlayots;
    folder.sizeffects = 0;
    folder.sizesprites = 0;
    folder.sprites = (sprite*) malloc(sizeof(sprite) * 0);
    folder.effects = (effect*) malloc(sizeof(effect) * 0);
    return &folder;
}

Areamap *CreateSprite(char name[15], int x, int y){
    folder.sizesprites++;
    folder.sprites = realloc(folder.sprites, (sizeof(sprite) * folder.sizesprites));
    folder.sprites[folder.sizesprites].posx = x;
    folder.sprites[folder.sizesprites].posy = y;
    folder.sprites[folder.sizesprites].layot = 0;
    strncpy(folder.sprites[folder.sizesprites].name, name, 15);
    return &folder;
}

Areamap *moveright(char namesprite[15], int speed){
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
        strcpy(folder.error,"No sprite with this name");
        return &folder;
    }
    folder.sprites[i].posx -= 1;
    i = 0;
    return &folder;
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
    free(folder.effects);
}

char Areaerror(){
    return *folder.error;
}

extern Areamap *moveup();
extern Areamap *movedown();
extern Areamap *moveleft();
extern Areamap *overight();
extern char Areaerror();
extern void CloseArea();
extern sprite *ReturnNSprite();
extern Areamap *CreateSprite();
extern Areamap *Area();
#endif
