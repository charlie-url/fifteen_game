#include "Game_manager.h"


	Game_manager::Game_manager()
		:splash{ Splash_screen(Point(0, 0), 720, 720, "Splash Screen") },
		instruct{ Instruct_screen(Point(0, 0), 720, 720, "Instruct Screen") },
		level{ Level_select(Point(0, 0), 720, 720, "Level Select", "username") },
		game{ Game_screen(Point(0, 0), 720, 720, "Game Screen", 10, "username") },
		end{ End_screen(Point(0, 0), 720, 720, "End Screen","username") }
	{
		instruct.hide();
		level.hide();
		game.hide();
		end.hide();
		current = splash.wait_for_button();
		username = splash.get_username();
		level.set_username(username);
		game.set_username(username);
		end.set_username(username);
		splash.hide();
	}

	void Game_manager::run() {
		while (current != Game_state(Quit)) {
			switch (current) {
			case (Game_state(Instruct)):
				instruct.show();
				current = instruct.wait_for_button();
				break;
			case (Game_state(Level)):
				level.show();
				current = level.wait_for_button();
				break;
			case (Game_state(Game_10)):
				game.show();
				game.set_difficulty(10);
				current = game.wait_for_button();
				break;
			case (Game_state(Game_20)):
				game.show();
				game.set_difficulty(20);
				current = game.wait_for_button();
				break;
			case (Game_state(Game_40)):
				game.show();
				game.set_difficulty(40);
				current = game.wait_for_button();
				break;
			case (Game_state(Game_80)):
				game.show();
				game.set_difficulty(80);
				current = game.wait_for_button();
				break;
			case (Game_state(End)):
				end.set_score(game.get_score());
				end.show();
				current = end.wait_for_button();
				break;
			case (Game_state(Quit)):
				return;
				break;
			default:
				cout << "Unexpected game state." << endl;
				cout << "Quitting..." << endl;
				return;
				break;
			}
		}
		return;
	}
