#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>


unsigned int KEYS[322] = {0U};
SDL_Event Event;
int Exit = 1, height = 1000, width = 1000;
SDL_Window *MainWindow = NULL;
SDL_Surface *MainSurface = NULL;
SDL_Renderer *MainRender = NULL;

typedef struct ColisionS{
    int Height[1];
    int Width[1];
    int CountC;
} ColisionS;

typedef struct sprite{
    SDL_Texture *Texture;
    int Posx;
    int Posy;
    ColisionS Colision;
} sprite;

sprite Player = {0,0};

int LoadTexture(){
    MainSurface = IMG_Load("C:/MYprog/Simgame/Textures/Sprite.png");
    SDL_GetError();
    Player.Texture = SDL_CreateTextureFromSurface(MainRender, MainSurface);
    SDL_GetError();
    return 1;
}
int EventShow(){
    short int Succes = 1;
    SDL_RenderClear( MainRender );
    SDL_GetError();
    SDL_Rect Rect={Player.Posx, Player.Posy, 256, 256};
    SDL_RenderCopy(MainRender, Player.Texture, NULL, &Rect);
    SDL_GetError();
    SDL_RenderPresent(MainRender);
    SDL_GetError();
    return Succes;
}

int main(int argc, char* argv[]) {

    Player.Colision.CountC = 1;
    Player.Colision.Width[0] = 10;
    Player.Colision.Height[0] = 10;
    MainWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );
    MainRender = SDL_CreateRenderer(MainWindow, -1, SDL_RENDERER_ACCELERATED);
    LoadTexture();
    while (Exit != 0){

        while (SDL_PollEvent(&Event) != 0){
            if (Event.key.keysym.sym == SDLK_w){
                Player.Posy -= 1;
                KEYS[Event.key.keysym.sym] = 1;
            }
            if (Event.key.keysym.sym == SDLK_s){
                Player.Posy += 1;
                KEYS[Event.key.keysym.sym] = 1;
            }
            if (Event.key.keysym.sym == SDLK_d){
                Player.Posx += 1;
                KEYS[Event.key.keysym.sym] = 1;
            }
            if (Event.key.keysym.sym == SDLK_a){
                Player.Posx -= 1;
                KEYS[Event.key.keysym.sym] = 1;
            }
            if (Event.key.keysym.sym == SDLK_q){
                Exit = 0;
                printf("LOL\n");
                break;
            }
            EventShow();
            printf("%s\n", SDL_GetError());
        }


    }
    SDL_GetError();
    SDL_DestroyTexture(Player.Texture);
    SDL_DestroyRenderer( MainRender );
    SDL_FreeSurface( MainSurface );
    SDL_DestroyWindow( MainWindow );
    IMG_Quit();
    SDL_Quit();
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
