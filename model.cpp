#include "model.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

using namespace std;

// Constructor initializes the object
Model::Model(int w, int h) {

	score = 0;
	lives = 3;
	// x-20 y-15
	pacman.x = 288; pacman.y = 416; pacman.h = 32; pacman.w = 32;
	
//initialize the ghosts
	ghost[0].x = 320; ghost[0].y = 240; ghost[0].h = 32; ghost[0].w = 32;	
	ghost[1].x = 576; ghost[1].y = 64; ghost[1].h = 32; ghost[1].w = 32;	
	ghost[2].x = 64; ghost[2].y = 416; ghost[2].h = 32; ghost[2].w = 32;
//	static SDL_Rect walls = {{0,0,32,640}, };
// Rect = walls;
	Rect[0].x = 0; 		Rect[0].y = 0; 		Rect[0].w = 32; 	Rect[0].h = 640;
	Rect[1].x = 32; 	Rect[1].y = 0; 		Rect[1].w = 608; 	Rect[1].h = 32;
	Rect[2].x = 0; 		Rect[2].y = 448; 	Rect[2].w = 640; 	Rect[2].h = 32;
	Rect[3].x = 608;	Rect[3].y = 32; 	Rect[3].w = 32;		Rect[3].h = 416;
	Rect[4].x = 64; 	Rect[4].y = 64; 	Rect[4].w = 32; 	Rect[4].h = 128;
	Rect[5].x = 96;		Rect[5].y = 160;	Rect[5].w = 64;		Rect[5].h = 32;
	Rect[6].x = 64;		Rect[6].y = 224;	Rect[6].w = 32;		Rect[6].h = 32;
	Rect[7].x = 128;	Rect[7].y = 224;	Rect[7].w = 64; 	Rect[7].h = 32;
	Rect[8].x = 64;		Rect[8].y = 288;	Rect[8].w = 32;		Rect[8].h = 128;
	Rect[9].x = 96;		Rect[9].y = 288;	Rect[9].w = 64; 	Rect[9].h = 32;
	Rect[10].x = 128;	Rect[10].y = 352;	Rect[10].w = 96; 	Rect[10].h = 64;
	Rect[11].x = 128;	Rect[11].y = 64;	Rect[11].w = 96; 	Rect[11].h = 64;
	Rect[12].x = 192;	Rect[12].y = 160;	Rect[12].w = 32; 	Rect[12].h = 160;
	Rect[13].x = 224;	Rect[13].y = 160;	Rect[13].w = 64; 	Rect[13].h = 32;
	Rect[14].x = 224;	Rect[14].y = 288;	Rect[14].w = 192; 	Rect[14].h = 32;
	Rect[15].x = 256;	Rect[15].y = 352;	Rect[15].w = 32; 	Rect[15].h = 96;
	Rect[16].x = 256; 	Rect[16].y = 64; 	Rect[16].w = 64; 	Rect[16].h = 64;
	Rect[17].x = 288; 	Rect[17].y = 128; 	Rect[17].w = 32; 	Rect[17].h = 64;
	Rect[18].x = 320; 	Rect[18].y = 320; 	Rect[18].w = 32; 	Rect[18].h = 32;
	Rect[19].x = 320; 	Rect[19].y = 352; 	Rect[19].w = 64; 	Rect[19].h = 64;
	Rect[20].x = 352; 	Rect[20].y = 32; 	Rect[20].w = 32; 	Rect[20].h = 96;
	Rect[21].x = 352; 	Rect[21].y = 160; 	Rect[21].w = 96; 	Rect[21].h = 32;
	Rect[22].x = 416; 	Rect[22].y = 192; 	Rect[22].w = 32; 	Rect[22].h = 128;
	Rect[23].x = 416; 	Rect[23].y = 352; 	Rect[23].w = 96; 	Rect[23].h = 64;
	Rect[24].x = 416; 	Rect[24].y = 64; 	Rect[24].w = 96; 	Rect[24].h = 64;
	Rect[25].x = 480; 	Rect[25].y = 160; 	Rect[25].w = 64; 	Rect[25].h = 32;
	Rect[26].x = 448; 	Rect[26].y = 224; 	Rect[26].w = 64; 	Rect[26].h = 32;
	Rect[27].x = 480; 	Rect[27].y = 288; 	Rect[27].w = 96; 	Rect[27].h = 32;
	Rect[28].x = 544; 	Rect[28].y = 320; 	Rect[28].w = 32; 	Rect[28].h = 96;
	Rect[29].x = 544; 	Rect[29].y = 224; 	Rect[29].w = 32; 	Rect[29].h = 32;
	Rect[30].x = 544; 	Rect[30].y = 64; 	Rect[30].w = 32; 	Rect[30].h = 128;
	Rect[31].x = 320;	Rect[31].y = 160; 	Rect[31].w = 32;	Rect[31].h = 32;

	middle.x = 224;		middle.y = 192;		middle.h = 96;		middle.w = 192;
	middle2.x = 320;	middle2.y = 160;	middle2.w = 32;		middle2.h = 32;
	checkblock.h = 32;	checkblock.w = 32;	checkblock.x = 0;	checkblock.y = 0;
	time =0;
	for (int i = 0; i <124 ; i++){
		pillShown[i] = true;
	}
	
	//SP locations
	SPloc[0].x = 32;	SPloc[0].y = 416;
	SPloc[1].x = 96;	SPloc[1].y = 128;
	SPloc[2].x = 416;	SPloc[2].y = 128;
	SPloc[3].x = 576;	SPloc[3].y = 32;
	SPloc[4].x = 576;	SPloc[4].y = 320;
	
	for(int i = 0; i < 5; i++){
		SPshown[i] = true;
	}
	
	int p = 0;
	offset.x = 0;		offset.y = 0;
	checkblock.x = 0;	checkblock.y = 0;

	//Initializes pills locations
	for (int x = 0; x < 19; x++){
		checkblock.y = 0;
		offset.y = 0;
		for (int y = 0; y < 14; y++){
			for (int b = 0; b < 31; b++){
			if (Collision(checkblock, Rect[b]) || Collision(checkblock, middle)
				|| Collision(checkblock, middle2)){
				break;
				}
			if (b == 30 && !Collision(checkblock, Rect[b]) && !Collision(checkblock, middle)
				&& !Collision(checkblock, middle2)){
				pills[p].x = offset.x;	pills[p].y = offset.y;
				// prints pill
				p++;
				}
			}
			checkblock.y += 32;
			offset.y += 32;
		}
		checkblock.x += 32;
		offset.x += 32;
	}
	
	state = SEEK;
	direction = STILL;
	ghostd[0] = UP;
	ghostd[1] = DOWN;
	ghostd[2] = RIGHT;
	//initialize new directions for my ghosts
	
	
};


bool Model::Collision(SDL_Rect a, SDL_Rect b){
	int lefta, leftb, righta, rightb, topa, topb, bottoma, bottomb;

	lefta = a.x;
	righta = a.x + a.w;
	topa = a.y;
	bottoma = a.y + a.h;

	leftb = b.x;
	rightb = b.x + b.w;
	topb = b.y;
	bottomb = b.y + b.h;

	if (bottoma <= topb || topa >= bottomb || righta <= leftb || lefta >= rightb)
		return false;
	else 
		return true;
};

bool Model::paccollision(SDL_Rect& rect, Direction direction){
	int lefta, leftb, righta, rightb, topa, topb, bottoma, bottomb;
	
	lefta = rect.x;
	righta = rect.x + rect.w;
	topa = rect.y;
	bottoma = rect.y + rect.h;
	
	switch(direction){
		case UP:
		topa += -2;
		for (int i = 0; i < 32; i++){
	leftb = Rect[i].x;
	rightb = Rect[i].x + Rect[i].w;
	topb = Rect[i].y;
	bottomb = Rect[i].y + Rect[i].h;
	if (bottoma > topb && topa < bottomb && righta > leftb && lefta < rightb){
		cout << i << endl;
		return true;
	break;}
}
	return false;
	break;
		case DOWN:
		bottoma += 2;
		for (int i = 0; i < 32; i++){
	leftb = Rect[i].x;
	rightb = Rect[i].x + Rect[i].w;
	topb = Rect[i].y;
	bottomb = Rect[i].y + Rect[i].h;
	if (bottoma > topb && topa < bottomb && righta > leftb && lefta < rightb){
		cout << i << endl;
		return true;
	break;}
		
}
	return false;
	break;
		case RIGHT:
		righta += 2;
		for (int i = 0; i < 32; i++){
	leftb = Rect[i].x;
	rightb = Rect[i].x + Rect[i].w;
	topb = Rect[i].y;
	bottomb = Rect[i].y + Rect[i].h;
	if (bottoma > topb && topa < bottomb && righta > leftb && lefta < rightb){
		cout << i << endl;
		return true;
	break;}
}
	return false;
	break;
		case LEFT:
		lefta += -2;
		for (int i = 0; i < 32; i++){
	leftb = Rect[i].x;
	rightb = Rect[i].x + Rect[i].w;
	topb = Rect[i].y;
	bottomb = Rect[i].y + Rect[i].h;
	if (bottoma > topb && topa < bottomb && righta > leftb && lefta < rightb){
		return true;
		cout << i << endl;
	break;}
}
	return false;
		break;
	}

}


	

//TODO: make pacman move.
//*if next Rect is a barrier, direction is STILL
void Model::move_pac() {

switch (state){
	case SEEK:
	for(int i = 0; i < 4; i++){
			if (pacman.x == ghost[i].x && pacman.y == ghost[i].y){ 	
				reset();
				direction = STILL;
			}
		}

//	if (!moving) { return; }
	switch(direction) {
	case STILL: return;
    case UP: if (!paccollision(pacman, direction)){pacman.y += -2;} break;
    case DOWN: if (!paccollision(pacman, direction)){pacman.y += 2;} break;
    case LEFT: if (!paccollision(pacman, direction)){pacman.x += -2;} break;
    case RIGHT: if (!paccollision(pacman, direction)){pacman.x += 2;}break;
	
	
    }
	
		
	
	for(int i = 0; i < 124; i++){
		if (pacman.x == pills[i].x && pacman.y == pills[i].y){
			if (pillShown[i] == true)
			score += 100;
			if (state == RUN && pillShown[i] == true){
				time += 1;
				score += 100;
				if (time == 7){
					state = SEEK;
					time = 0;
				}
				
			}
			pillShown[i] = false;
			
		}
	}
	for(int i = 0; i < 5; i++){
		if (pacman.x == SPloc[i].x && pacman.y == SPloc[i].y){
			if (SPshown[i] == true)
			state = RUN;
			SPshown[i] = false;
			
		}
		//else
		//Change state to get ghosts
	}
	break;
	case RUN:
	for(int i = 0; i < 4; i++){
			if (Collision(pacman, ghost[i]))/*pacman.x == ghost[i].x && pacman.y == ghost[i].y*/{ 	
				resetghost(i);		
			}
		}


	switch(direction) {
	case STILL: return;
    case UP: if (!paccollision(pacman, direction)){pacman.y += -2;} break;
    case DOWN: if (!paccollision(pacman, direction)){pacman.y += 2;} break;
    case LEFT: if (!paccollision(pacman, direction)){pacman.x += -2;} break;
    case RIGHT: if (!paccollision(pacman, direction)){pacman.x += 2;}break;
	
	
    }
	
		
	
	for(int i = 0; i < 124; i++){
		if (pacman.x == pills[i].x && pacman.y == pills[i].y){
			if (state == RUN && pillShown[i] == true){
				time += 1;
				if (time == 7){
					state = SEEK;
					time = 0;
				}
				
			}
			pillShown[i] = false;
			score += 100;
			
		}
	}
	for(int i = 0; i < 5; i++){
		if (pacman.x == SPloc[i].x && pacman.y == SPloc[i].y){
			if (SPshown[i] == true)
			state = RUN;
			SPshown[i] = false;
			
		}	
	}
	
	break;
	}
	
};

void Model::go(Direction d){
	direction = d;
};


void Model::reset(){
		pacman.x = 288; pacman.y = 416; pacman.h = 32; pacman.w = 32;
		ghost[0].x = 320; ghost[0].y = 240; ghost[0].h = 32; ghost[0].w = 32;	
		ghost[1].x = 576; ghost[1].y = 64; ghost[1].h = 32; ghost[1].w = 32;	
		ghost[2].x = 64; ghost[2].y = 416; ghost[2].h = 32; ghost[2].w = 32;
		ghostd[0] = UP;
		ghostd[1] = DOWN;
		ghostd[2] = RIGHT;
		lives--;
		SDL_Delay(1000);
};

void Model::resetghost(int i){
	ghost[i].x = 320; ghost[i].y = 240; ghost[i].h = 32; ghost[i].w = 32;
	ghostd[i] = UP;
};

//TODO: make ghost collision function
//just like pacman collision
bool Model::ghostcollision(SDL_Rect ghost, Direction d){

		int lefta, leftb, righta, rightb, topa, topb, bottoma, bottomb;
	
	
	
		lefta = ghost.x;
		righta = ghost.x + ghost.w;
		topa = ghost.y;
		bottoma = ghost.y + ghost.h;
	
		switch(d){
			case UP:
			topa += -2;
			for (int i = 0; i < 31; i++){
				leftb = Rect[i].x;
				rightb = Rect[i].x + Rect[i].w;
				topb = Rect[i].y;
				bottomb = Rect[i].y + Rect[i].h;
					if (bottoma > topb && topa < bottomb && righta > leftb && lefta < rightb){
						cout << i << endl;
						return true;
				break;}
		}
		return false;
		break;
			case DOWN:
			bottoma += 2;
			for (int i = 0; i < 31; i++){
				leftb = Rect[i].x;
				rightb = Rect[i].x + Rect[i].w;
				topb = Rect[i].y;
				bottomb = Rect[i].y + Rect[i].h;
					if (bottoma > topb && topa < bottomb && righta > leftb && lefta < rightb){
						cout << i << endl;
						return true;
				break;}
		
		}
		return false;
		break;
			case RIGHT:
			righta += 2;
			for (int i = 0; i < 31; i++){
				leftb = Rect[i].x;
				rightb = Rect[i].x + Rect[i].w;
				topb = Rect[i].y;
				bottomb = Rect[i].y + Rect[i].h;
					if (bottoma > topb && topa < bottomb && righta > leftb && lefta < rightb){
					cout << i << endl;
					return true;
				break;}
	}
		return false;
		break;
			case LEFT:
			lefta += -2;
			for (int i = 0; i < 31; i++){
				leftb = Rect[i].x;
				rightb = Rect[i].x + Rect[i].w;
				topb = Rect[i].y;
				bottomb = Rect[i].y + Rect[i].h;
					if (bottoma > topb && topa < bottomb && righta > leftb && lefta < rightb){
					return true;
					cout << i << endl;
				break;}
	}
		return false;
		break;
	}


}

bool Model::overlap(SDL_Rect c, SDL_Rect d){	
	return SDL_HasIntersection(&c,&d);
};

//TODO: choose a new path for the ghost
void Model::new_path(int k){

	

		int path1, path2, path3, path4;
		//path1 = 5000;
		//path2 = 5001;
		//path3 = 5002;
		//path4 = 5003;
		SDL_Rect c1,c2,c3,c4;
		c1 = ghost[k]; c1.y -= 1; //up path1 will be up
		c2 = ghost[k]; c2.y += 1; //down path2 will be down
		c3 = ghost[k]; c3.x -= 1; //left path3 will be left
		c4 = ghost[k]; c4.x += 1; //right path4 will be right
	
	switch (state){
		case SEEK:
		for (int i = 0; i < 31; i++){
				if (!overlap(c1, Rect[i])){
					path1 = abs (c1.x - pacman.x) + abs (c1.y - pacman.y);
				}
				
				if (!overlap(c2, Rect[i])){
					path2 = abs (c2.x - pacman.x) + abs (c2.y - pacman.y);
				}
				if (!overlap(c3, Rect[i])){
					path3 = abs (c3.x - pacman.x) + abs (c3.y - pacman.y);
				}
				if (!overlap(c4, Rect[i])){
					path4 = abs (c4.x - pacman.x) + abs (c4.y - pacman.y);
				}
				
			}
	
	switch (ghostd[k]) {
		case UP:
			if (path3 < path4){
				ghostd[k] = LEFT;
			}
			else {
				ghostd[k] = RIGHT;
			}
			break;
		case DOWN:
			if (path3 < path4){
				ghostd[k] = LEFT;
			}
			else {
				ghostd[k] = RIGHT;
			}
			break;
		case LEFT:
			if (path1 < path2){
				ghostd[k] = UP;
			}
			else {
				ghostd[k] = DOWN;
			}
			break;
		case RIGHT:
			if (path1 < path2){
				ghostd[k] = UP;
			}
			else {
				ghostd[k] = DOWN;
			}
			break;
	
	}
		break;
	case RUN:
				for (int i = 0; i < 31; i++){
				if (!overlap(c1, Rect[i])){
					path1 = abs (c1.x - pacman.x) + abs (c1.y - pacman.y);
				}
				
				if (!overlap(c2, Rect[i])){
					path2 = abs (c2.x - pacman.x) + abs (c2.y - pacman.y);
				}
				if (!overlap(c3, Rect[i])){
					path3 = abs (c3.x - pacman.x) + abs (c3.y - pacman.y);
				}
				if (!overlap(c4, Rect[i])){
					path4 = abs (c4.x - pacman.x) + abs (c4.y - pacman.y);
				}
				
			}
	
	switch (ghostd[k]) {
		case UP:
			if (path3 < path4){
				ghostd[k] = RIGHT;
			}
			else {
				ghostd[k] = LEFT;
			}
			break;
		case DOWN:
			if (path3 < path4){
				ghostd[k] = RIGHT;
			}
			else {
				ghostd[k] = LEFT;
			}
			break;
		case LEFT:
			if (path1 < path2){
				ghostd[k] = DOWN;
			}
			else {
				ghostd[k] = UP;
			}
			break;
		case RIGHT:
			if (path1 < path2){
				ghostd[k] = DOWN;
			}
			else {
				ghostd[k] = UP;
			}
			break;
	
	}
		break;
	}

	
};


void Model::ghost_bump(int g){
	for (int i = 0; i < 3; i++){
		if (i != g){
			if ((overlap(ghost[i], ghost[g])) && (ghostd[i] == ghostd[g])){
				switch(ghostd[g]) {
			case UP:
				ghostd[g] = DOWN;
				break;
			case DOWN:
				ghostd[g] = UP;
				break;
			case LEFT: 
				ghostd[g] = RIGHT;
				break;
			case RIGHT: 
				ghostd[g] = LEFT;
				break;
	
		}
			
			}
		}
	}
};

//moves the ghost
void Model::move_ghost(){


	
	for (int i = 0; i < 3; i++){
		if (ghostcollision(ghost[i], ghostd[i]) == true ){
			new_path(i);
		}
		else if ((ghost[i].x == 96 && ghost[i].y == 0) || (ghost[i].x == 320 && ghost[i].y == 128) || (ghost[i].x == 576 && ghost[i].y == 192)
					|| (ghost[i].x == 384 && ghost[i].y == 384) || (ghost[i].x == 160 && ghost[i].y == 320) || (ghost[i].x == 96 && ghost[i].y == 192)
					||  (ghost[i].x == 448 && ghost[i].y == 192)){
						new_path(i);
				}
	}
	
	
		
	
	
	for (int i = 0; i < 3; i++){
		ghost_bump(i);
	}
	
	for (int i = 0; i < 3; i++){
		if (ghost[i].x == 320 && ghost[i].y == 224 && ghostd[i] == DOWN){
			ghostd[i] = UP;
		}
	}
	
	
	
	for (int j = 0; j < 3; j++){
		switch(ghostd[j]) {
			case UP:
				if (!ghostcollision(ghost[j], ghostd[j])){
					ghost[j].y -= 2; 
				}
				break;
			case DOWN:
				if (!ghostcollision(ghost[j], ghostd[j])){
					ghost[j].y += 2; 
				}
				break;
			case LEFT: 
				if (!ghostcollision(ghost[j], ghostd[j])){
					ghost[j].x -= 2; 
				}
				break;
			case RIGHT: 
				if (!ghostcollision(ghost[j], ghostd[j])){
					ghost[j].x += 2; 
				}
				break;
	
		}
	}
	
};


// Destructor deletes dynamically allocated memory
Model::~Model() {
};

bool Model::gameOver() {
	int n = 0;
	
	for (int i = 0; i < 124; i++){
		if (pillShown[i] == false)
			n++;
	}
	if (lives == 0)
		return true;
	return n > 123;
};

