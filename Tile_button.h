#ifndef TILE_GUARD
#define TILE_GUARD 1

#include "lib/std_lib_facilities_5.h"
#include "lib/Window.h"
#include "lib/Graph.h"
#include "lib/Simple_window.h"

struct Tile_button : public Button {
	Tile_button(int x_coord, int y_coord, int number, Callback cb); //Constructor for a single tile in the 4x4 tile array

	int x(); //x position of tile on 4x4 array
	int y(); //y position of tile on 4x4 array
	int val(); //number that's on the tile
	void set_x(int x);
	void set_y(int y);
	void pseudo_set_xy(int x, int y); //for the invisible swap for the "hint"
	int manhattan(); //returns the manhattan distance for a tile

	Image red_tile;
	Image green_tile;
	Image blank_tile;
	Text tile_label;
private:
	int x_coord;
	int y_coord;
	int number;
	
};
#endif //TILE_GUARD 



