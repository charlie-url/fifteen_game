//subtask 3, enter player name and store all scores along with player name
//not final, skeleton code for the buttons involved
//planning on opening a separate window to let the user enter their initials
//once they press enter, the separate window will close, and the initials will 
//be stored in a txt file

#include "std_lib_facilities_5.h"
#include "Simple_window.h"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"

struct player_list::Window {
	player_list(Point xy, int w, int h, const string& title);
private:
	Button enter_button;
	In_box player_initials;

	void enter();
};

player_list::player_list(Point xy, int w, int h, const string& title):window(xy, w, h, title),
enter_button{Point{x_max()-150,0),70,20,"Enter", 
[](Address, Address pw) {reference_to<player_list>(pw).enter(); },
player_initials{Point{x_max() - 310,0},50,20,"Initials:"}
{
attach(enter_button);
attach(player_initials);
}

void player_list::enter() {
	string current_player = player_initials.get_string();
	hide();
}

int main()
try {
  if(H112 != 201708L)error("Error: incorrect std_lib_facilities_5.h version ",
		  	   H112);
  player_list win (Point(100,200), 600, 400, "Enter Player Initials");
  return gui_main();

}
catch(exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}
