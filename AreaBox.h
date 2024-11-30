#ifndef _AreaBox_H_
#define _AreaBox_H_
#include <stdlib.h>
#include <stdio.h>
typedef struct{
  int mapwidth;
  int mapheight;
  int maplayots;
} Areamap;
 Areamap *Area(unsigned int inwidth, unsigned int inheight, unsigned int inlayots){
    Areamap c = {0, 1, 0,};
    return &c;
}
extern Areamap;
extern Areamap *Area();

#endif
