#include "lib/std_lib_facilities_5.h"
#include "lib/Window.h"
#include "lib/Graph.h"
#include "FL/Fl_JPEG_Image.H"
#include "lib/Simple_window.h"

#include "fifteen_game.h"




struct Splash_screen : public Project_window {
	Splash_screen(Point xy, int w, int h, const string& title)
		:Project_window{ xy,w,h,title },
		show_instructions{ Point{ 360 - 64,360 + 32 }, 128, 64, "Instuctions",  [](Address, Address pw) { reference_to<Splash_screen>(pw).set_state(Game_state(Instruct));} },
		play_button{ Point{ 360 - 64,360 - 32 }, 128, 64, "Start",  [](Address, Address pw) {  reference_to<Splash_screen>(pw).set_state(Game_state(Level)); } },
		name_entry{ In_box(Point(x_max() - 310, 0), 70, 30, "Enter initials") }
	{
		attach(play_button);
		attach(show_instructions);
		attach(game_name);
		attach(team_info);
		attach(team_roster);
		attach(name_entry);
	}

	string get_username() {
		return name_entry.get_string();
	}

private:
	Text game_name = Text{ Point{ 100,100 }, "Fifteen Game" };
	Text team_info = Text{ Point{ 100,150 }, "Team 41: TeamName" };
	Text team_roster = Text{ Point{ 100,200 }, "Charles Wong Savannah Yu Cindy Zhang Eric Zhang" };


	Button show_instructions;
	Button play_button;
	In_box name_entry;
};

struct Game_manager {

	Game_manager()
	:splash { Splash_screen(Point(0, 0), 720, 720, "Splash Screen")},
	instruct { Instruct_screen(Point(0, 0), 720, 720, "Instruct Screen")},
	level { Level_select(Point(0, 0), 720, 720, "Level Select", "username")},
	game { Game_screen(Point(0, 0), 720, 720, "Game Screen", 10, "username")},
	end { End_screen(Point(0, 0), 720, 720, "End Screen", 0, "username")}
	{
		instruct.hide();		
		level.hide();
		game.hide();
		end.hide();	
		current = splash.wait_for_button();
		username = splash.get_username();
		level.set_username(username);
		game.set_username(username);
		end.set_username(username);
		splash.hide();
	}
	void run() {
		while (current != Game_state(Quit)) {
			switch (current) {
			case (Game_state(Instruct)):
				instruct.show();
				current = instruct.wait_for_button();
				break;
			case (Game_state(Level)):
				level.show();
				current = level.wait_for_button();
				break;
			case (Game_state(Game_10)):
				game.show();
				game.set_difficulty(10);
				current = game.wait_for_button();
				break;
			case (Game_state(Game_20)):
				game.show();
				game.set_difficulty(20);
				current = game.wait_for_button();
				break;
			case (Game_state(Game_40)):
				game.show();
				game.set_difficulty(40);
				current = game.wait_for_button();
				break;
			case (Game_state(Game_80)):
				game.show();
				game.set_difficulty(80);
				current = game.wait_for_button();
				break;
			case (Game_state(End)):
				end.show();
				current = end.wait_for_button();
				break;
			case (Game_state(Quit)):
				return;
				break;
			default:
				cout << "Unexpected game state." << endl;
				cout << "Quitting..." << endl;
				return;
				break;
			}
		}
		return;
	}
private:
	int difficulty;
	Game_state current;
	string username;
	Splash_screen splash;
	Instruct_screen instruct;
	Level_select level;
	Game_screen game;
	End_screen end;
};

int main() {
	try {
		Game_manager game = Game_manager();
		game.run();
		//keep_window_open();
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