
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include "model.h"
#include <map>
#include <string>
#include <sstream>

#ifndef _VIEW_H
#define _VIEW_H



// Show (output) the state of the model
class View {
public:
    View(std::string title, int width, int height);
    ~View();
    // Print out the visible stuff in the grid
    void show(Model * model);
//	SDL_Rect Rect[31];
private:
	bool Collision(SDL_Rect a, SDL_Rect b);
	SDL_Surface* life;
	SDL_Surface* background;
	SDL_Surface* background2;
	SDL_Surface* pacmanclose;
	SDL_Surface* text;
	SDL_Surface* words;
	SDL_Surface* pill;
	SDL_Surface* spill;
    SDL_Window* window;
    SDL_Surface* screen;
    bool fail;
    SDL_Surface* load(char * path);
	std::map<Direction, SDL_Surface*> pacman;
	SDL_Surface* Ghost;
	SDL_Surface* Ghost2;
	Mix_Music * startup;
	Mix_Chunk * death;
	Mix_Chunk * chomp;
	SDL_Rect dest;
	TTF_Font* font;


	int frame;
};
#endif