#ifndef SPLASH_SCREEN_GUARD
#define SPLASH_SCREEN_GUARD 1

#include "Project_window.h"


struct Splash_screen : public Project_window {

	Splash_screen(Point xy, int w, int h, const string& title); //Splash screen constructor

	string get_username();

private:
	Text game_name = Text{ Point{ 360-(150),90+128 }, "15 Game!" };
	Text team_info = Text{ Point{ 360-(25*12)/2,720-90-45}, "Brought to you by: [Team Compute]" };
	Text team_roster = Text{ Point{ 360-(40*12)/2, 720-90-20 }, "( Charles Wong     Savannah Yu     Cindy Zhang     Eric Zhang )" };


	Button show_instructions;
	Button play_button;
	In_box name_entry;
};



#endif // !SPLASH_SCREEN_GUARD


