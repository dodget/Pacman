#ifndef _MODEL_H
#define _MODEL_H
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>



enum State { RUN, SEEK, RESET};
enum Direction { UP, DOWN, LEFT, RIGHT, STILL };



// The model manages the state of the game
class Model {
public:
    // Constructor (instantiates object)
    Model(int w, int h);
    // Destructor deletes all dynamically allocated stuff
    ~Model();
	void go(Direction d);
	void move();
    // Is the game over?
    bool gameOver();
	//Make the object move
	// Move (if the next spot is a wall d = STILL)
	Direction direction;
	void move_pac();
	bool paccollision(SDL_Rect& rect, Direction direction);
	bool Collision(SDL_Rect a, SDL_Rect b);
	// Move the ghosts (if the next spot is a wall, switch direction)
	void move_ghost();
	void reset();
	void new_path(int k);
	bool ghostcollision(SDL_Rect ghost, Direction d);
	void ghost_bump(int g);
    // instantiate objects
	SDL_Rect pacman;
	SDL_Rect Rect[32];
	// Locations of the pills
	SDL_Rect pills[124];
	// Is the pill being shown?
	bool pillShown[124];
	void newlevel();
	// ghosts 
	int time;
	SDL_Rect ghost[3];
	bool SPshown[5];
	SDL_Rect SPloc[5];
	SDL_Rect middle;
	SDL_Rect middle2;
	SDL_Rect checkblock;
	SDL_Rect offset;
	Direction ghostd[4];
	Direction last_d;
	bool overlap(SDL_Rect c, SDL_Rect d);
	
	State state;
	void resetghost(int i);
	int score;
	int lives;
};

#endif