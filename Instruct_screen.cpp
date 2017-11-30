#include "Instruct_screen.h"



	Instruct_screen::Instruct_screen(Point xy, int w, int h, const string& title)
		:Project_window{ xy,w,h,title },
		go_to_levels{ Point{ 360 - 64,360 + 64 }, 128, 64, "Play",  [](Address, Address pw) { reference_to<Instruct_screen>(pw).set_state(Game_state(Level)); } }
	{
		attach(instruct1);
		attach(instruct2);
		attach(go_to_levels);
		how_to_play.set_font_size(64);
		attach(how_to_play);
	}

