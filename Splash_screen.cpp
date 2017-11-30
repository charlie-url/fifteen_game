#include "Splash_screen.h"


	Splash_screen::Splash_screen(Point xy, int w, int h, const string& title)
		:Project_window{ xy,w,h,title },
		show_instructions{ Point{ 360-8-128,360+16 }, 128, 64, "Help",  [](Address, Address pw) { reference_to<Splash_screen>(pw).set_state(Game_state(Instruct));} },
		play_button{ Point{ 360+8+0,360+16  }, 128, 64, "Play",  [](Address, Address pw) {  reference_to<Splash_screen>(pw).set_state(Game_state(Level)); } },
		name_entry{ In_box(Point(360-64,360-32-8), 128, 32, "") }
	{
		attach(play_button);
		attach(show_instructions);
		attach(game_name);
		attach(team_info);
		attach(team_roster);
		attach(name_entry);
	}

	string Splash_screen::get_username() {
		return name_entry.get_string();
	}
