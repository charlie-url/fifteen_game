#ifndef END_SCREEN_GUARD
#define END_SCREEN_GUARD 1


#include "Project_window.h"
struct End_screen : public Project_window {


	End_screen(Point xy, int w, int h, const string& title, int final_player_score, string user);


private:
	Button new_game_button;
	string text_score;
	Text score = Text{ Point{ 100,100 }, text_score };
	int final_player_score;
};







#endif // !END_SCREEN_GUARD

