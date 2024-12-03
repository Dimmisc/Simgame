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
  sprite sprites[1];
  int *effects[1];
} Areamap;

Areamap folder={0,0,0};
int i=0;

 Areamap *Area(unsigned int inwidth, unsigned int inheight, unsigned int inlayots){
    folder.mapheight = inheight;
    folder.mapwidth = inwidth;
    folder.maplayots = inlayots;
    return &folder;
}

Areamap *CreateSprite(char name[15]){
    int n = sizeof(folder.sprites)/sizeof(folder.sprites[0]) - 1;
    folder.sprites[n].posx = 0;
    folder.sprites[n].posy = 0;
    folder.sprites[n].layot = 0;
    // добавление пустого элемента в folder.sprites (пока нету:() //
    return &folder;
}

sprite *ReturnSprites(){
    return folder.sprites;
    }

extern sprite *ReturnSprites();
extern Areamap *CreateSprite();
extern Areamap *Area();

#endif
