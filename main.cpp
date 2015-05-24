#include<iostream>
#include"sudoku.h"
using namespace std;
int main(){
	sudoku test;
	sudoku Test;
	test.GiveQuestion();
	Test=test.ReadIn();
	test.Solve(Test);
	return 0;
}
