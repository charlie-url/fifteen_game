#include "std_lib_facilities_5.h"
#include "Window.h"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"
#include "Simple_window.h"

struct Splash_screen : Graph_lib::Window {
	Splash_screen(Point xy, int w, int h, const string& title)
		:Window{ xy,w,h,title },
		show_instructions{ Point{ 360 - 64,360 + 32 }, 128, 64, "Instuctions",  [](Address, Address pw) { reference_to<Splash_screen>(pw).instruct(); } },
		play_button{ Point{ 360 - 64,360 - 32 }, 128, 64, "Play",  [](Address, Address pw) { reference_to<Splash_screen>(pw).play(); } },
		button_pushed{ false }
	{
		attach(play_button);
		attach(show_instructions);
		attach(game_name);
		attach(team_info);
		attach(team_roster);
		attach(instructions);
	}
	void wait_for_button() {
		while (!button_pushed) {
			Fl::wait();
		}
		button_pushed = false;
		play();
	}

private:
	Text game_name = Text{ Point{100,100}, "Fifteen Game" };
	Text team_info = Text{ Point{ 100,150 }, "Team 41: TeamName" };
	Text team_roster = Text{ Point{ 100,200 }, "Charles Wong Savannah Yu Cindy Zhang Eric Zhang" };
	Text instructions = Text{ Point{ 100,250 }, "Instructions:1. Do 2.Something" };
	Button show_instructions;// = Button{ Point{ 360 - 64,360 + 32 }, 128, 64, "Instuctions",  [](Address, Address pw) { reference_to<Splash_screen>(pw).instruct(); } };
	Button play_button;
	bool button_pushed;

	void play() {
		cout << "[next screen]" << endl;
		Fl::redraw();
	}
	void instruct() {
		cout << "[instructions]" << endl;
		Fl::redraw();
	}
};


int main() {
	try {
		Splash_screen splash(Point(0, 0), 720, 720, "Splash Screen");
		splash.wait_for_button();



	}
	catch (exception& e) {
		cerr << "error:" << e.what() << endl;
		keep_window_open();
		return 1;
	}
	catch (...) {
		cerr << "Oops, unknown exception!" << endl;
		keep_window_open();
		return 2;
	}
}