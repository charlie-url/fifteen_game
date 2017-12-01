#include "Tile_button.h"


Tile_button::Tile_button(int x_coord, int y_coord, int number, Callback cb)
	:Button{ Point(100 + (100 * x_coord),200 + (100 * y_coord)),100, 100, to_string(number), cb },
	red_tile{ Point(100 + (100 * x_coord),200 + (100 * y_coord)),"img/red.jpg" },
	green_tile{ Point(100 + (100 * x_coord),200 + (100 * y_coord)),"img/green.jpg" },
	blank_tile{ Point(100 + (100 * x_coord),200 + (100 * y_coord)),"img/empty.jpg" },
	tile_label{ Point(100 + 50 + (100 * x_coord)-(3*(exp2(number/10))),200 + (100 * y_coord)+(55)),to_string(number) },
	x_coord{ x_coord },
	y_coord{ y_coord },
	number{ number }
{
	if (number == 0) { tile_label.set_label(" "); } //create the blank tile
	
	tile_label.set_font(Graph_lib::Font::screen_bold);
	tile_label.set_color(Color::white);
}

int Tile_button::x() {
	return x_coord;
}

int Tile_button::y() {
	return y_coord;
}

int Tile_button::val() {
	return number;
}

//moves the tile along the x-axis on the 4x4 array
void Tile_button::set_x(int x) {

	move(100 * (x - x_coord), 0);
	red_tile.move(100 * (x - x_coord), 0);
	green_tile.move(100 * (x - x_coord), 0);
	blank_tile.move(100 * (x - x_coord), 0);
	tile_label.move(100 * (x - x_coord), 0);
	x_coord = x;	
	Fl::redraw();
}

//moves the tile along the y-axis on the 4x4 array
void Tile_button::set_y(int y) {
	move(0, 100 * (y - y_coord));
	red_tile.move(0, 100 * (y - y_coord));
	green_tile.move(0, 100 * (y - y_coord));
	blank_tile.move(0, 100 * (y - y_coord));
	tile_label.move(0, 100 * (y - y_coord));
	y_coord = y;
	Fl::redraw();
}

//emulate a tile movement for the sake of finding the manhattan distance
void Tile_button::pseudo_set_xy(int x, int y) {
	move(100 * (x - x_coord), 0);
	x_coord = x;
	move(0, 100 * (y - y_coord));
	y_coord = y;
}

//find the manahattan distance of a tile
int Tile_button::manhattan() {
	int ideal_x = (number - 1) % 4;
	int ideal_y = (number - 1) / 4;
	if (number == 0) {//blank in bottom right
		ideal_x = 3;
		ideal_y = 3;
	}
	int dy = abs(y_coord - ideal_y);
	int dx = abs(x_coord - ideal_x);
	return (dx + dy);
}


