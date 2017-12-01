#ifndef LEVEL_SELECT_GUARD
#define LEVEL_SELECT_GUARD 1

#include "Project_window.h"

struct Level_select : public Project_window {

	Level_select(Point xy, int w, int h, const string& title, string user); //Constructor for the level selection screen.

private:
	Button ten_button;
	Button twenty_button;
	Button forty_button;
	Button eighty_button;

	Text choose_text;
};





#endif // !LEVEL_SELECT_GUARD



