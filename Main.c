#include <stdio.h>
#include <stdlib.h>
#include "AreaBox.h"

unsigned int height=100000, width=100000, layots=8;

Areamap *map;
sprite *Smap;

int main(){
    char name[15];
    strncpy(name, "Practicalname1", 15);
    int n=2;
    map = Area(height, width, layots);
    map = CreateSprite(name, 1, 0);
    strncpy(name, "Practicalname2", 15);
    map = CreateSprite(name, 1, 1);
    Smap = ReturnNSprite(n);
    for (int i=1;i<=n;i++){
        Smap = ReturnNSprite(i);
        if (Smap != 0){
            printf("%s\n", Smap->name);
        }
        else {
            printf("%s\n", map->error);
            break;
        }
    }
    printf("Hello, World!\n");
    CloseArea();
    return 0;
}
