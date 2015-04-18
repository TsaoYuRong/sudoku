#include<iostream>
using namespace std;
class sudoku{
public:
	sudoku();
	bool isCorrect(int []);
	void GiveQuestion();
	void ReadIn();
	void Solve();
	static const int sudokuSize=144;
	bool checkUnity(int arr[]);

private:
	int map[sudokuSize];
};
