#include "lib/std_lib_facilities_5.h"
#include "lib/Window.h"
#include "lib/Graph.h"
#include "FL/Fl_JPEG_Image.H"
#include "lib/Simple_window.h"

#include "fifteen_game.h"


int main() {
	try {
		Game_manager game = Game_manager();
		game.run();
		//keep_window_open();
		return 0;

	}
	catch (exception& e) {
		cerr << "error:" << e.what() << endl;
		keep_window_open();
		return 1;
	}
	catch (...) {
		cerr << "Oops, unknown exception!" << endl;
		keep_window_open();
		return 2;
	}
}