#ifndef END_SCREEN_GUARD
#define END_SCREEN_GUARD 1


#include "Project_window.h"
struct End_screen : public Project_window {


	End_screen(Point xy, int w, int h, const string& title, string user);

	void set_score(int final_score);

private:
	Button new_game_button;
	Text score = Text{ Point{ 100,100 }, "FinalScore"};
};







#endif // !END_SCREEN_GUARD

