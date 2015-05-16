#include "controller.h"
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
int main(int argc, char** argv) {
    Controller c;
    c.loop();
    return 0;
}