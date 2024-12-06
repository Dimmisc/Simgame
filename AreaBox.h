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
  int mapwidth;
  int mapheight;
  int maplayots;
  sprite *sprites = malloc(sizeof(sprite));
  effect *effects = malloc(sizeof(effect));
  char error[15];
  int sizeeffect = 1;
  int sizesprites = 1;
} Areamap;

Areamap folder = {0,0,0};
int i = 0;
int nsprite = 0; // число отвечающее за длину массива sprites

 Areamap *Area(unsigned int inwidth, unsigned int inheight, unsigned int inlayots){
    folder.mapheight = inheight;
    folder.mapwidth = inwidth;
    folder.maplayots = inlayots;
    return &folder;
}

Areamap *CreateSprite(char name[15], int x, int y){
    int n = sizeof(folder.sprites) / sizeof(folder.sprites[0]) - 1;
    folder.sprites[n].posx = x;
    folder.sprites[n].posy = y;
    folder.sprites[n].layot = 0;
    strncpy(folder.sprites[n].name, name, 15);
    folder.sizesprites++;
    folder.sprites = realloc(folder.sprites, sizeof(folder.sprites) * (sizesprites));
    return &folder;
}

Areamap *Moveright(char namesprite[15], int speed){
    nsprite = sizeof(folder.sprites) / sizeof(folder.sprites[0]) - 1;
    while (folder.sprites[i].name != namesprite && i < nsprite){
        i++;
    }
    if (strcmp(namesprite, folder.sprites.name) == 0){
        strcpy(folder.error, "No sprite with this name");
        return &folder;
    }
    folder.sprites[i].posy++;
    i = 0;
    return &folder;
}

Areamap *Moveleft(char namesprite[15], int speed){
    nsprite = sizeof(folder.sprites) / sizeof(folder.sprites[0]) - 1;
    while (folder.sprites[i].name != namesprite && i < nsprite){
        i++;
    }
    if (strcmp(namesprite, folder.sprites.name) == 0){
        strcpy(folder.error, "No sprite with this name");
        return &folder;
    }
    folder.sprites[i].posy -= 1;
    i = 0;
    return &folder;
}

Areamap *Moveup(char namesprite[15], int speed){
    nsprite = sizeof(folder.sprites) / sizeof(folder.sprites[0]) - 1;
    while (folder.sprites[i].name != namesprite && i < nsprite){
        i++;
    }
    if (strcmp(namesprite, folder.sprites.name) == 0){
        strcpy(folder.error, "No sprite with this name");
        return &folder;
    }
    folder.sprites[i].posx++;
    i = 0;
    return &folder;
}

Areamap *Movedown(char namesprite[15], int speed){
    nsprite = sizeof(folder.sprites) / sizeof(folder.sprites[0]) - 1;
    while (folder.sprites[i].name != namesprite && i < nsprite){
        i++;
    }
    if (strcmp(namesprite, folder.sprites.name)){
        strcpy(folder.error,"No sprite with this name");
        return &folder;
    }
    folder.sprites[i].posx -= 1;
    i = 0;
    return &folder;
}

sprite *ReturnSprites(){
    return folder.sprites;
}

void closeArea(){
    i = 0;
    nsprite = 0;
    free(folder->sprites);
}

char Areaerror(){
    return *folder.error;
}

extern sprite *ReturnSprites();
extern Areamap *CreateSprite();
extern Areamap *Area();
#endif
