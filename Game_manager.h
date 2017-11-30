#ifndef GAME_MANAGER_GUARD
#define GAME_MANAGER_GUARD 1

#include "Splash_screen.h"
#include "Instruct_screen.h"
#include "Level_select.h"
#include "Game_screen.h"
#include "End_screen.h"

struct Game_manager {

	Game_manager();//constructor that initializes one of each window

	void run();//runs loop for choosing the next window to go to

private:
	int difficulty;//tracks the difficulty of the current round
	Game_state current;//current game state(window)
	string username;
	Splash_screen splash;
	Instruct_screen instruct;
	Level_select level;
	Game_screen game;
	End_screen end;
};





#endif // !GAME_MANAGER_GUARD



