#ifndef PLAYER_SCORE_GUARD
#define PLAYER_SCORE_GUARD 1

#include "lib/std_lib_facilities_5.h"

struct player_score {
	//for task 3 and 6, assigns two different values to 1 element in a vector made of player_scores

	bool operator<(const player_score& p2);

	
	string name;
	int score;
};






#endif // !PLAYER_SCORE_GUARD


