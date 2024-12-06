#include <stdio.h>
#include "AreaBox.h"

unsigned int height=100000, width=100000, layots=8;

Areamap *map;
sprite *Spritesonmap;

int main(){
    char name[15];

    map = Area(height, width, layots);
    map = CreateSprite(name, 1, 0);
    sprite *smap = ReturnSprites();

    printf("Hello, World!");
    CloseArea();
    return 0;
}
