#include <iostream>
#include<time.h>
#include<stdlib.h>
#include<iomanip>
#include<stdio.h>
#include"sudoku.h"
using namespace std;
const int sudokuSize=144;
int temAnswer[sudokuSize]={};
sudoku::sudoku(){
	for(int i=0;i<sudokuSize;i++) map[i]=0;
}
bool sudoku::checkUnity(int arr[]){//check 12 numbers
	int ctrArr[10]={};
	for(int i=0;i<12;i++){
		if(arr[i]==-1) ctrArr[0]++;
		else ctrArr[arr[i]]++;
	}
	if(ctrArr[0]!=3) return false;
	for(int i=1;i<10;i++){
		if(ctrArr[i]!=1)
			return false;	
}
	return true;
}
bool sudoku::isCorrect(int answerMap[]){
	int checkArr[12]={};
	for(int i=0;i<144;i+=12){         //check the row
		for(int j=0;j<12;j++){    
			checkArr[j]=answerMap[i+j];
		}
		if(checkUnity(checkArr)==false) return false;
	}
	for(int i=0;i<12;i++){    //check the columns
		for(int j=0;j<12;j++){
			checkArr[i]=answerMap[i+j*12];
		}
		if(checkUnity(checkArr)==false) return false;
	}
	for(int i=0;i<12;i+=12){    //check the cell
		for(int j=0;j<12;j+=4){
			int a=0;
			for(int k=0;k<3;k++){
				for(int t=0;t<3;t++){
					checkArr[a]=answerMap[t+k];
					a++;
				}					
			}
			if(checkArr[0]!=-1){
				checkArr[9]=checkArr[10]=checkArr[11]=-1;
				if(checkUnity(checkArr)==false) return false;
			}
			else {
				for(int x=0;x<9;x++){
					if(checkArr[x]!=-1)return false;
				}
			}
return true;
}
}
}
void sudoku::GiveQuestion(){
	srand(time(0));
	int space=36;
	char sample[sudokuSize]={'x','x','x','f','d','e','c','a','b','i','g','h','x','x','x','i','g','h','f','d','e','c','a','b','x','x','x','c','a','b','i','g','h','f','d','e','d','e','f','x','x','x','a','b','c','g','h','i','g','h','i','x','x','x','d','e','f','a','b','c','a','b','c','x','x','x','g','h','i','d','e','f','b','c','a','e','f','d','x','x','x','h','i','g','e','f','d','h','i','g','x','x','x','b','c','a','h','i','g','b','c','a','x','x','x','e','f','d','i','g','h','d','e','f','b','c','a','x','x','x','c','a','b','g','h','i','e','f','d','x','x','x','f','d','e','a','b','c','h','i','g','x','x','x'};
	int Question[sudokuSize]={};
	int switchChar[9];
	int check[9]={};
	for(int i=0;i<9;i++){
		switchChar[i]=rand()%9+1;
		while(check[switchChar[i]]==1){
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
        	map[i]=Question[i];
       		cout<<setw(2)<<Question[i];
        	if((i+1)%12==0)cout<<endl;
}
}
sudoku sudoku::ReadIn(){	
return *this;
}
int sudoku::getFirstZero(int temAnswer[sudokuSize]){
	for(int i=0;i<sudokuSize;i++){
		if(temAnswer[i]==0) return i;
	}
}
void sudoku::setElement(int zero,int num){
	map[zero]=num;
}

bool sudoku::Solve(sudoku sample){

	int rowCheck[10]={};int colCheck[10]={};int cellCheck[10]={};int test[10]={};int tem;
        int temAnswer[sudokuSize]={}; int chanceNumber[10]={};int ctr=0,firstZero;
	for(int i=0;i<sudokuSize;i++) temAnswer[i]=sample.map[i];
	
	firstZero=getFirstZero(temAnswer);
	if(firstZero == -1)
	{ // end condition
  		if(sample.isCorrect(sample.map))
  		{
			for(int i=0;i<sudokuSize;i++){
  				temAnswer[i]= sample.map[i];
			}
  			return true;
  		}
  		else	return false;
  	}
	else
 	{
                        for(tem;tem<(firstZero/12)+12;tem++){   //select row
                                if(sample.map[tem]>0)rowCheck[sample.map[tem]]++;
                                else if(sample.map[tem]==-1)rowCheck[0]++;
                        }
                        for(tem=(firstZero%12);tem<sudokuSize;tem+=12){//select column
                                if((sample.map[tem]>0)) colCheck[sample.map[tem]]++;
                                else if ((sample.map[tem]==-1)) colCheck[0]++;
                        }
                        tem=3*((firstZero%12)/3)+36*((firstZero/12)/3);
                        for(int k=tem;k<tem+25;k+=12){ //select cell
                                for(int t=0;t<3;t++){
                                        if((sample.map[tem+t]>0))cellCheck[sample.map[tem]]++;
                                        else if((sample.map[tem+t]==-1))cellCheck[0]++;
                                                        }
                                                 }
                        for(int j=1;j<10;j++){ //test number
                                if(rowCheck[j]==0&&colCheck[j]==0&&cellCheck[j]==0) {
                                        chanceNumber[ctr]=j;
                                        ctr++;
                                }
                        }
                        if(chanceNumber[1]==0)  temAnswer[firstZero]=sample.map[firstZero]=chanceNumber[0];//只有一個可能


		for(int num=1; num<=ctr; ++num)
		{
			 sample.setElement(firstZero,chanceNumber[ctr]);
			 if(Solve(sample))
 			 return true;
 		}
 		return false;
 	}
  }

/*	for(int i=0;i<sudokuSize;i++){
		tem=i/12;
		if(sample.map[i]==0){
			for(tem;tem<(i/12)+12;tem++){   //select row
				if(sample.map[tem]>0)rowCheck[sample.map[tem]]++;
				else if(sample.map[tem]==-1)rowCheck[0]++;
			}
			for(tem=(i%12);tem<sudokuSize;tem+=12){//select column
				if((sample.map[tem]>0)) colCheck[sample.map[tem]]++;
				else if ((sample.map[tem]==-1)) colCheck[0]++;
			}		
			tem=3*((i%12)/3)+36*((i/12)/3);		
			for(int k=tem;k<tem+25;k+=12){ //select cell                    		
                             	for(int t=0;t<3;t++){
                                   	if((sample.map[tem+t]>0))cellCheck[sample.map[tem]]++;
					else if((sample.map[tem+t]==-1))cellCheck[0]++;
                                			}
                       				 }
			for(int j=1;j<10;j++){ //test number
				if(rowCheck[j]==0&&colCheck[j]==0&&cellCheck[j]==0) {
					chanceNumber[ctr]=j;
					ctr++;
				}
			}
			if(chanceNumber[1]==0)	temAnswer[i]=sample.map[i]=chanceNumber[0];//只有一個可能			
		else {   //兩個以上可能
				for(int t=0;t<10;t++) rowCheck[t]=0;
				for(int k=i-11;k<=i;k++){                                       
                                       rowCheck[temAnswer[k]]=1;
                                }
				for(int j=0;j<10;j++){					
					if(chanceNumber[j]!=0&&temAnswer[i]!=chanceNumber[j]&&rowCheck[chanceNumber[j]]==0){
						temAnswer[i]=chanceNumber[j];
					}
				}						
			}
	}
	}
			
	if(isCorrect(temAnswer)==true){
		for(int i=0;i<sudokuSize;i++){
			cout<<setw(2)<<temAnswer[i];
               		if((i+1)%12==0)cout<<endl;
		}
	}
	else Solve(sample);

}
*/
