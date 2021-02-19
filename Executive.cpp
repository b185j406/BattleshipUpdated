//Executive.cpp

#include "Executive.h"
#include <iostream>


Executive::Executive(){ //constructor
	playerOneFiringGrid = new int*[10];
	playerTwoFiringGrid = new int*[10];
	for(int i = 0; i < 10; i++){
		playerOneFiringGrid[i] = new int[10];
		playerTwoFiringGrid[i] = new int[10];
	}
	playerOneShipGrid = new int*[10];
	playerTwoShipGrid = new int*[10];
	for(int i = 0; i < 10; i++){
		playerOneShipGrid[i] = new int[10];
		playerTwoShipGrid[i] = new int[10];
	}

	fillGrids();
}

Executive::~Executive() //deconstructor
{
	for(int i = 0; i < 10; i++)
	{
		delete playerOneFiringGrid[i];
		delete playerTwoFiringGrid[i];
	}
	delete[] playerOneFiringGrid;
	delete[] playerTwoFiringGrid;
}

void Executive::run(){  //runs the program
	std::cout<<"Player one's turn\nIs player one ready?(y/Y): ";
	std::cin>>ready;
	if(ready == 'y' || ready =='Y')
	{
		printPlayerOneShipGrid();
		printPlayerOneFiringGrid();
		std::cout<<"Choose a postion to fire\n";
		std::cout<<"col: ";
		std::cin>>charCol;
		std::cout<<"row: ";
		std::cin>>row;
		fire1(row, charCol);
		std::cout<<"\nPlayer two's turn\nIs player two ready?(y/Y): ";
		std::cin>>ready;
		if(ready == 'y' || ready =='Y')
		{
			printPlayerTwoShipGrid();
			printPlayerTwoFiringGrid();
			std::cout<<"Choose a postion to fire\n";
			std::cout<<"col: ";
			std::cin>>charCol;
			std::cout<<"row: ";
			std::cin>>row;
			fire2(row, charCol);
		}
	}
	if(isWinner() == 0)
	{
		run();
	}
	if(isWinner() == 1)
	{
		std::cout<<"Player one wins!\n";
	}
	if(isWinner() == 2)
	{
		std::cout<<"Player two wins!\n";
	}
	std::cout<<"Would you like to play again?(y/n): ";
	std::cin>>playagain;
	if(playagain == 'y')
	{
		fillGrids();
		run();
	}
	else
	{
		std::cout<<"Goodbye...\n";
	}
}


void Executive::fillGrids(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			playerOneFiringGrid[i][j] = 0;
			playerTwoFiringGrid[i][j] = 0;
		}
	}
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			playerOneShipGrid[i][j] = 0;
			playerTwoShipGrid[i][j] = 0;
		}
	}
}

void Executive::printPlayerOneFiringGrid(){
	std::cout << "+------------------------------------Player One's Firing Board-------------------------------------------+\n";
	std::cout << "|			A	B	C	D	E	F	G	H	I	J	|\n";
	std::cout << "+---------------+---------------------------------------------------------------------------------------+\n";
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(j == 0){
				std::cout << "|" << "\t" << i+1 << "\t" << "|" << "\t" << playerOneFiringGrid[i][j] << "\t";
			}
			else if(j == 9){
				std::cout << playerOneFiringGrid[i][j] << "\t" << "|";
			}
			else{
				std::cout << playerOneFiringGrid[i][j] << "\t";
			}
		}
		std::cout << "\n";
	}
	std::cout << "+---------------+---------------------------------------------------------------------------------------+\n";
}

void Executive::printPlayerTwoFiringGrid(){
	std::cout << "+------------------------------------Player Two's Firing Board-------------------------------------------+\n";
	std::cout << "|			A	B	C	D	E	F	G	H	I	J	|\n";
	std::cout << "+---------------+---------------------------------------------------------------------------------------+\n";
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(j == 0){
				std::cout << "|" << "\t" << i+1 << "\t" << "|" << "\t" << playerTwoFiringGrid[i][j] << "\t";
			}
			else if(j == 9){
				std::cout << playerTwoFiringGrid[i][j] << "\t" << "|";
			}
			else{
				std::cout << playerTwoFiringGrid[i][j] << "\t";
			}
		}
		std::cout << "\n";
	}
	std::cout << "+---------------+---------------------------------------------------------------------------------------+\n";
}

void Executive::printPlayerOneShipGrid(){
	std::cout << "+------------------------------------Player One's Ship Board-------------------------------------------+\n";
	std::cout << "|			A	B	C	D	E	F	G	H	I	J	|\n";
	std::cout << "+---------------+---------------------------------------------------------------------------------------+\n";
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(j == 0){
				std::cout << "|" << "\t" << i+1 << "\t" << "|" << "\t" << playerOneShipGrid[i][j] << "\t";
			}
			else if(j == 9){
				std::cout << playerOneShipGrid[i][j] << "\t" << "|";
			}
			else{
				std::cout << playerOneShipGrid[i][j] << "\t";
			}
		}
		std::cout << "\n";
	}
	std::cout << "+---------------+---------------------------------------------------------------------------------------+\n";
}

void Executive::printPlayerTwoShipGrid(){
	std::cout << "+------------------------------------Player Two's Ship Board-------------------------------------------+\n";
	std::cout << "|			A	B	C	D	E	F	G	H	I	J	|\n";
	std::cout << "+---------------+---------------------------------------------------------------------------------------+\n";
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(j == 0){
				std::cout << "|" << "\t" << i+1 << "\t" << "|" << "\t" << playerTwoShipGrid[i][j] << "\t";
			}
			else if(j == 9){
				std::cout << playerTwoShipGrid[i][j] << "\t" << "|";
			}
			else{
				std::cout << playerTwoShipGrid[i][j] << "\t";
			}
		}
		std::cout << "\n";
	}
	std::cout << "+---------------+---------------------------------------------------------------------------------------+\n";
}

void Executive::fire1(int row, char charCol)
{
	col = CharToNum(charCol);
	if(playerTwoShipGrid[row][col] == 0)
	{
		playerOneFiringGrid[row][col] = 50;
		playerTwoShipGrid[row][col] = 50;
		std::cout<<"\nMISS\n";
	}
	else if(playerTwoShipGrid[row][col] == 50 || playerTwoShipGrid[row][col] == 99)
	{
		std::cout<<"Position has already been fired, choose a diffrent position\n";
		std::cout<<"col: ";
		std::cin>>charCol;
		std::cout<<"row: ";
		std::cin>>row;
		fire1(row, charCol);
	}
	else
	{
		playerOneFiringGrid[row][col] = 99;
		playerTwoShipGrid[row][col] = 99;
		std::cout<<"\nHIT\n";
	}
}

void Executive::fire2(int row, char charCol)
{
	col = CharToNum(charCol);
	if(playerOneShipGrid[row][col] == 0)
	{
		playerTwoFiringGrid[row][col] = 50;
		playerOneShipGrid[row][col] = 50;
		std::cout<<"\nMISS\n\n";
	}
	else if(playerOneShipGrid[row][col] == 50 || playerOneShipGrid[row][col] == 99)
	{
		std::cout<<"Position has already been fired, choose a diffrent position\n";
		std::cout<<"col: ";
		std::cin>>charCol;
		std::cout<<"row: ";
		std::cin>>row;
		fire1(row, charCol);
	}
	else
	{
		playerTwoFiringGrid[row][col] = 99;
		playerOneShipGrid[row][col] = 99;
		std::cout<<"\nHIT\n";
	}
}

int Executive::CharToNum(char charCol)
{
	if(charCol == 'a' || charCol == 'A')
	{
		return(1);
	}
	if(charCol == 'b' || charCol == 'B')
	{
		return(2);
	}
	if(charCol == 'c' || charCol == 'C')
	{
		return(3);
	}
	if(charCol == 'd' || charCol == 'D')
	{
		return(4);
	}
	if(charCol == 'e' || charCol == 'E')
	{
		return(5);
	}
	if(charCol == 'f' || charCol == 'F')
	{
		return(6);
	}
	if(charCol == 'g' || charCol == 'G')
	{
		return(7);
	}
	if(charCol == 'h' || charCol == 'H')
	{
		return(8);
	}
	if(charCol == 'i' || charCol == 'I')
	{
		return(9);
	}
	if(charCol == 'j' || charCol == 'J')
	{
		return(10);
	}
	else
	{
		return(1);
	}
}

int Executive::isWinner()
{
	return(0);
}
