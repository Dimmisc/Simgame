#include <stdio.h>
#include "AreaBox.h"

unsigned int height=100000, width=100000, layots=8;

Areamap *map;
sprite *Smap;

int main(int arc, char *argv[]){
    char name[15];
    strncpy(name, "Ork_deligation", 15);
    int n=1;
    map = Area(height, width, layots);
    map = CreateSprite(name, 1, 0);
    Smap = ReturnNSprite(n);
    if (Smap != 0){
        printf("%s\n", Smap->name);
    }
    else {
        printf("Error in function ReturnNSprite");
    }
    printf("Hello, World!");
    CloseArea();
    return 0;
}
