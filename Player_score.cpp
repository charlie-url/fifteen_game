#include "Player_score.h"
//tells the sort function which player_score item is bigger and smaller
//used for sorting the leaderboard

bool player_score::operator<(const player_score& p2) {
	return score < p2.score;
}
