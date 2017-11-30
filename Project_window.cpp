#include "Project_window.h"




	Project_window::Project_window(Point xy, int w, int h, const string& title)
		:Window{ xy,w,h,title },
		username{ Text(Point(360,650),"username") },
		leaderboard_username{ Text(Point(550,525), "username") },
		quit_button{ Point{ 70,0 }, 70, 20, "Quit",[](Address, Address pw) {reference_to<Project_window>(pw).quit(); } },
		button_pushed{ false },
		state{ Game_state(Default) }
	{
		attach(quit_button);
	}

	void Project_window::set_username(string new_name) {
		username.set_label(new_name);
		leaderboard_username.set_label(new_name);
		Fl::redraw();
	}

	Game_state Project_window::wait_for_button() {
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

	void Project_window::set_state(Game_state new_state) {
		state = new_state;
		button_pushed = true;
	}

	void Project_window::quit() {
		button_pushed = true;
		make_current();
		hide();
		state = Game_state(Quit);
	}
