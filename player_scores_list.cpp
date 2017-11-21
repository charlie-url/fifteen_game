#include "std_lib_facilities_5.h"

struct player_scores {
	string name;
	int score;
};

int main() {
	vector<player_scores>original_scores;

	ifstream Scores;
	Scores.open("Scores_list.txt");

	if (Scores.fail()) {
		cerr << "Error Opening File" << endl;
		keep_window_open();
		exit(1);
	}
	player_scores set_scores;
	while (Scores>>set_scores.name>>set_scores.score) {
		original_scores.push_back(set_scores);
	}

	Scores.close();


	cout << "enter name: " << endl;
	player_scores set;
	cin >> set.name;
	set.score = 0;
	original_scores.push_back(set);
	cout << set.name << ' ' << set.score << endl<<endl;

	

		for (int i = 0; i < original_scores.size(); ++i) {
		cout << original_scores[i].name << ' ' << original_scores[i].score << endl;
	}

	ofstream new_score_list;
	new_score_list.open("Scores_list.txt");
	for (int i = 0; i < original_scores.size(); ++i) {
		new_score_list << original_scores[i].name << " " << original_scores[i].score << endl;
	}


	new_score_list.close();


	
	keep_window_open();
	return 0;
}
