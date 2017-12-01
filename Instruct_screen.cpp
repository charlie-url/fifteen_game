#include "Instruct_screen.h"



	Instruct_screen::Instruct_screen(Point xy, int w, int h, const string& title)
		:Project_window{ xy,w,h,title },
		go_to_levels{ Point{ 360 - 64,360 - 32 }, 128, 64, "Start",  [](Address, Address pw) { reference_to<Instruct_screen>(pw).set_state(Game_state(Level)); } }
	{
		//attach instructions and a play button
		attach(instruct1);
		attach(instruct2);
		attach(go_to_levels);
	}

