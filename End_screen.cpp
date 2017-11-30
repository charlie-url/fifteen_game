#include "End_screen.h"

	End_screen::End_screen(Point xy, int w, int h, const string& title, int final_player_score, string user)
		:Project_window{ xy,w,h,title },
		new_game_button{ Point{ 150,70 }, 70, 70, "New Game",[](Address, Address pw) { reference_to<End_screen>(pw).set_state(Game_state(Level)); } },
		final_player_score{ final_player_score }
	{
		cout << final_player_score << endl;
		score.set_label("Final Score: " + to_string(final_player_score));
		attach(username);
		attach(score);
		set_username(user);
		attach(new_game_button);
	}

