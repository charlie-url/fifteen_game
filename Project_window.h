#ifndef PROJECT_WINDOW_GUARD
#define PROJECT_WINDOW_GUARD 1

#include "lib/std_lib_facilities_5.h"
#include "lib/Window.h"
#include "lib/Graph.h"
#include "lib/Simple_window.h"

//Tells us what page/screen should be loaded
enum Game_state { Default = 0, Splash = 1, Instruct = 2, Level = 3, Game_10 = 10, Game_20 = 20, Game_40 = 40, Game_80 = 80, End = 5, Quit = 6 };


struct Project_window : Graph_lib::Window {

	Project_window(Point xy, int w, int h, const string& title); 

	void set_username(string new_name);
	Game_state wait_for_button();
	void set_state(Game_state new_state);
	void quit();
	Text username;
protected:
	
	string player_name;
	Button quit_button;
	Text leaderboard_username;
	bool button_pushed;
	Game_state state;
};



#endif // !PROJECT_WINDOW_GUARD



