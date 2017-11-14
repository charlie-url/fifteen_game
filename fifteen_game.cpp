#include "std_lib_facilities_5.h"
#include "Window.h"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"
#include "Simple_window.h"

struct Splash_screen : Graph_lib::Window {
	Splash_screen(Point xy, int w, int h, const string& title)
		:Window{ xy,w,h,title },
		show_instructions{ Point{ 360 - 64,360 + 32 }, 128, 64, "Instuctions",  [](Address, Address pw) { reference_to<Splash_screen>(pw).instruct(); } },
		play_button{ Point{ 360 - 64,360 - 32 }, 128, 64, "Start",  [](Address, Address pw) { reference_to<Splash_screen>(pw).play(); } },
		ten_button {Point(200,50), 320, 100, "10", [](Address, Address pw) {reference_to<Splash_screen>(pw).ten_game();} },
		twenty_button {Point(200,150), 320, 100, "20", [](Address, Address pw) {reference_to<Splash_screen>(pw).twenty_game();} },
		forty_button {Point(200,250), 320, 100, "40", [](Address, Address pw) {reference_to<Splash_screen>(pw).forty_game();} },
		eighty_button {Point(200,350), 320, 100, "80", [](Address, Address pw) {reference_to<Splash_screen>(pw).eighty_game();} },
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
	Text leaderboard = Text { Point{550,200}, "Leaderboard"};
	Text difficulty_10 = Text{ Point{100,100}, "Difficulty 10"};
	Text difficulty_20 = Text{ Point{100,100}, "Difficulty 20"};
	Text difficulty_40 = Text{ Point{100,100}, "Difficulty 40"};
	Text difficulty_80 = Text{ Point{100,100}, "Difficulty 80"};
	Text first = Text{Point{550,250}, "1."};
	Text second = Text{Point{550,300}, "2."};
	Text third = Text{Point{550,350}, "3."};
	Text fourth = Text{Point{550,400}, "4."};
	Text fifth = Text{Point{550,450}, "5."};
	Button show_instructions;// = Button{ Point{ 360 - 64,360 + 32 }, 128, 64, "Instuctions",  [](Address, Address pw) { reference_to<Splash_screen>(pw).instruct(); } };
	Button play_button;
	Button ten_button;
	Button twenty_button;
	Button forty_button;
	Button eighty_button;
	bool button_pushed;

	void play() {
		cout << "[next screen]" << endl;
		
		detach(play_button);	//probably a better way to do this honestly like a clear() function?
		detach(show_instructions);
		detach(game_name);
		detach(team_info);
		detach(team_roster);
		detach(instructions);

		attach(ten_button);
		attach(twenty_button);
		attach(forty_button);
		attach(eighty_button);
		Fl::redraw();
	}
	void instruct() {
		cout << "[instructions]" << endl;
		Fl::redraw();
	}
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
<<<<<<< HEAD
		vector<int> numbers = {0, 15, 3, 4, 12, 14, 7, 8, 11, 10, 6, 5, 13, 9, 2, 1};

		Vector_ref<Button> buttons;
		int numIndex = 0;
		for(int x = 100; x < 500; x+=100) {
			for(int y = 200; y < 600; y+=100) {
<<<<<<< HEAD
				if(numIndex == 0) {
					buttons.push_back(new Button {Point(x,y), 100, 100, "", [](Address, Address pw) { reference_to<Splash_screen>(pw).instruct(); }});
				} else {
					buttons.push_back(new Button {Point(x,y), 100, 100, to_string(numbers.at(numIndex)), [](Address, Address pw) { reference_to<Splash_screen>(pw).instruct(); }});
				}
				numIndex++;
				attach(buttons[buttons.size()-1]);
			}
		}

		Fl::redraw();
	}
	void twenty_game() {
		cout << "[twenty game]" << endl;
		detach(ten_button); //detach all buttons
		detach(twenty_button);
		detach(forty_button);
		detach(eighty_button);

		attach(difficulty_20);
		attach(leaderboard);
		attach(first);
		attach(second);
		attach(third);
		attach(fourth);
		attach(fifth);
<<<<<<< HEAD
		vector<int> numbers = {2, 10, 0, 6, 5, 7, 13, 9, 1, 3, 11, 14, 4, 8, 12, 15};

		Vector_ref<Button> buttons;
		int numIndex = 0;
		for(int x = 100; x < 500; x+=100) {
			for(int y = 200; y < 600; y+=100) {
<<<<<<< HEAD
				if(numIndex == 2) {
					buttons.push_back(new Button {Point(x,y), 100, 100, "", [](Address, Address pw) { reference_to<Splash_screen>(pw).instruct(); }});
				} else {
					buttons.push_back(new Button {Point(x,y), 100, 100, to_string(numbers.at(numIndex)), [](Address, Address pw) { reference_to<Splash_screen>(pw).instruct(); }});
				}
				numIndex++;
				attach(buttons[buttons.size()-1]);
			}
		}

		Fl::redraw();
	}
	void forty_game() {
		cout << "[forty game]" << endl;
		detach(ten_button); //detach all buttons
		detach(twenty_button);
		detach(forty_button);
		detach(eighty_button);

		attach(difficulty_40);
		attach(leaderboard);
		attach(first);
		attach(second);
		attach(third);
		attach(fourth);
		attach(fifth);
		vector<int> numbers = {6, 10, 9, 14, 5, 13, 15, 12, 11, 2, 7, 8, 4, 1, 3, 0};

		Vector_ref<Button> buttons;
		int numIndex = 0;
		for(int x = 100; x < 500; x+=100) {
			for(int y = 200; y < 600; y+=100) {
				if(numIndex == 15) {
					buttons.push_back(new Button {Point(x,y), 100, 100, "", [](Address, Address pw) { reference_to<Splash_screen>(pw).instruct(); }});
				} else {
					buttons.push_back(new Button {Point(x,y), 100, 100, to_string(numbers.at(numIndex)), [](Address, Address pw) { reference_to<Splash_screen>(pw).instruct(); }});
				}
				numIndex++;
				attach(buttons[buttons.size()-1]);
			}
		}

		Fl::redraw();
	}
	void eighty_game() {
		cout << "[eighty game]" << endl;
		detach(ten_button); //detach all buttons
		detach(twenty_button);
		detach(forty_button);
		detach(eighty_button);

		attach(difficulty_80);
		attach(leaderboard);
		attach(first);
		attach(second);
		attach(third);
		attach(fourth);
		attach(fifth);
		vector<int> numbers = {0, 15, 3, 4, 12, 14, 7, 8, 11, 10, 6, 5, 13, 9, 2, 1};

		Vector_ref<Button> buttons;
		int numIndex = 0;
		for(int x = 100; x < 500; x+=100) {
			for(int y = 200; y < 600; y+=100) {
				if(numIndex == 0) {
					buttons.push_back(new Button {Point(x,y), 100, 100, "", [](Address, Address pw) { reference_to<Splash_screen>(pw).instruct(); }});
				} else {
					buttons.push_back(new Button {Point(x,y), 100, 100, to_string(numbers.at(numIndex)), [](Address, Address pw) { reference_to<Splash_screen>(pw).instruct(); }});
				}
				numIndex++;
				attach(buttons[buttons.size()-1]);
			}
		}

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