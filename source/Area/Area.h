#ifndef _AreaBox_H_
#define _AreaBox_H_

#include "Area.c"

typedef struct AreaMap {
    sprite* sprites;
    char error[30];
    int mapwidth; 
    int mapheight;
    int maplayots;
    int sizesprites;
    int sizeflexingsprites;
    //effect* effects;
    //int sizeffects;
} AreaMap;

int *Area(unsigned int inwidth, unsigned int inheight, unsigned int inlayots);


#endif