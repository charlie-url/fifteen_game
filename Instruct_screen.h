#ifndef INSTRUCTION_SCREEN_GUARD
#define INSTRUCTION_SCREEN_GUARD

#include "Project_window.h"

struct Instruct_screen : public Project_window {


	Instruct_screen(Point xy, int w, int h, const string& title); //Construcctor for the tutorial screen


private:
	Button go_to_levels; //Takes the user back to the level selections screen
	Text instruct1 = Text{ Point{ 100,100 }, "Click a tile next to the empty tile to move the tile into the empty tile's spot. Continue" };
	Text instruct2 = Text{ Point{ 100,115 }, "to do so until the tiles are in the correct numerical order." };
};

#endif // !INSTRUCTION_SCREEN_GUARD



