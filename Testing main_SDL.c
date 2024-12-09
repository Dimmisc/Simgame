#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    SDL_Window * Window;
    SDL_Surface *image;
    SDL_Renderer *Ren;
    image = IMG_Load("Simgame/Textures/Sprite.png");
    Window = SDL_CreateWindow("Hello World!", 100, 100, 400, 400, SDL_WINDOW_SHOWN);
    Ren = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(Ren, image);
    SDL_RenderClear(Ren);
    SDL_RenderCopy(Ren, tex, NULL, NULL);
    SDL_RenderPresent(Ren);
    SDL_Delay(10000);

    SDL_DestroyTexture(tex);
    SDL_FreeSurface(image);
    SDL_DestroyWindow(Window);
    SDL_DestroyRenderer(Ren);
    SDL_Quit();
    return 0;
}
