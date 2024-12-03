#include <stdio.h>
#include "AreaBox.h"

unsigned int height=100000, width=100000, layots=8;

Areamap *map;
sprite *Spritesonmap;

int main(int arc, char *argv[]){
    char name[15];
    
    map = Area(height, width, layots);
    map = CreateSprite(name);
    Spritesonmap = ReturnSprites();
    
    printf("Hello, World!");
    
    return 0;
}
