#include "End_screen.h"

	End_screen::End_screen(Point xy, int w, int h, const string& title,string user)
		:Project_window{ xy,w,h,title },
		new_game_button{ Point{360-100,720-90-120}, 200, 40, "Run another round.",[](Address, Address pw) { reference_to<End_screen>(pw).set_state(Game_state(Level)); } }
	{
		//display final score to user and give player option to play again
		score.set_font_size(24);
		attach(score);
		attach(username);
		set_username(user);
		username.set_font_size(24);
		username.move(64,-360);
		attach(new_game_button);
	}

	void End_screen::set_score(int final_score) {
		score.set_label("Final score: " + to_string(final_score));
	}