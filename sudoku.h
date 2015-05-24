#include<iostream>
using namespace std;
class sudoku{
public:
	sudoku();
	bool isCorrect(int []);
	void GiveQuestion();
	sudoku ReadIn();
	bool Solve(sudoku);
	bool checkUnity(int arr[]);
	int getFirstZero(int temAnswer[]);
	void setElement(int,int);
	static const int sudokuSize=144;

private:
	int map[sudokuSize];
};
