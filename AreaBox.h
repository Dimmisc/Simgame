#ifndef _AreaBox_H_
#define _AreaBox_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    int posx;
    int posy;
    int type;
    char name[15];
} sprite;

typedef struct{
  int mapwidth;
  int mapheight;
  int maplayots;
  sprite *sprites[1];
  int *effects[1];
} Areamap;

Areamap folder={0,0,0};

 Areamap *Area(unsigned int inwidth, unsigned int inheight, unsigned int inlayots){
    Areamap folder = {inwidth, inheight, inlayots,};

    return &folder;
}

Areamap *CreateSprite(char name[15]){
    sprite c = {0,0,0};
    strcpy(c.name, name);
    folder.sprites[1] = &c;
    return &folder;
}

extern Areamap;
extern Areamap *CreateSprite();
extern Areamap *Area();

#endif
