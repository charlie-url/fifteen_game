#ifndef SPLASH_SCREEN_GUARD
#define SPLASH_SCREEN_GUARD 1

#include "Project_window.h"


struct Splash_screen : public Project_window {

	Splash_screen(Point xy, int w, int h, const string& title);

	string get_username();

private:
	Text game_name = Text{ Point{ 100,100 }, "Fifteen Game" };
	Text team_info = Text{ Point{ 100,150 }, "Team 41: TeamName" };
	Text team_roster = Text{ Point{ 100,200 }, "Charles Wong Savannah Yu Cindy Zhang Eric Zhang" };


	Button show_instructions;
	Button play_button;
	In_box name_entry;
};



#endif // !SPLASH_SCREEN_GUARD


