main:main.o sudoku.o
	g++ -o main main.o sudoku.o
sudoku.o:sudoku.cpp sudoku.h
	g++ -c sudoku.cpp
main.o: main.cpp sudoku.h
	g++ -c main.cpp
clear:
	 rm main *.o
