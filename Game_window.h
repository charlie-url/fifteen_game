#include "GUI.h"    
#include "Graph.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

struct Game_window : Graph_lib::Window {
	Game_window(Point xy, int w, int h, const string& title);

	bool wait_for_button(); // simple event loop

private:
	Button next_button;     // the "next" button
	bool button_pushed;     // implementation detail

	static void cb_next(Address, Address); // callback for next_button
	void next();            // action to be done when next_button is pressed

};