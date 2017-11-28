#include "lib/std_lib_facilities_5.h"
#include "lib/Window.h"
#include "lib/Graph.h"
#include "FL/Fl_JPEG_Image.H"
#include "lib/Simple_window.h"

struct Tile_button : public Button {
	Tile_button(int x_coord, int y_coord, int number, Callback cb)
		:Button{ Point(100 + (100 * x_coord),200 + (100 * y_coord)),100, 100, to_string(number), cb},
		x_coord{x_coord},
		y_coord{y_coord},
			number{number}
	{}

	int x() {
		return x_coord;
	}

	int y() {
		return y_coord;
	}
	int val() {
		return number;
	}
	void set_x(int x) {
		
		move(100*(x-x_coord),0);
		x_coord = x;
		Fl::redraw();
	}

	void set_y(int y) {
		move(0,100 * (y-y_coord));
		y_coord = y;
		Fl::redraw();
	}
	int manhattan() {
		//do: calculate position from value
		int ideal_x = (number-1) % 4;
		int ideal_y = (number-1) / 4;
		if(number==0){//blank in bottom right
			ideal_x = 3;
			ideal_y = 3;
		}
		int dy = abs(y_coord - ideal_y);
		int dx = abs(x_coord - ideal_x);
		return (dx+dy);
	}


private:
	int x_coord;
	int y_coord;
	int number;
};

struct Project_window : Graph_lib::Window {

	Project_window(Point xy, int w, int h, const string& title)
		:Window{ xy,w,h,title },
		quit_button{ Point{ 70,0 }, 70, 20, "Quit",[](Address, Address pw) {reference_to<Project_window>(pw).quit();} },
		button_pushed{ false }
	{
		attach(quit_button);
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

	Button quit_button;
	bool button_pushed;
};

struct Game_screen : public Project_window {

	Game_screen(Point xy, int w, int h, const string& title, int difficulty)
		:Project_window{ xy,w,h,title },
		difficulty{ difficulty }
	{
		attach(leaderboard);
		attach(first);
		attach(second);
		attach(third);
		attach(fourth);
		attach(fifth);
		game_init();
	}



	void tile(int tile_num) {
		int place = 0;
		for(int i = 0; i < tiles.size();++i){
			if(tiles[i].val() == tile_num){
				place = i;
			}
		} 

		cout << "The tile you clicked is " << tile_num << endl;
		cout << "Its row is " << tiles[place].y() << endl;
		cout << "Its col is " << tiles[place].x() << endl;
		cout << "Manhattan distance is " << tiles[place].manhattan() << endl;
		swap(place);
	}

	void swap(int val) {
		int empty = 0;//location of empty tile
		int temp_x = 0;
		int temp_y = 0;
		bool valid_swap = false;
		for (int i = 0; i < 16; ++i) {
			if (tiles[i].val() == 0) {
				empty = i;
			}
		}
		if (tiles[empty].x() == tiles[val].x()) {
			if (abs(tiles[empty].y() - tiles[val].y())==1) {
				valid_swap = true;
			}
		}
		if (tiles[empty].y() == tiles[val].y()) {
			if (abs(tiles[empty].x() - tiles[val].x()) == 1) {
				valid_swap = true;
			}
		}
		if (valid_swap) {
			temp_x = tiles[empty].x();
			temp_y = tiles[empty].y();
			tiles[empty].set_x(tiles[val].x());
			tiles[empty].set_y(tiles[val].y());
			tiles[val].set_x(temp_x);
			tiles[val].set_y(temp_y);
		}
	}


	void load_values() {

		switch (difficulty) {//populate vector<int> numbers
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
	}

	void game_init(){
		load_values();
		tile_bag.push_back(new Tile_button{ 0,0,0,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(0);} });
		tile_bag.push_back(new Tile_button{ 0,0,1,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(1);} });
		tile_bag.push_back(new Tile_button{ 0,0,2,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(2);} });
		tile_bag.push_back(new Tile_button{ 0,0,3,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(3);} });
		tile_bag.push_back(new Tile_button{ 0,0,4,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(4);} });
		tile_bag.push_back(new Tile_button{ 0,0,5,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(5);} });
		tile_bag.push_back(new Tile_button{ 0,0,6,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(6);} });
		tile_bag.push_back(new Tile_button{ 0,0,7,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(7);} });
		tile_bag.push_back(new Tile_button{ 0,0,8,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(8);} });
		tile_bag.push_back(new Tile_button{ 0,0,9,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(9);} });
		tile_bag.push_back(new Tile_button{ 0,0,10,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(10);} });
		tile_bag.push_back(new Tile_button{ 0,0,11,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(11);} });
		tile_bag.push_back(new Tile_button{ 0,0,12,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(12);} });
		tile_bag.push_back(new Tile_button{ 0,0,13,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(13);} });
		tile_bag.push_back(new Tile_button{ 0,0,14,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(14);} });
		tile_bag.push_back(new Tile_button{ 0,0,15,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(15);} });
		for (int i = 0; i < tile_bag.size(); ++i) {
			attach(tile_bag[i]);
		}
		cout << "done" << endl;
		for (int i = 0; i < tile_bag.size(); i++) {
			detach(tile_bag[i]);
			tiles.push_back(tile_bag[numbers.at(i)]);//puts tiles in the correct order
			tiles[i].set_x(i % 4);
			tiles[i].set_y(i / 4);
			attach(tiles[i]);
		}
	}

private:

	int difficulty;
	Vector_ref<Tile_button> tile_bag;
	Vector_ref<Tile_button> tiles;
	
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

struct Level_select : public Project_window {

	Level_select(Point xy, int w, int h, const string& title, string name)
		:Project_window{ xy,w,h,title },
		ten_button{ Point(200,50), 320, 100, "10", [](Address, Address pw) {reference_to<Level_select>(pw).start_game(10);} },
		twenty_button{ Point(200,150), 320, 100, "20", [](Address, Address pw) {reference_to<Level_select>(pw).start_game(20);} },
		forty_button{ Point(200,250), 320, 100, "40", [](Address, Address pw) {reference_to<Level_select>(pw).start_game(40);} },
		eighty_button{ Point(200,350), 320, 100, "80", [](Address, Address pw) {reference_to<Level_select>(pw).start_game(80);} },
		username{ Point{360,10},name }
	{
		attach(ten_button);
		attach(twenty_button);
		attach(forty_button);
		attach(eighty_button);
		attach(username);
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

	Button ten_button;
	Button twenty_button;
	Button forty_button;
	Button eighty_button;

	Text difficulty_10 = Text{ Point{ 100,100 }, "Difficulty 10" };
	Text difficulty_20 = Text{ Point{ 100,100 }, "Difficulty 20" };
	Text difficulty_40 = Text{ Point{ 100,100 }, "Difficulty 40" };
	Text difficulty_80 = Text{ Point{ 100,100 }, "Difficulty 80" };

	Text username;

};

struct Splash_screen : public Project_window {



	Splash_screen(Point xy, int w, int h, const string& title)
		:Project_window{ xy,w,h,title },
		
		show_instructions{ Point{ 360 - 64,360 + 32 }, 128, 64, "Instuctions",  [](Address, Address pw) { reference_to<Splash_screen>(pw).instruct(); } },
		play_button{ Point{ 360 - 64,360 - 32 }, 128, 64, "Start",  [](Address, Address pw) { reference_to<Splash_screen>(pw).view_levels(); } },
		username(Point(x_max() - 310, 0), 70, 30, "Enter initial")
	{
		attach(play_button);
		attach(show_instructions);
		attach(game_name);
		attach(team_info);
		attach(team_roster);
		attach(username);
	}



	void view_levels() {
		cout << "[level screen]" << endl;
		cout << username.get_string() << endl;
		quit();
		Level_select levels(Point(0, 0), 720, 720, "Level Select", username.get_string());
		levels.wait_for_button();
	}



	void instruct() {
		cout << "[instructions]" << endl;

		Fl::redraw();
	}

private:
	Text game_name = Text{ Point{100,100}, "Fifteen Game" };
	Text team_info = Text{ Point{ 100,150 }, "Team 41: TeamName" };
	Text team_roster = Text{ Point{ 100,200 }, "Charles Wong Savannah Yu Cindy Zhang Eric Zhang" };

	Button show_instructions;
	Button play_button;
	In_box username;



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