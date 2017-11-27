#include "std_lib_facilities_5.h"
#include "Window.h"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"
#include "Simple_window.h"

struct Game_screen : Graph_lib::Window {

	Game_screen(Point xy, int w, int h, const string& title, int difficulty)
		:Window{ xy,w,h,title },
		quit_button{ Point{ 70,0 }, 70, 20, "Quit",[](Address, Address pw) {reference_to<Game_screen>(pw).quit();} },
		difficulty{ difficulty },
		button_pushed{ false }
	{
		attach(quit_button);
		game_init();
	}

	void wait_for_button() {
		while (!button_pushed) {
			Fl::wait();
		}
		button_pushed = false;
	}

	void quit() {
		button_pushed = true;
		make_current();
		hide();
	}



	void game_init() {
		cout << "[game]" << endl;

		attach(leaderboard);
		attach(first);
		attach(second);
		attach(third);
		attach(fourth);
		attach(fifth);

		switch (difficulty) {
		case 10: numbers = ten_nums;
			break;
		case 20: numbers = twenty_nums;
			break;
		case 40: numbers = forty_nums;
			break;
		case 80: numbers = eighty_nums;
			break;
		default: cout << "error in choosing difficulty";
			break;
		}

		int numIndex = 0;
		for (int x = 100; x < 500; x += 100) {
			for (int y = 200; y < 600; y += 100) {
				if (numIndex == 10) {
					buttons.push_back(new Button{ Point(x,y), 100, 100, "", [](Address, Address pw) { reference_to<Game_screen>(pw).tile(); } });
				}
				else {
					buttons.push_back(new Button{ Point(x,y), 100, 100, to_string(numbers.at(numIndex)), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(); } });
				}
				numIndex++;
				attach(buttons[buttons.size() - 1]);
			}
		}

		Fl::redraw();
	}

	void tile() {
		cout << "[tile]" << endl;
	}
private:
	Button quit_button;
	int difficulty;
	bool button_pushed;
	Vector_ref<Button> buttons;
	vector<int> numbers;
	vector<int> ten_nums = { 1, 5, 9, 13, 2, 6, 10, 14, 3, 12, 0, 8, 4, 7, 15, 11 };
	vector<int> twenty_nums = { 1, 5, 9, 13, 6, 0, 10, 15, 3, 2, 14, 12, 4, 11, 7, 8 };
	vector<int> forty_nums = { 6, 10, 9, 14, 5, 13, 15, 12, 11, 2, 7, 8, 4, 1, 3, 0 };
	vector<int> eighty_nums = { 0, 15, 3, 4, 12, 14, 7, 8, 11, 10, 6, 5, 13, 9, 2, 1 };

	Text leaderboard = Text{ Point{ 550,200 }, "Leaderboard" };
	Text first = Text{ Point{ 550,250 }, "1." };
	Text second = Text{ Point{ 550,300 }, "2." };
	Text third = Text{ Point{ 550,350 }, "3." };
	Text fourth = Text{ Point{ 550,400 }, "4." };
	Text fifth = Text{ Point{ 550,450 }, "5." };
};

struct Level_select : Graph_lib::Window {

	Level_select(Point xy, int w, int h, const string& title, string name)
		:Window{ xy,w,h,title },
		quit_button{ Point{ 70,0 }, 70, 20, "Quit",[](Address, Address pw) {reference_to<Level_select>(pw).quit();} },
		ten_button{ Point(200,50), 320, 100, "10", [](Address, Address pw) {reference_to<Level_select>(pw).start_game(10);} },
		twenty_button{ Point(200,150), 320, 100, "20", [](Address, Address pw) {reference_to<Level_select>(pw).start_game(20);} },
		forty_button{ Point(200,250), 320, 100, "40", [](Address, Address pw) {reference_to<Level_select>(pw).start_game(40);} },
		eighty_button{ Point(200,350), 320, 100, "80", [](Address, Address pw) {reference_to<Level_select>(pw).start_game(80);} },
		button_pushed{ false },
		username{ Point{360,10},name }
	{
		attach(quit_button);
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
	}

	void quit()
	{
		button_pushed = true;
		make_current();
		hide();
	}

	void start_game(int diff) {
		button_pushed = true;
		cout << "[game screen]" << endl;
		cout << diff << endl;
		quit();
		Game_screen game(Point(0, 0), 720, 720, "Game Screen", diff);
		game.wait_for_button();
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

	Text username;

	bool button_pushed;


};


struct Splash_screen : Graph_lib::Window {



	Splash_screen(Point xy, int w, int h, const string& title)
		:Window{ xy,w,h,title },
		quit_button{ Point{70,0}, 70, 20, "Quit",[](Address, Address pw) {reference_to<Splash_screen>(pw).quit();} },
		show_instructions{ Point{ 360 - 64,360 + 32 }, 128, 64, "Instuctions",  [](Address, Address pw) { reference_to<Splash_screen>(pw).instruct(); } },
		play_button{ Point{ 360 - 64,360 - 32 }, 128, 64, "Start",  [](Address, Address pw) { reference_to<Splash_screen>(pw).view_levels(); } },
		button_pushed{ false },
		username(Point(x_max() - 310, 0), 70, 30, "Enter initial")
	{
		attach(play_button);
		attach(show_instructions);
		attach(game_name);
		attach(team_info);
		attach(team_roster);
		attach(quit_button);
		attach(username);
	}

	void wait_for_button() {
		while (!button_pushed) {
			Fl::wait();
		}
		button_pushed = false;
	}


	void view_levels() {
		cout << "[level screen]" << endl;
		cout << username.get_string() << endl;
		quit();
		Level_select levels(Point(0, 0), 720, 720, "Level Select", username.get_string());
		levels.wait_for_button();
	}


	void quit()
	{
		button_pushed = true;
		make_current();
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

	Button quit_button;
	Button show_instructions;
	Button play_button;

	In_box username;

	bool button_pushed;

};




int main() {
	try {
		Splash_screen splash(Point(0, 0), 720, 720, "Splash Screen");
		splash.wait_for_button();
		return 0;

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