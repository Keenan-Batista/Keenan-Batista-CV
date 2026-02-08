#include <iostream>
using namespace std;

int main() {
	int scores[5], highestScore, lowestScore; //Variable declaration
	double totalScores, averageScore;

	totalScores = 0;
	highestScore = 0;
	lowestScore = 100;

	//Input the scores and determine the highest as well as the lowest score that were inputted
	for (int i = 0; i <= 4; i++) {
		cout << "Enter student " << (i + 1) << " score: ";
		cin >> scores[i];
		cout << endl;

		if (highestScore < scores[i]) {
			highestScore = scores[i];
		}
		if (lowestScore > scores[i]) {
			lowestScore = scores[i];
		}
		totalScores = totalScores + scores[i];
	}

	cout << "Scores entered:\n";
	//Displays the scores in order
	for (int i = 0; i <= 4; i++) {
		cout << "Student " << (i + 1) << ": " << scores[i] << endl;
	}
	cout << endl;

	//Calculate and display the average score
	averageScore = ((totalScores / 500) * 100);
	cout << "Average score: " << (averageScore) << endl;

	cout << "Highest score: " << (highestScore) << endl;
	cout << "Lowest score: " << (lowestScore) << endl;

	return 0;
}