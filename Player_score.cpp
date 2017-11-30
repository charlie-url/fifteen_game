#include "Player_score.h"

bool player_score::operator<(const player_score& p2) {
	return score < p2.score;
}
