#ifndef _SEL_H_
#define _SEL_H_


typedef struct SEL_ConsoleWindow {
    SDL_Window *window;
    SDL_Surface *surface;
    SDL_Renderer *render;
    sprite **shownSprites;
    char Error[30];
    int lsS;
    short int error_continue;
} SEL_ConsoleWindow;

typedef struct WindowSetting {
    int width;
    int height;
    int x;
    int y;
    char name[];
} WindowSettings;



int SEL_init(SEL_ConsoleWindow *ARG, WindowSettings *settings);
int SEL_Moving_of_Sprites(AreaMap *AREA, int speed);
int SEL_UpdateScreen(SEL_ConsoleWindow *ARG);
int SEL_Start(int TPS);
int SEL_WQuit(SEL_ConsoleWindow *ARG);
int SEL_AQuit(AreaMap *Area);
int SEL_Exit();


#endif