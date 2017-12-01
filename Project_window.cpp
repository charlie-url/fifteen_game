#include "Project_window.h"




	Project_window::Project_window(Point xy, int w, int h, const string& title)
		:Window{ xy,w,h,title },
		username{ Text(Point(((720-180)/2)-12,(720-90-3)),"username") },
		quit_button{ Point{ 90,90 }, 70, 24, "Quit",[](Address, Address pw) {reference_to<Project_window>(pw).quit(); } },
		leaderboard_username{ Text(Point(550,525), "username") },
		button_pushed{ false },
		state{ Game_state(Default) }
	{
		attach(quit_button);//every window has a quit button
	}

	void Project_window::set_username(string new_name) {

		username.set_label(new_name);//updates placeholder username
		leaderboard_username.set_label(new_name);
		player_name = new_name;
		username.set_label(new_name);
		Fl::redraw();
	}

	Game_state Project_window::wait_for_button() {//returns enum for next window to open
		make_current();
		show();
		cout << label() << endl;
		while (!button_pushed) {
			Fl::wait();
		}
		button_pushed = false;
		hide();
		return state;
	}

	void Project_window::set_state(Game_state new_state) {//setter for next window
		state = new_state;
		button_pushed = true;
	}

	void Project_window::quit() {//quits the entire game
		button_pushed = true;
		make_current();
		hide();
		state = Game_state(Quit);
	}
