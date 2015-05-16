#include "view.h"
#include <sstream>

using namespace std;
// Initialize Barriers


// Initialize SDL
View::View(string title, int width, int height) {
    fail = false;
    SDL_SetMainReady();
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0) {
        fail = true;
        return;
    }
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        fail = true;
        return;
    }
    // Get the screen
    screen = SDL_GetWindowSurface(window);
    //Initialize JPEG and PNG loading
    if( !( IMG_Init( IMG_INIT_JPG|IMG_INIT_PNG ) & (IMG_INIT_JPG|IMG_INIT_PNG) ) ) {
        fail = true;
        return;
    }
    //Initialize SDL_mixer
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
        fail = true;
        return;
    }

    // Initialize True type fonts
    if( TTF_Init() == -1 ) {
        return;
    }
	
	pill = load("assets/pill.png");
	SDL_SetColorKey(pill, SDL_TRUE, SDL_MapRGB(screen->format,0x00,0x00,0x00));
	spill = load("assets/Superpill.png");
	SDL_SetColorKey(spill, SDL_TRUE, SDL_MapRGB(screen->format,0x00,0x00,0x00));

	frame = 0;
		
	
	
	
    // Load assets
	life = load("assets/lives.png");
    pacman[RIGHT] = load("assets/pacmanR.png");
	pacman[STILL] = load("assets/pacmanR.png");
	pacman[LEFT] = load("assets/Lpacman.png");
	pacman[UP] = load("assets/Upacman.png");
	pacman[DOWN] = load("assets/Dpacman.png");
	
	
	
	//Load ghost
	Ghost = load("assets/pacman-ghost.png");
	Ghost2 = load("assets/RUNghost.png");
	
	SDL_SetColorKey(life, SDL_TRUE, SDL_MapRGB(screen->format, 0x00,0x00,0x00));
	SDL_SetColorKey(Ghost, SDL_TRUE, SDL_MapRGB(screen->format, 0x00,0x00,0x00));
	SDL_SetColorKey(Ghost2, SDL_TRUE, SDL_MapRGB(screen->format, 0x00,0x00,0x00));
	SDL_SetColorKey(pacman[RIGHT], SDL_TRUE, SDL_MapRGB(screen->format, 0x00,0x00,0x00));
	SDL_SetColorKey(pacman[STILL], SDL_TRUE, SDL_MapRGB(screen->format, 0x00,0x00,0x00));
	SDL_SetColorKey(pacman[LEFT], SDL_TRUE, SDL_MapRGB(screen->format, 0x00,0x00,0x00));
	SDL_SetColorKey(pacman[UP], SDL_TRUE, SDL_MapRGB(screen->format, 0x00,0x00,0x00));
	SDL_SetColorKey(pacman[DOWN], SDL_TRUE, SDL_MapRGB(screen->format, 0x00,0x00,0x00));
	background = load("assets/background.jpg");
	background2 = load("assets/RUNbackground.jpg");
	
    startup = Mix_LoadMUS("assets/pacman_beginning.wav");
	Mix_PlayMusic( startup, 1 );

    chomp = Mix_LoadWAV("assets/pacman_chomp.wav");
	death = Mix_LoadWAV("assets/pacman_death.wav");
    font = TTF_OpenFont( "assets/LiberationSans-Regular.ttf", 28 );
		
}


View::~View() {
    SDL_DestroyWindow(window);
	SDL_FreeSurface(pacman[RIGHT]);
	SDL_FreeSurface(pacman[LEFT]);
	SDL_FreeSurface(pacman[UP]);
	SDL_FreeSurface(pacman[DOWN]);
	SDL_FreeSurface(pill);
	SDL_FreeSurface(Ghost);
	
	for (int p = 0; p < 124; p++)

	SDL_FreeSurface(background);
	
	SDL_FreeSurface(spill);

	IMG_Quit();
    SDL_Quit();
}

/**
 *  Load an image from a file to a SDL_Surface
 */
SDL_Surface* View::load(char * path) {
    // Load image
    SDL_Surface* optimizedSurface = NULL;
    SDL_Surface* loadedSurface = IMG_Load( path );
    if( loadedSurface == NULL ) {
        return NULL;
    }
    // Convert surface to screen format
    optimizedSurface = SDL_ConvertSurface( loadedSurface, screen->format, 0 );
    
    // Get rid of old loaded surface
    SDL_FreeSurface( loadedSurface );
    return optimizedSurface;
}

void View::show(Model * model) {
	if (model->state == SEEK){
	SDL_Rect fontdest;
	SDL_BlitSurface(background, NULL, screen, NULL);
	
	for (int i = 0; i < 124; i++){
		if (model->pillShown[i] == true){
		SDL_BlitSurface(pill, NULL, screen, &(model->pills[i]));
		}
		
	
	}
			
	for (int m = 0; m < 5; m++){
		if (model->SPshown[m] == true){
		SDL_BlitSurface(spill, NULL, screen, &model->SPloc[m]);
		}
	}
	
		
	
	
	//pacman&pill collision
	for (int i = 0; i < 124; i++){
		 if (model->direction == RIGHT && model->pacman.x + 4 == model->pills[i].x && model->pacman.y == model->pills[i].y && model->pillShown[i]==true)
		Mix_PlayChannel( -1, chomp, 0);
		if (model->direction == LEFT && model->pacman.x - 4 == model->pills[i].x && model->pacman.y == model->pills[i].y && model->pillShown[i]==true)
		Mix_PlayChannel( -1, chomp, 0);
		if (model->direction == UP && model->pacman.x == model->pills[i].x && model->pacman.y -4 == model->pills[i].y && model->pillShown[i]==true)
		Mix_PlayChannel( -1, chomp, 0);
		if (model->direction == DOWN && model->pacman.x == model->pills[i].x && model->pacman.y +4 == model->pills[i].y && model->pillShown[i]==true)
		Mix_PlayChannel( -1, chomp, 0);
		}
		//Pacman & Ghost collision
				
		for (int i = 0; i < 3; i++){
		dest.x = model->ghost[i].x;
		dest.y = model->ghost[i].y;
		SDL_BlitSurface(Ghost, NULL, screen, &dest);
		}
		
		SDL_Rect lr;
	for (int i = 0; i < model->lives; i++){
		lr.x = 512 + (i*24);
		lr.y = 450;
		SDL_BlitSurface(life, NULL, screen, &lr);
		}
	
    // Probably call SDL_FillRect or SDL_BlitSurface a bunch here :-)

	SDL_BlitSurface(pacman[model->direction], NULL, screen, &(model->pacman));
	//LIVES
	
	stringstream s;
	s << "Score: " << model->score;
	SDL_Color textColor = { 255, 255, 255 };
	if (model->lives>0){
		text = TTF_RenderText_Solid(font, s.str().c_str(), textColor);
		fontdest.x = 0;
		fontdest.y = 0;
		SDL_BlitSurface( text, NULL, screen, &fontdest );
	}
	else{
		text = TTF_RenderText_Solid(font,"GAME OVER", textColor);
		fontdest.x = 230;
		fontdest.y = 250;
		SDL_BlitSurface( text, NULL, screen, &fontdest );
	}
	/*SDL_Color textColor = { 255, 255, 255 };
    text1 = TTF_RenderText_Solid( font, "Lives: ", textColor );
	fontdest.x = 250;
    fontdest.y = 250;
    SDL_BlitSurface( text1, NULL, screen, &fontdest );
	text2 = TTF_RenderText_Solid( font, model->lives, textColor );
	fontdest.x = 275;
    fontdest.y = 250;
    SDL_BlitSurface( text2, NULL, screen, &fontdest );
	*/

	SDL_UpdateWindowSurface(window);
	}
	
	if (model->state == RUN){
		SDL_BlitSurface(background2, NULL, screen, NULL);
	
	for (int i = 0; i < 124; i++){
		if (model->pillShown[i] == true){
		SDL_BlitSurface(pill, NULL, screen, &(model->pills[i]));
		}
		
	
	}
			
	for (int m = 0; m < 5; m++){
		if (model->SPshown[m] == true){
		SDL_BlitSurface(spill, NULL, screen, &model->SPloc[m]);
		}
	}
	for (int i = 0; i < 124; i++){
		 if (model->direction == RIGHT && model->pacman.x + 4 == model->pills[i].x && model->pacman.y == model->pills[i].y && model->pillShown[i]==true)
		Mix_PlayChannel( -1, chomp, 0);
		if (model->direction == LEFT && model->pacman.x - 4 == model->pills[i].x && model->pacman.y == model->pills[i].y && model->pillShown[i]==true)
		Mix_PlayChannel( -1, chomp, 0);
		if (model->direction == UP && model->pacman.x == model->pills[i].x && model->pacman.y -4 == model->pills[i].y && model->pillShown[i]==true)
		Mix_PlayChannel( -1, chomp, 0);
		if (model->direction == DOWN && model->pacman.x == model->pills[i].x && model->pacman.y +4 == model->pills[i].y && model->pillShown[i]==true)
		Mix_PlayChannel( -1, chomp, 0);
		}
		//Pacman & Ghost collision
		
		for (int i = 0; i < 3; i++){
		dest.x = model->ghost[i].x;
		dest.y = model->ghost[i].y;
		SDL_BlitSurface(Ghost2, NULL, screen, &dest);
		}
	SDL_Rect lr;
	for (int i = 0; i < model->lives; i++){
		lr.x = 512 + (i*24);
		lr.y = 450;
		SDL_BlitSurface(life, NULL, screen, &lr);
		}
    // Probably call SDL_FillRect or SDL_BlitSurface a bunch here :-)
	
	SDL_BlitSurface(pacman[model->direction], NULL, screen, &(model->pacman));
	
	
	SDL_UpdateWindowSurface(window);
	}
  
}
