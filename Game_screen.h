#ifndef GAME_SCREEN_GUARD
#define GAME_SCREEN_GUARD



#include "Tile_button.h"
#include "Project_window.h"
#include "Player_score.h"

//Create the screen which the game is played on as well as the actual game itself

struct Game_screen : public Project_window {

	Game_screen(Point xy, int w, int h, const string& title, int difficulty, string user); //Constructor for the game window

	void set_difficulty(int diff); //Load up the correct tiles for the difficulty chosen
	int get_score();
	void pseudo_swap(int val); //false swap function that emulates a tile movement for calculating the manhattan distance
	int locate_tile(int x, int y);
	int locate_tile(int tile_number);
	void hint(); //Recommend a move to the player based on manhattan distance
	void number_right(); //The number of tiles in the incorrect position. Slightly misleading function name.
	void update_highscores();
	string player_name;
	vector<player_score> pulling_scores(); //Vector of player scores of the leaderboard
	vector<string> leaderboard();
	void tile(int tile_num);
	void final_scores_list(int final_score);
	void check_game_over(); //Check if counter is zero
	void swap(int val); //switches positions between tiles
	void load_values(); 
	void order_tiles(); //Puts the tiles in the correct place on the game window
	void game_init(); //Game initializer

private:
	int score;
	int moves_remain;
	int difficulty;
	int num_right;
	Vector_ref<Tile_button> tile_bag;
	Vector_ref<Tile_button> tiles;

	//The order of numbers on the tiles for different difficulty levels
	vector<int> numbers;
	vector<int> ten_nums = { 1, 5, 9, 13, 2, 6, 10, 14, 3, 12, 0, 8, 4, 7, 15, 11 };
	vector<int> twenty_nums = { 1, 5, 9, 13, 6, 0, 10, 15, 3, 2, 14, 12, 4, 11, 7, 8 };
	vector<int> forty_nums = { 6, 10, 9, 14, 5, 13, 15, 12, 11, 2, 7, 8, 4, 1, 3, 0 };
	vector<int> eighty_nums = { 0, 15, 3, 4, 12, 14, 7, 8, 11, 10, 6, 5, 13, 9, 2, 1 };

	Button hint_button;
	Text advice;
	Text moves = Text{ Point{ 240,90+24+48 }, to_string(difficulty) };
	Text right = Text{ Point{ 480, 90+24+48 }, "##" }; //number of tiles in the correct position
	Text leader_title = Text{ Point{ 720-120-(5*12),90+128+64 }, "Leaderboard" };
	Text first = Text{ Point{ 720-120-(5*12)-20,90+128+64+50 }, leaderboard()[0] };
	Text second = Text{ Point{ 720-120-(5*12)-20,90+128+64+100}, leaderboard()[1] };
	Text third = Text{ Point{ 720-120-(5*12)-20,90+128+64+150}, leaderboard()[2] };
	Text fourth = Text{ Point{ 720-120-(5*12)-20,90+128+64+200 }, leaderboard()[3] };
	Text fifth = Text{ Point{ 720-120-(5*12)-20,90+128+64+250 }, leaderboard()[4] };
	Text move_disp = Text{ Point{ 240-(5*18)/2, 90+24+48-14 }, "Moves Remaining" };
	Text right_disp = Text{ Point{ 480-(5*25)/2, 90+24+48-14 }, "Tiles Placed Correctly" };
};






#endif // !GAME_SCREEN_GUARD

