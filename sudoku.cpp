#include <iostream>
#include"sudoku.h"
using namespace std;
sudoku::sudoku(){
	for(int i=0;i<sudokuSize;i++){
		map[i]=0;
}
}
bool sudoku::checkUnity(int arr[]){
	int ctrArr[9]={};
	for(int i=0;i<9;i++){
		ctrArr[arr[i]-1]++;
			}
	for(int i=0;i<9;i++){
		if(ctrArr[i]!=1)
			return false;	
}
	return true;
}
bool sudoku::isCorrect(int answerMap[]){
	int checkArr[9];
	for(int i=0;i<81;i+=9){         //check the row
		for(int j=0;j<9;j++){    
			checkArr[j]=answerMap[i+j];
}
		if(checkUnity(checkArr)==false) return false;
}
	for(int i=0;i<9;i++){    //check the columns
		for(int j=0;j<9;j++){
			checkArr[i]=answerMap[i+j*9];
}
		if(checkUnity(checkArr==false)) return false;
	for(int i=0;i<9){    //check the cell
		for(int j=0;j<9;j++){
			



}


}



}









}
