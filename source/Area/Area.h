#ifndef _AreaBox_H_
#define _AreaBox_H_

#include "Area.c"


typedef struct Layot {
    sprite *sprites;
    int LenSprites;
} Layot;


typedef struct Cell {
    Layot *layots;
    int SizeLayots;
} Cell;


typedef struct CellSettings {
    int height;
    int width;
    int countHeight;
    int countWidth;
} CellSettings;


typedef struct AreaMap {
    char error[30];
    Cell **cells;
    CellSettings cellsArgs;
    int mapwidth;
    int mapheight;
    //effect* effects;
    //int sizeffects;
} AreaMap;


int *Area(unsigned int inwidth, unsigned int inheight, unsigned int inlayots);


#endif