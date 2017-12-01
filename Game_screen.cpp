#include "Game_screen.h"

Game_screen::Game_screen(Point xy, int w, int h, const string& title, int difficulty, string user)
	:Project_window{ xy,w,h,title },
	difficulty{ difficulty },
	hint_button{ Point(360,10), 160, 100, "Hint", [](Address, Address pw) {reference_to<Game_screen>(pw).hint(); } },
	advice{ Point{ 360, 30 }, "A helpful hint if you click the button" }
{
	attach(leaderboard_username);
	set_username(user);
	score = 0;
	num_right = 0;
	moves_remain = difficulty;
	player_name = user;
	attach(leader_title);
	attach(first);
	attach(second);
	attach(third);
	attach(fourth);
	attach(fifth);
	attach(moves);
	attach(right);
	attach(hint_button);
	attach(advice);
	game_init();
}

void Game_screen::set_difficulty(int diff) {
	difficulty = diff;
	moves_remain = diff;
	load_values();
	order_tiles();
}
int Game_screen::get_score() {
	return score;
}

void Game_screen::pseudo_swap(int val) {
	//moves, but does not redraw or decrement counters
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
		if (abs(tiles[empty].y() - tiles[val].y()) == 1) {
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
		tiles[empty].pseudo_set_xy(tiles[val].x(), tiles[val].y());
		tiles[val].pseudo_set_xy(temp_x, temp_y);
		//cout << "\tinvisible move of tiles" << endl;
	}
}

int Game_screen::locate_tile(int x, int y) {
	//returns the location in the array of the tile at (x,y)
	for (int i = 0; i < tiles.size(); ++i) {
		if (tiles[i].x() == x && tiles[i].y() == y) {
			//cout << "tile found at location (" << x << ", " << y << ")" << endl;
			return i;
		}
	}
	cout << "error: tile at (" << x << "," << y << ") not found" << endl;
}

int Game_screen::locate_tile(int tile_number) {
	for (int i = 0; i < 16; ++i) {
		if (tiles[i].val() == tile_number) {
			//cout << "tile found at location " << i << endl;
			return i;
		}
	}
	cout << "error, tile " << tile_number << " not found" << endl;
}

void Game_screen::hint() {
	int empty = locate_tile(0);
	int empty_y = tiles[empty].y();
	int empty_x = tiles[empty].x();
	int min_error = 160;//more than possible on one board
	int curr_error = 0;//error of current layout
	vector<int> errors = { 0,0,0,0 };
	//case of upwards move (row 1 to 3)
	if (empty_y > 0) {
		curr_error = 0;
		pseudo_swap(locate_tile(empty_x, empty_y - 1));
		for (int i = 0; i < tiles.size(); ++i) {
			curr_error += tiles[i].manhattan();
		}
		min_error = min(min_error, curr_error);
		pseudo_swap(locate_tile(empty_x, empty_y));//reset board
		errors[0] = curr_error;
	}
	//case of downwards move
	if (empty_y < 3) {
		curr_error = 0;
		pseudo_swap(locate_tile(empty_x, empty_y + 1));
		for (int i = 0; i < tiles.size(); ++i) {
			curr_error += tiles[i].manhattan();
		}
		min_error = min(min_error, curr_error);
		pseudo_swap(locate_tile(empty_x, empty_y));//reset board
		errors[1] = curr_error;
	}
	//case of left move
	if (empty_x > 0) {
		curr_error = 0;
		pseudo_swap(locate_tile(empty_x - 1, empty_y));
		for (int i = 0; i < tiles.size(); ++i) {
			curr_error += tiles[i].manhattan();
		}
		min_error = min(min_error, curr_error);
		pseudo_swap(locate_tile(empty_x, empty_y));//reset board
		errors[2] = curr_error;
	}
	//case of right move
	if (empty_x < 3) {
		curr_error = 0;
		pseudo_swap(locate_tile(empty_x + 1, empty_y));
		for (int i = 0; i < tiles.size(); ++i) {
			curr_error += tiles[i].manhattan();
		}
		min_error = min(min_error, curr_error);
		pseudo_swap(locate_tile(empty_x, empty_y));//reset board
		errors[3] = curr_error;
	}
	//choose best moves
	vector<string> directions = { "Up","Down","Left","Right" };
	string good_advice = "";
	for (int i = 0; i < errors.size(); ++i) {
		if (errors[i] == min_error) {
			good_advice += directions[i] + " ";
		}
	}
	advice.set_label("Try one of these moves: " + good_advice);
	Fl::redraw();
}


void Game_screen::number_right() {
	num_right = 0;
	for (int i = 0; i < 16; ++i) {
		if (tiles[i].manhattan() != 0) {
			++num_right;
		}
	}
	right.set_label(to_string(num_right));
}

void Game_screen::update_highscores() {
	vector<player_score> new_scores = pulling_scores();
	first.set_label(new_scores[0].name + "  " + to_string(new_scores[0].score));
	second.set_label(new_scores[1].name + "  " + to_string(new_scores[1].score));
	third.set_label(new_scores[2].name + "  " + to_string(new_scores[2].score));
	fourth.set_label(new_scores[3].name + "  " + to_string(new_scores[3].score));
	fifth.set_label(new_scores[4].name + "  " + to_string(new_scores[4].score));
}


vector<player_score> Game_screen::pulling_scores() {
	vector<player_score> original_scores;
	ifstream Scores;
	switch (difficulty) {
	case 10:
		Scores.open("usr/Scores_list_10.txt");
		break;
	case 20:
		Scores.open("usr/Scores_list_20.txt");
		break;
	case 40:
		Scores.open("usr/Scores_list_40.txt");
		break;
	case 80:
		Scores.open("usr/Scores_list_80.txt");
		break;
	default:
		cout << "Error with selecting difficulty, cannot display scores" << endl;
	}
	if (Scores.fail()) {
		cerr << "Error Opening File" << endl;
		keep_window_open();
		exit(1);
	}

	player_score set_scores;
	while (Scores >> set_scores.name >> set_scores.score) {
		original_scores.push_back(set_scores);
	}
	Scores.close();//can put into a separate file later	

	return original_scores;

}

vector<string> Game_screen::leaderboard() {
	vector<string>top_5;

	for (int i = 0; i < 5; ++i) {
		string combined_name_score = pulling_scores()[i].name + "         " + to_string(pulling_scores()[i].score);
		top_5.push_back(combined_name_score);
	}

	return top_5;
}

void Game_screen::tile(int tile_num) {
	int place = 0;
	for (int i = 0; i < tiles.size(); ++i) {
		if (tiles[i].val() == tile_num) {
			place = i;
		}
	}

	cout << "The tile you clicked is " << tile_num;
	cout << " (" << tiles[place].y() << "," << tiles[place].x() << ")" << endl;
	cout << "Manhattan: " << tiles[place].manhattan() << endl;
	swap(place);
}


void Game_screen::final_scores_list(int final_score) {
	string player_name = username.lab;
	vector<player_score>sort_scores = pulling_scores();

	player_score set_player_info;
	set_player_info.name = player_name;
	set_player_info.score = final_score;


	sort_scores.push_back(set_player_info);
	sort(sort_scores.begin(), sort_scores.end());

	ofstream new_score_list;
	switch (difficulty) {
	case 10:
		new_score_list.open("usr/Scores_list_10.txt");
		break;
	case 20:
		new_score_list.open("usr/Scores_list_20.txt");
		break;
	case 40:
		new_score_list.open("usr/Scores_list_40.txt");
		break;
	case 80:
		new_score_list.open("usr/Scores_list_80.txt");
		break;
	default:
		cout << "Error with selecting difficulty, cannot display scores" << endl;
	}
	if (new_score_list.fail()) {
		cerr << "Error Opening File" << endl;
		keep_window_open();
		exit(1);
	}
	//cout << "what is entered into the txt file: " << endl;
	for (int i = sort_scores.size() - 1; i >= 0; --i) {
		new_score_list << sort_scores[i].name << " " << sort_scores[i].score << endl << endl;
		//cout << sort_scores[i].name << "   " << sort_scores[i].score << endl;
	}

	//writes the new list of player names and the scores into the file
	new_score_list.close();
	//closes the file 
}

void Game_screen::check_game_over() {
	if (moves_remain == 0) {
		final_scores_list(score);
		state = Game_state(End);
		button_pushed = true;
	}
}

void Game_screen::swap(int val) {
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
		if (abs(tiles[empty].y() - tiles[val].y()) == 1) {
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
		--moves_remain;
		moves.set_label(to_string(moves_remain));
		score = difficulty * (16 - num_right);
		if (tiles[val].manhattan() == 0) {
			attach(tiles[val].green_tile);
			detach(tiles[val].red_tile);
		}
		else{
			attach(tiles[val].red_tile);
			detach(tiles[val].green_tile);
		}
		detach(tiles[val].tile_label);
		attach(tiles[val].tile_label);
		check_game_over();
	}
	number_right();
}


void Game_screen::load_values() {

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

void Game_screen::order_tiles() {
	for (int i = 0; i < tiles.size(); i++) {
		detach(tiles[i]);
	}
	tiles = Vector_ref<Tile_button>{};
	for (int i = 0; i < tile_bag.size(); i++) {
		detach(tile_bag[i]);
		tiles.push_back(tile_bag[numbers.at(i)]);//puts tiles in the correct order
		tiles[i].set_x(i / 4);
		tiles[i].set_y(i % 4);
		attach(tiles[i]);
		if (tiles[i].manhattan()==0) {
			attach(tiles[i].green_tile);
			detach(tiles[i].red_tile);
		}
		else{
			attach(tiles[i].red_tile);
			detach(tiles[i].green_tile);
		}
		if (tiles[i].val() == 0) {
			detach(tiles[i].green_tile);
			detach(tiles[i].red_tile);
			attach(tiles[i].blank_tile);
		}
		attach(tiles[i].tile_label);
	}
	Fl::redraw();
}

void Game_screen::game_init() {
	load_values();
	tile_bag.push_back(new Tile_button{ 0,0,0,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(0); } });
	tile_bag.push_back(new Tile_button{ 0,0,1,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(1); } });
	tile_bag.push_back(new Tile_button{ 0,0,2,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(2); } });
	tile_bag.push_back(new Tile_button{ 0,0,3,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(3); } });
	tile_bag.push_back(new Tile_button{ 0,0,4,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(4); } });
	tile_bag.push_back(new Tile_button{ 0,0,5,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(5); } });
	tile_bag.push_back(new Tile_button{ 0,0,6,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(6); } });
	tile_bag.push_back(new Tile_button{ 0,0,7,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(7); } });
	tile_bag.push_back(new Tile_button{ 0,0,8,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(8); } });
	tile_bag.push_back(new Tile_button{ 0,0,9,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(9); } });
	tile_bag.push_back(new Tile_button{ 0,0,10,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(10); } });
	tile_bag.push_back(new Tile_button{ 0,0,11,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(11); } });
	tile_bag.push_back(new Tile_button{ 0,0,12,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(12); } });
	tile_bag.push_back(new Tile_button{ 0,0,13,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(13); } });
	tile_bag.push_back(new Tile_button{ 0,0,14,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(14); } });
	tile_bag.push_back(new Tile_button{ 0,0,15,[](Address,Address pw) {reference_to<Game_screen>(pw).tile(15); } });
	for (int i = 0; i < tile_bag.size(); ++i) {
		attach(tile_bag[i]);
	}
	order_tiles();

}
