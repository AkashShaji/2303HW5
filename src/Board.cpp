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
	for(int i = 0; i < size; i++){
		for(int j =0; j < size; j++){
			delete newBoard[i][j];
		}
	}


	for(int i = 0; i < size; i++){
		for(int j =0; j < size; j++){
			delete oldBoard[i][j];
		}
	}


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
	//tempBoard = oldBoard;
	//oldBoard = newBoard;
	//newBoard = tempBoard;
	cout << "testicles" << endl;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(newBoard[i][j]){
				newBoard[i][j]->changeIsMoved();
			}
		}
	}
	for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				cout << "i:"<< i << "j:"<< j << endl;
				if(newBoard[i][j] ){
					if(!newBoard[i][j]->getIsMoved() && newBoard[i][j]->getType() == 'd'){
					Organism*arr[4];
					cout << newBoard[i][j]->getType() << endl;
					if(i == 0){
						arr[0] = new Organism();
					}
					else{
						arr[0] = newBoard[i-1][j];
					}
					if(j == 0){
						arr[1] = new Organism();
					}
					else{
						arr[1] = newBoard[i][j-1];
					}
					if(i == (size-1)){
						arr[2] = new Organism();
					}
					else{
						arr[2] = newBoard[i+1][j];
					}

					if(j == (size-1)){
						arr[3] = new Organism();
					}
					else{
						arr[3] = newBoard[i][j+1];
					}
					int num = newBoard[i][j]->move(arr);
					newBoard[i][j]->changeIsMoved();
					cout << "num" << num << endl;

					if(((Doodlebug*)newBoard[i][j])->isStarving()){
						newBoard[i][j] == NULL;
					}
					else{
						if(num == 0){
							newBoard[i-1][j] = newBoard[i][j];

							if(newBoard[i][j]->canBreed()){
								newBoard[i][j] = new Doodlebug();
							}

							newBoard[i][j] = NULL;
						}
						else if(num == 1){
							newBoard[i][j-1] = newBoard[i][j];
							if(newBoard[i][j]->canBreed()){
								newBoard[i][j] = new Doodlebug();
							}
							newBoard[i][j] = NULL;
						}
						else if(num == 2){
							newBoard[i+1][j] = newBoard[i][j];
							if(newBoard[i][j]->canBreed()){
								newBoard[i][j] = new Doodlebug();
							}
							newBoard[i][j] = NULL;
						}
						else if(num == 3){
						newBoard[i][j+1] = newBoard[i][j];
						if(newBoard[i][j]->canBreed()){
							newBoard[i][j] = new Doodlebug();
						}
							newBoard[i][j] = NULL;
						}


					}
					

					}
					
					else{
						Organism*arr[4];
						cout << newBoard[i][j]->getType() << endl;
						if(i == 0){
							arr[0] = new Organism();
						}
						else{
							arr[0] = newBoard[i-1][j];
						}
						if(j == 0){
							arr[1] = new Organism();
						}
						else{
							arr[1] = newBoard[i][j-1];
						}
						if(i == (size-1)){
							arr[2] = new Organism();
						}
						else{
							arr[2] = newBoard[i+1][j];
						}

						if(j == (size-1)){
							arr[3] = new Organism();
						}
						else{
							arr[3] = newBoard[i][j+1];
						}
						int num = newBoard[i][j]->move(arr);
						newBoard[i][j]->changeIsMoved();
						cout << "num" << num << endl;

							if(num == 0){
								newBoard[i-1][j] = newBoard[i][j];

								if(newBoard[i][j]->canBreed()){
									newBoard[i][j] = new Doodlebug();
								}

								newBoard[i][j] = NULL;
							}
							else if(num == 1){
								newBoard[i][j-1] = newBoard[i][j];
								if(newBoard[i][j]->canBreed()){
									newBoard[i][j] = new Doodlebug();
								}
								newBoard[i][j] = NULL;
							}
							else if(num == 2){
								newBoard[i+1][j] = newBoard[i][j];
								if(newBoard[i][j]->canBreed()){
									newBoard[i][j] = new Doodlebug();
								}
								newBoard[i][j] = NULL;
							}
							else if(num == 3){
							newBoard[i][j+1] = newBoard[i][j];
							if(newBoard[i][j]->canBreed()){
								newBoard[i][j] = new Doodlebug();
							}
								newBoard[i][j] = NULL;
							}





					}

				}
			}

		}
	numGen += 1;
}

