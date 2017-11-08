#include "std_lib_facilities_5.h"
#include "Window.h"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"
#include "Simple_window.h"

struct Splash_screen : Graph_lib::Window {
	Splash_screen(Point xy, int w, int h, const string& title)
		:Window{ xy,w,h,title },
		play_button{ Point{ 360-64,360-32 }, 128, 64, "Play",  [](Address, Address pw) { reference_to<Splash_screen>(pw).play(); } },
		button_pushed{ false }
	{
		attach(play_button);

	}
	void wait_for_button() {
		while (!button_pushed) {
			Fl::wait();
		}
		button_pushed = false;
		play();
	}

private:

	Button play_button;
	bool button_pushed;

	void play() {
		cout << "[next screen]" << endl;
		Fl::redraw();
	}
};


int main() {
	try {
		Splash_screen splash(Point(0, 0), 720, 720, "Splash Screen");
		splash.wait_for_button();



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