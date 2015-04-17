#include <iostream>
#include<time.h>
#include<stdlib.h>
#include<iomanip>
#include"sudoku.h"
using namespace std;
sudoku::sudoku(){
	for(int i=0;i<sudokuSize;i++){
		map[i]=0;
}
}
bool sudoku::checkUnity(int arr[]){//check 9 numbers
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
}
	for(int i=0;i<9;i++){    //check the cell
		for(int j=0;j<9;j++){
			int a;
			a=27*(i/3)+3*(i%3)+9*(j/3)+(j%3);           
			checkArr[i]=answerMap[a];		
}
	if(checkUnity(checkArr)==false) return false;
}
}
*/
void sudoku::GiveQuestion(){
	srand(time(0));
	int space=36;
	char sample[sudokuSize]={'x','x','x','f','d','e','c','a','b','i','g','h','x','x','x','i','g','h','f','d','e','c','a','b','x','x','x','c','a','b','i','g','h','f','d','e','d','e','f','x','x','x','a','b','c','g','h','i','g','h','i','x','x','x','d','e','f','a','b','c','a','b','c','x','x','x','g','h','i','d','e','f','b','c','a','e','f','d','x','x','x','h','i','g','e','f','d','h','i','g','x','x','x','b','c','a','h','i','g','b','c','a','x','x','x','e','f','d','i','g','h','d','e','f','b','c','a','x','x','x','c','a','b','g','h','i','e','f','d','x','x','x','f','d','e','a','b','c','h','i','g','x','x','x'}
	int Question[sudokuSize];
	int switchChar[9];
	int check[9]={};
	for(int i=0;i<9;i++){
		switchChar[i]=rand()%9+1;
		while(check[switchChar[i]==1){
			switchChar[i]=rand()%9+1;
}
		check[switchChar[i]]++;

}
	for(int i=0;i<sudokuSize;i++){		
		switch(sample[i]){
			case 'a':Question[i]=switchChar[0];break;
			case 'b':Question[i]=switchChar[1];break;
			case 'c':Question[i]=switchChar[2];break;
			case 'd':Question[i]=switchChar[3];break;
			case 'e':Question[i]=switchChar[4];break;
			case 'f':Question[i]=switchChar[5];break;
			case 'g':Question[i]=switchChar[6];break;
			case 'h':Question[i]=switchChar[7];break;
			case 'i':Question[i]=switchChar[8];break;
			case 'x':Question[i]=-1;
}
}
	int tempNum[sudokuSize]={};
	for(int i=0;i<sudokuSize;i++){
        if(Question[i]==-1) tempNum[i]=1;
}
	for(int i=0;i<space;i++){
		int spaceNum;
		spaceNum=rand()%144;
		while(tempNum[spaceNum]==1)  spaceNum=rand()%144;
		Question[spaceNum]=0;
       		tempNum[spaceNum]=1;
}	
	for(int i=0;i<sudokuSize;i++) {
        	sudoku::map[i]=Question[i]
       		cout<<setw(2)<<Question[i];
        	if((i+1)%12==0)cout<<endl;
}
}
void sudoku::Readin(int map[sudokuSize]){
	int readinQuestion[sudokuSize];	
	for(int i=0;i<sudokuSize;i++){
		 readinQuestion[i]=map[i];
		 cout<<readinQuestion[i];	
}
}
void sudoku::Solve(int Question[sudokuSize]){
	for(int i=0;i<sudukuSize;i++){
		if(Question[i]==0){
			int tem=floor(i/12),rowCheck[10]={},colCheck[10]={},cellCheck[10]={};
			int anotherSpace[sudokuSize]={},spaceCtr=0;
			for(tem;tem<floor(i/12)+12;tem++){   //select row
				if(Question[tem]>0)rowCheck[Question[tem]]++;
				else if(Question[tem]==-1)rowCheck[0]++;
				else if(Question[tem]==0){anotherSpace[sapceCtr]=tem; spaceCtr++;}
			}
			for(tem=i;tem<sudokuSize;tem+=12){//select column
				if(Question[tem]>0) colCheck[Question[tem]]++;
				else if (Question[tem]==-1) colCheck[0]++;
				else if(Question[tem]==0){anotherSpace[spaceCtr]==tem; spaceCtr++;}
			}
			for(){ //select cell

			}
			
			int chanceNumber[10];
			for(int j=1;j<10;j++){ //test number
				if(rowCheck[j]==0&&colCheck[j]==0&&cellCheck==[0]) chanceNumber[j]++;
			}

			int space=i; 
			for(int j=0;j<10;j++){  //origin space
				if(chanceNumber[j]==1)Question[space]=j;
					rowCheck[j]==1;// 排除已用過的數
					colCheck[j]==1;
					cellCheck[j]==1;
					
					for(int k=0;k<27;k++){//get all row number
						if(anotherSpace[k]<floor(j/12)+12&&anotherSpace[k]>floor((j-1)/12)+12){
                                                	space=anotherSpace[k];
							for(int t=1;t<10;t++){
								if(rowCheck[t]==0){
		                                                        Question[space]=t;
									rowCheck[t]=1;
									break;
									}
                                				}
						}
						else if ((anotherSpace[k]-j)%12==0){//get all column
							space=anotherSpace[k];
							for(int t=1;t<10;t++){
								if(colCheck[t]==0){
									Question[space]=t;
									colCheck[t]=1;
									break;
							
								}
							}
						}
						else if(){//get all cell
							space=anotherSpace[k];
                                                        for(int t=1;t<10;t++){
                                                                if(cellCheck[t]==0){
                                                                        Question[space]=t;
                                                                        cellCheck[t]=1;
                                                                        break;

                                                                }
							}
						}
						else break;
						}
					checkUnity()
					



}
					
                                                                                               
                                                              
                                                                       
                                                                              


							
			for(tem=i;tem<sudokuSize;tem+=12)
}	
}
}
}
