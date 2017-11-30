#ifndef GAME_SCREEN_GUARD
#define GAME_SCREEN_GUARD



#include "Tile_button.h"
#include "Project_window.h"
#include "Player_score.h"

struct Game_screen : public Project_window {

	Game_screen(Point xy, int w, int h, const string& title, int difficulty, string user);

	void set_difficulty(int diff);
	int get_score();
	void pseudo_swap(int val);
	int locate_tile(int x, int y);
	int locate_tile(int tile_number);
	void hint();
	void number_right();
	vector<player_score> pulling_scores();
	vector<string> leaderboard();
	void tile(int tile_num);
	void final_scores_list(int final_score);
	void check_game_over();
	void swap(int val);
	void load_values();
	void order_tiles();
	void game_init();

private:
	int score;
	int moves_remain;
	int difficulty;
	int num_right;
	Vector_ref<Tile_button> tile_bag;
	Vector_ref<Tile_button> tiles;

	vector<int> numbers;
	vector<int> ten_nums = { 1, 5, 9, 13, 2, 6, 10, 14, 3, 12, 0, 8, 4, 7, 15, 11 };
	vector<int> twenty_nums = { 1, 5, 9, 13, 6, 0, 10, 15, 3, 2, 14, 12, 4, 11, 7, 8 };
	vector<int> forty_nums = { 6, 10, 9, 14, 5, 13, 15, 12, 11, 2, 7, 8, 4, 1, 3, 0 };
	vector<int> eighty_nums = { 0, 15, 3, 4, 12, 14, 7, 8, 11, 10, 6, 5, 13, 9, 2, 1 };

	Button hint_button;
	Text advice;
	Text moves = Text{ Point{ 360,128 }, to_string(difficulty) };
	Text right = Text{ Point{ 360, 148 }, "##" };
	Text leader_title = Text{ Point{ 550,200 }, "Leaderboard" };
	Text first = Text{ Point{ 550,250 }, leaderboard()[0] };
	Text second = Text{ Point{ 550,300 }, leaderboard()[1] };
	Text third = Text{ Point{ 550,350 }, leaderboard()[2] };
	Text fourth = Text{ Point{ 550,400 }, leaderboard()[3] };
	Text fifth = Text{ Point{ 550,450 }, leaderboard()[4] };
};






#endif // !GAME_SCREEN_GUARD

