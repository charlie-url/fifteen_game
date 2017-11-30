#include "End_screen.h"

	End_screen::End_screen(Point xy, int w, int h, const string& title,string user)
		:Project_window{ xy,w,h,title },
		new_game_button{ Point{ 300, 300 }, 150, 100, "New Game",[](Address, Address pw) { reference_to<End_screen>(pw).set_state(Game_state(Level)); } }
	{
		score.set_label("Final Score: ");
		attach(score);
		set_username(user);
		attach(username);
		attach(new_game_button);
	}

	void End_screen::set_score(int final_score) {
		score.set_label("Final score: " + to_string(final_score));


	}