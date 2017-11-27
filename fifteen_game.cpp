#include "std_lib_facilities_5.h"
#include "Window.h"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"
#include "Simple_window.h"

struct Splash_screen : Graph_lib::Window {



	Splash_screen(Point xy, int w, int h, const string& title)
		:Window{ xy,w,h,title },
		quit_button{ Point{70,0}, 70, 20, "Quit",[](Address, Address pw) {reference_to<Splash_screen>(pw).quit();} },
		show_instructions{ Point{ 360 - 64,360 + 32 }, 128, 64, "Instuctions",  [](Address, Address pw) { reference_to<Splash_screen>(pw).instruct(); } },
		play_button{ Point{ 360 - 64,360 - 32 }, 128, 64, "Start",  [](Address, Address pw) { reference_to<Splash_screen>(pw).play(); } },
		button_pushed{ false },
		username(Point(x_max() - 310, 0), 70, 30, "Enter initial")
	{
		attach(play_button);
		attach(show_instructions);
		attach(game_name);
		attach(team_info);
		attach(team_roster);
		attach(instructions);
		attach(quit_button);
		attach(username);
	}

	void wait_for_button() {
		while (!button_pushed) {
			Fl::wait();
		}
		button_pushed = false;
		play();
	}


	void play() {
		cout << "[next screen]" << endl;
		cout << username.get_string() << endl;
		hide();
	}


	void quit()
	{
		hide();
	}

	void instruct() {
		cout << "[instructions]" << endl;


		Fl::redraw();
	}

private:
	Text game_name = Text{ Point{100,100}, "Fifteen Game" };
	Text team_info = Text{ Point{ 100,150 }, "Team 41: TeamName" };
	Text team_roster = Text{ Point{ 100,200 }, "Charles Wong Savannah Yu Cindy Zhang Eric Zhang" };
	Text instructions = Text{ Point{ 100,250 }, "Instructions:1. Do 2.Something" };
	Text leaderboard = Text{ Point{550,200}, "Leaderboard" };


	Text first = Text{ Point{550,250}, "1." };
	Text second = Text{ Point{550,300}, "2." };
	Text third = Text{ Point{550,350}, "3." };
	Text fourth = Text{ Point{550,400}, "4." };
	Text fifth = Text{ Point{550,450}, "5." };

	Button quit_button;
	Button show_instructions;
	Button play_button;

	In_box username;

	bool button_pushed;



	/*
	void ten_game() {
		cout << "[ten game]" << endl;
		detach(ten_button); //detach all buttons
		detach(twenty_button);
		detach(forty_button);
		detach(eighty_button);

		attach(difficulty_10);
		attach(leaderboard);
		attach(first);
		attach(second);
		attach(third);
		attach(fourth);
		attach(fifth);


		//	Vector_ref<Button> buttons;
		int numIndex = 0;
		for (int x = 100; x < 500; x += 100) {
			for (int y = 200; y < 600; y += 100) {
				if (numIndex == 10) {
					buttons.push_back(new Button{ Point(x,y), 100, 100, "", [](Address, Address pw) { reference_to<Splash_screen>(pw).instruct(); } });
				}
				else {
					buttons.push_back(new Button{ Point(x,y), 100, 100, to_string(numbers.at(numIndex)), [](Address, Address pw) { reference_to<Splash_screen>(pw).instruct(); } });
				}
				numIndex++;
				attach(buttons[buttons.size() - 1]);
			}
		}

		Fl::redraw();
	}*/

};

struct Level_select : Graph_lib::Window {

	Level_select(Point xy, int w, int h, const string& title)
		:Window{ xy,w,h,title },
		quit_button{ Point{ 70,0 }, 70, 20, "Quit",[](Address, Address pw) {reference_to<Level_select>(pw).quit();} },
		ten_button{ Point(200,50), 320, 100, "10", [](Address, Address pw) {reference_to<Level_select>(pw).start_game(10);} },
		twenty_button{ Point(200,150), 320, 100, "20", [](Address, Address pw) {reference_to<Level_select>(pw).start_game(20);} },
		forty_button{ Point(200,250), 320, 100, "40", [](Address, Address pw) {reference_to<Level_select>(pw).start_game(40);} },
		eighty_button{ Point(200,350), 320, 100, "80", [](Address, Address pw) {reference_to<Level_select>(pw).start_game(80);} }
	{
		attach(ten_button);
		attach(twenty_button);
		attach(forty_button);
		attach(eighty_button);
	}

	void wait_for_button() {
		while (!button_pushed) {
			Fl::wait();
		}
		button_pushed = false;
		//play();
	}

	void quit()
	{
		hide();
	}

	void start_game(int diff) {
		return;
	}
private:

	Button quit_button;
	Button ten_button;
	Button twenty_button;
	Button forty_button;
	Button eighty_button;

	Text difficulty_10 = Text{ Point{ 100,100 }, "Difficulty 10" };
	Text difficulty_20 = Text{ Point{ 100,100 }, "Difficulty 20" };
	Text difficulty_40 = Text{ Point{ 100,100 }, "Difficulty 40" };
	Text difficulty_80 = Text{ Point{ 100,100 }, "Difficulty 80" };

	bool button_pushed;

	/*vector<int> ten_nums = { 1, 5, 9, 13, 2, 6, 10, 14, 3, 12, 0, 8, 4, 7, 15, 11 };
	vector<int> twenty_nums = { 1, 5, 9, 13, 6, 0, 10, 15, 3, 2, 14, 12, 4, 11, 7, 8 };
	vector<int> forty_nums = { 6, 10, 9, 14, 5, 13, 15, 12, 11, 2, 7, 8, 4, 1, 3, 0 };
	vector<int> eighty_nums = { 0, 15, 3, 4, 12, 14, 7, 8, 11, 10, 6, 5, 13, 9, 2, 1 };*/
};




int main() {
	try {
		Splash_screen splash(Point(0, 0), 720, 720, "Splash Screen");
		return gui_main();


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