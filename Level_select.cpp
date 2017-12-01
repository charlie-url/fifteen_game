#include "Level_select.h"


	Level_select::Level_select(Point xy, int w, int h, const string& title, string user)
		:Project_window{ xy,w,h,title },
		ten_button{ Point(200,90+128), 320, 90, "Easy", [](Address, Address pw) { reference_to<Level_select>(pw).set_state(Game_state(Game_10));} },
		twenty_button{ Point(200,90+228), 320, 90, "Normal", [](Address, Address pw) {reference_to<Level_select>(pw).set_state(Game_state(Game_20)); } },
		forty_button{ Point(200,90+328), 320, 90, "Advanced", [](Address, Address pw) {reference_to<Level_select>(pw).set_state(Game_state(Game_40)); } },
		eighty_button{ Point(200,90+428), 320, 90, "Expert", [](Address, Address pw) {reference_to<Level_select>(pw).set_state(Game_state(Game_80)); } },
		choose_text{ Text{ Point{ 360 - (20 * 15) / 2,90 + 64 },"Choose a difficulty:" } }
	{
		//attach difficulty options to the screen
		attach(username);
		set_username(user);
		attach(ten_button);
		attach(twenty_button);
		attach(forty_button);
		attach(eighty_button);
		choose_text.set_font_size(32);
		attach(choose_text);

	}

