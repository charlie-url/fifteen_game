#ifndef TILE_GUARD
#define TILE_GUARD 1

#include "lib/std_lib_facilities_5.h"
#include "lib/Window.h"
#include "lib/Graph.h"
#include "lib/Simple_window.h"

struct Tile_button : public Button {
	Tile_button(int x_coord, int y_coord, int number, Callback cb);

	int x();
	int y();
	int val();
	void set_x(int x);
	void set_y(int y);
	void pseudo_set_xy(int x, int y);
	int manhattan();

	Image red_tile;
	Image green_tile;

private:
	int x_coord;
	int y_coord;
	int number;

};
#endif //TILE_GUARD 



