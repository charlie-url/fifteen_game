#ifndef GAME_MANAGER_GUARD
#define GAME_MANAGER_GUARD 1

#include "Splash_screen.h"
#include "Instruct_screen.h"
#include "Level_select.h"
#include "Game_screen.h"
#include "End_screen.h"

struct Game_manager {

	Game_manager();

	void run();

private:
	int difficulty;
	Game_state current;
	string username;
	Splash_screen splash;
	Instruct_screen instruct;
	Level_select level;
	Game_screen game;
	End_screen end;
};





#endif // !GAME_MANAGER_GUARD



