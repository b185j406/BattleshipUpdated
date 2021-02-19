//Executive.h

#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>
#include <fstream>
#include <iostream>

class Executive
{

	public:
		Executive();
		~Executive();

		void run();
		void printPlayerOneFiringGrid();
		void printPlayerTwoFiringGrid();
		void printPlayerOneShipGrid();
		void printPlayerTwoShipGrid();
		void fillGrids();
		void fire1(int row, char col);
		void fire2(int row, char col);
		int CharToNum(char charCol);
		int isWinner();

	private:
		int** playerOneFiringGrid;
		int** playerTwoFiringGrid;
		int** playerOneShipGrid;
		int** playerTwoShipGrid;
		int row;
		char charCol;
		int col;
		char ready;
		char playagain;
};
#endif
