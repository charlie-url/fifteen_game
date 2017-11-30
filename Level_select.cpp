#include "Level_select.h"


	Level_select::Level_select(Point xy, int w, int h, const string& title, string user)
		:Project_window{ xy,w,h,title },
		ten_button{ Point(200,50), 320, 100, "10", [](Address, Address pw) { reference_to<Level_select>(pw).set_state(Game_state(Game_10));} },
		twenty_button{ Point(200,150), 320, 100, "20", [](Address, Address pw) {reference_to<Level_select>(pw).set_state(Game_state(Game_20)); } },
		forty_button{ Point(200,250), 320, 100, "40", [](Address, Address pw) {reference_to<Level_select>(pw).set_state(Game_state(Game_40)); } },
		eighty_button{ Point(200,350), 320, 100, "80", [](Address, Address pw) {reference_to<Level_select>(pw).set_state(Game_state(Game_80)); } }
	{
		attach(username);
		set_username(user);
		attach(ten_button);
		attach(twenty_button);
		attach(forty_button);
		attach(eighty_button);
		attach(username);
	}

