/*
 * Board.cpp
 *
 *  Created on: Feb 21, 2018
 *      Author: student
 */

#include "Board.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
Board::Board(int size, int numAnt, int numDood) {
	this->size = size;
	oldBoard = new Organism**[size];
	for(int i = 0; i < size; i++){
		oldBoard[i] = new Organism*[size];
	}
	newBoard = new Organism**[size];
	for(int i = 0; i < size; i++){
		newBoard[i] = new Organism*[size];
	}
	int	numSpots = size * size;
	if(numAnt + numDood > numSpots){
		cout << "Number of organisms greater than board size, not popuating board" << endl;
	}
	else{

		srand(time(NULL));
		while((numAnt > 0) || (numDood > 0)){
			int	ran = rand() % numSpots;
			cout << ran << " " << ran/size << " " << ran%size << endl;
			if(!newBoard[ran%size][ran/size]){
				if(numAnt){
				newBoard[ran%size][ran/size] =  new Ant();
					numAnt--;
				}
				else{
				newBoard[ran%size][ran/size] = new Doodlebug();
					numDood--;
				}
			}
		}
	}
	numGen = 1;
}





//TODO fix
Board::~Board() {
//	delete board;
/*	for(int i = 0; i < size; i++){
			delete[] newBoard[i];
		}
	delete[] newBoard;
	for(int i = 0; i < size; i++){
				delete[] oldBoard[i];
			}
	delete[] oldBoard;
	*/
}
/*
bool Board::isBoardDead(){
	for(int i = 0; i < size; i++){

		for(int j = 0; j < size; j++){
			if(!(newBoard[i][j])){
				return false;
			}
		}
	}
	return true;
}

int Board::numAnts(Organism** board){
	int count = 0;
	for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				if(board[i][j].getType() == 'a'){
					count++;
				}
			}
		}
	return count;
}

int Board::numBugs(Organism** board){
	int count = 0;
	for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				if(board[i][j].getType() == 'd'){
					count++;
				}
			}
		}
	return count;
}
*/

void Board::printBoard(){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(newBoard[i][j]){
			cout << newBoard[i][j]->getType();
			}
			else{
			cout << " ";
			}
		}
		cout << endl;
	}
}


void Board::generateNext(){
	tempBoard = oldBoard;
	oldBoard = newBoard;
	newBoard = tempBoard;
	cout << "testicles" << endl;

	for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				cout << "i:"<< i << "j:"<< j << endl;
				if(oldBoard[i][j]){
					Organism*arr[4];
					cout << oldBoard[i][j]->getType() << endl;
					if(i == 0){
						arr[0] = NULL;
					}
					else{
						arr[0] = newBoard[i-1][j];
					}
					if(j == 0){
						arr[1] = NULL;
					}
					else{
						arr[1] = newBoard[i][j-1];
					}
					if(i == (size-1)){
						arr[2] = NULL;
					}
					else
						arr[2] = oldBoard[i+1][j];

					if(j == (size-1)){
						arr[3] = NULL;
					}
					else{
						arr[3] = oldBoard[i][j+1];
					}
					int num = oldBoard[i][j]->move(arr);
					
					if(num == 0){
						newBoard[i-1][j] = oldBoard[i][j];
						newBoard[i][j] = NULL;
					}
					else if(num == 1){
						newBoard[i][j-1] = oldBoard[i][j];
						newBoard[i][j] = NULL;
					}
					else if(num == 2){
						newBoard[i+1][j] = oldBoard[i][j];
						newBoard[i][j] = NULL;
					}
					else if(num == 3){
						newBoard[i][j+1] = oldBoard[i][j];
						newBoard[i][j] = NULL;
					}
					else if(num == 4){
						newBoard[i][j] = oldBoard[i][j];
					}
					numGen += 1;
				}
			}
		}
}

