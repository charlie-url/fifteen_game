#ifndef END_SCREEN_GUARD
#define END_SCREEN_GUARD 1


#include "Project_window.h"
//create a screen for when the game ends
struct End_screen : public Project_window {

	End_screen(Point xy, int w, int h, const string& title, string user); //Constructor for our "game over" screen

	void set_score(int final_score); //Setter for the final game score

private:
	Button new_game_button; //button for restarting the game
	Text score = Text{ Point{ 100,100 }, "FinalScore"}; //Displays the final score to the player
};







#endif // !END_SCREEN_GUARD

