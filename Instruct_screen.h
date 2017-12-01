#ifndef INSTRUCTION_SCREEN_GUARD
#define INSTRUCTION_SCREEN_GUARD

#include "Project_window.h"

struct Instruct_screen : public Project_window {


	Instruct_screen(Point xy, int w, int h, const string& title); //Construcctor for the tutorial screen


private:
	Button go_to_levels;
	Text how_to_play = Text{ Point{360 - (16 * 24) / 2,360 - 64 - 20},"How to play:" };
	Text instruct1 = Text{ Point{ 90+20,360 }, "�  Click a tile next to the empty tile to move the tile into the empty tile's spot." };
	Text instruct2 = Text{ Point{ 90+20,380 }, "�  Continue to do so until the tiles are in the correct numerical order." };

};

#endif // !INSTRUCTION_SCREEN_GUARD



