#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>


unsigned int KEYS[322] = {0U};
SDL_Event Event;
int Exit = 1, height = 100, width = 100;

typedef struct ColisionS{
    int Height[1];
    int Width[1];
    int CountC;
} ColisionS;

typedef struct sprite{
    int Posx;
    int Posy;
    ColisionS Colision;
} sprite;

int EventShow(){
    short int Succes = 1;
    return Succes
}

int main(int argc, char* argv[]) {
    sprite Player = {0,0};
    Player.Colision.CountC = 1;
    Player.Colision.Width[0] = 10;
    Player.Colision.Height[0] = 10;
    SDL_Window *MainWindow = NULL;
    SDL_Surface *MainSurface = NULL;
    MainWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );

    while (Exit != 0){

        while (SDL_PollEvent(&Event) != 0){
            if (Event.key.keysym.sym == SDLK_w){
                Player.Posx += 1;
                KEYS[Event.key.keysym.sym] = 1;
            }
            if (Event.key.keysym.sym == SDLK_q){
                Player.Posx -= 1;
                KEYS[Event.key.keysym.sym] = 1;
            }
            if (Event.key.keysym.sym == SDLK_d){
                Player.Posy += 1;
                KEYS[Event.key.keysym.sym] = 1;
            }
            if (Event.key.keysym.sym == SDLK_a){
                Player.Posy -= 1;
                KEYS[Event.key.keysym.sym] = 1;
            }
            if (Event.key.keysym.sym == SDLK_q){
                Exit = 0;
                printf("LOL\n");
                break;
            }
            printf("%d\n", Event.key.keysym.sym);
        }

    }

    SDL_FreeSurface( MainSurface );
    SDL_DestroyWindow( MainWindow );
    printf("End");

    return 0;
}

/*
SDL_Texture* loadTexture(char *path){
    //The final texture
    SDL_Texture* newTexture = NULL;
    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path );
    if( loadedSurface == NULL ){
        printf( "Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError() );
    }
    else{
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if( newTexture == NULL ){
            printf( "Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError() );
        }
        //Get rid of old loaded surface

    }
    SDL_FreeSurface( loadedSurface );
    return newTexture;
}*/
