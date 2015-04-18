#include<iostream>
#include"sudoku.h"
using namespace std;
int main(){
	sudoku test;
	test.GiveQuestion();
	test.ReadIn();
	test.Solve();
	return 0;
}
