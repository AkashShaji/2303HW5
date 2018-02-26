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

/**
 * Initializes the board.
 * @param the size of the board, board will be n*n
 * @param the number of ants to spawn
 * @param the number of doodlebugs to spawn
 */

Board::Board(int size, int numAnt, int numDood) {
	//Saves size of board
	this->size = size;
	//Initializes a new 2d array to store the board
	board = new Organism**[size];
	//Allocating memory
	for(int i = 0; i < size; i++){
		board[i] = new Organism*[size];
	}
	//Tracker for the number of generations simulated
	numGen = 0;

	//If theres more ants and doodlebugs than potential space, the board is not populated.
	if(numAnt + numDood > size * size){
		cout << "Number of organisms greater than board size, not popuating board" << endl;
		totalAnts = 0;
		totalDoods = 0;
	}
	else{
		//Saving the number of ants and doodlebugs for statistics
		totalAnts = numAnt;
		totalDoods = numDood;
		while((numAnt > 0) || (numDood > 0)){
			//Picks a random number and places an ant or doodlebug in the spot
			int	ran = rand() % (size * size);
			if(!board[ran%size][ran/size]){
				if(numAnt){
					board[ran%size][ran/size] =  new Ant();
					numAnt--;
				}
				else{
					board[ran%size][ran/size] = new Doodlebug();
					numDood--;
				}
			}
		}
	}
}





//TODO fix
Board::~Board() {
	//	delete board;
	for(int i = 0; i < size; i++){
		for(int j =0; j < size; j++){
			delete board[i][j];
		}
	}
}

/**
 * checks to see if there are any organisms on the board
 * @return if the board is dead or not
 */
bool Board::isBoardDead(){
	//itterates through each spot, and if any organism is found returns false;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if((board[i][j])){
				return false;
			}
		}
	}
	//Otherwise the board is dead.
	return true;
}
/**
 * returns the number of ants in the board
 * @return the number of ants in the board
 */
int Board::numAnts(){
	//value to be returned.
	int count = 0;
	//Itterates through each spot in the board, checks to see if there is an organism there
	//and if there is checks to see if it is an ant.
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(board[i][j] && board[i][j]->getType() == 'o'){
				count++;
			}
		}
	}
	return count;
}
/**
 * returns the number of doodlebugs in the board
 * @return the number of doodlebugs in the board
 */
int Board::numDoods(){
	//value to be returned.
	int count = 0;
	//Itterates through each spot in the board, checks to see if there is an organism there
	//and if there is checks to see if it is an ant
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(board[i][j] && board[i][j]->getType() == 'x'){
				count++;
			}
		}
	}
	return count;
}
/**
 * returns the total number of ants in the simulation
 * @return the total number of ants
 */
int Board::getTotalAnts(){
	return totalAnts;
}

/**
 * returns the total number of doodlebugs in the simulation
 * @return the total number of doodlebugs
 */
int Board::getTotalDoods(){
	return totalDoods;
}
/**
 * prints the board to the console
 */
void Board::printBoard(){
	//Itterats through each spot, checks to see if an organism is there, and if
	//there is it prints it's type
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(board[i][j]){
				cout << board[i][j]->getType();
			}
			else{
				cout << " ";
			}
		}
		//newline at the end of each row
		cout << endl;
	}
}


Organism** Board::getNearby(int i, int j){
	//List of nearby organisms to be passed to the move function
	cout << "in getBearby i: " << i << "j:" << j << "\n";
	Organism* arr[4];
	//Returns a fake organism if the position that is being checked is on the edge
	//otherwise returns the relative board position. 
	if(i == 0){
		arr[0] = new Organism();}
	else{
		arr[0] = board[i-1][j];}
	if(j == 0){
		arr[1] = new Organism();}
	else{
		arr[1] = board[i][j-1];}
	if(i == (size-1)){
		arr[2] = new Organism();}
	else{
		arr[2] = board[i+1][j];}
	if(j == (size-1)){
		arr[3] = new Organism();}
	else{
		arr[3] = board[i][j+1];}

	return arr;

}

void Board::generateNext(){
	//Itterating number of generations ran
	numGen += 1;
	//Resets all the organisms to have not moved yet.
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(board[i][j]){
				board[i][j]->changeIsMoved();
			}
		}
	}

	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(board[i][j] && !(board[i][j]->getIsMoved()) && board[i][j]->getType() == 'x'){
				Organism**arr = this->getNearby(i,j);
				cout << "here";
				//Gets the position the doodlebug wants to move to
				int num = board[i][j]->move(arr);
				cout << "here2";
				//States that the doodlebug has been moved so that it doesnt move again this turn
				board[i][j]->changeIsMoved();

				//If the doodlebug is starving, don't move it
				if(((Doodlebug*)board[i][j])->isStarving()){
					board[i][j] = NULL;
				}
				else{
					int x;
					int y;
					switch (num){
						case 0:
							x = i-1;
							y = j;
							break;
						case 1:
							x = i;
							y = j -1;
							break;
						case 2:
							x = i+1;
							y = j;
							break;
						case 3:
							x = i;
							y = j+1;
							break;
					}
					board[i][j]->changeIsMoved(true);
					if( num !=4){
						board[x][y] = board[i][j];
						if(board[x][y]->canBreed()){
							board[i][j] = new Doodlebug();
							totalDoods++;
						}
						else{
							board[i][j] = NULL;
						}
					}
				}
			}
		}
	}
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			//cout << "i:"<< i << "j:"<< j << endl;
			if(board[i][j] ){
				if (!(board[i][j]->getIsMoved()) && board[i][j]->getType() == 'o'){
					//						cout<<"MOvedA1: "<<(int)board[i][j]->getIsMoved();
					Organism*arr[4];
					//						cout << board[i][j]->getType() << endl;
					if(i == 0){
						arr[0] = new Organism();
					}
					else{
						arr[0] = board[i-1][j];
					}
					if(j == 0){
						arr[1] = new Organism();
					}
					else{
						arr[1] = board[i][j-1];
					}
					if(i == (size-1)){
						arr[2] = new Organism();
					}
					else{
						arr[2] = board[i+1][j];
					}

					if(j == (size-1)){
						arr[3] = new Organism();
					}
					else{
						arr[3] = board[i][j+1];
					}
					int num = board[i][j]->move(arr);
					board[i][j]->changeIsMoved();
					//						cout << "num" << num << endl;

					if(num == 0){
						board[i-1][j] = board[i][j];

						board[i-1][j]->changeIsMoved(true);
						//								cout<<"MOved2: "<<(int)board[i-1][j]->getIsMoved();
						if(board[i-1][j]->canBreed()){
							board[i][j] = new Ant();
							//cout<<"made ant"<<endl;
							totalAnts++;
						}
						else
							board[i][j] = NULL;
					}
					else if(num == 1){
						board[i][j-1] = board[i][j];

						board[i][j-1]->changeIsMoved(true);
						//cout<<"MOved2: "<<(int)board[i][j-1]->getIsMoved();
						if(board[i][j-1]->canBreed()){
							board[i][j] = new Ant();
							//cout<<"made ant"<<endl;
							totalAnts++;
						}
						else
							board[i][j] = NULL;
					}
					else if(num == 2){
						board[i+1][j] = board[i][j];

						board[i+1][j]->changeIsMoved(true);
						//cout<<"MOved2: "<<(int)board[i+1][j]->getIsMoved();
						if(board[i+1][j]->canBreed()){
							board[i][j] = new Ant();
							//cout<<"made ant"<<endl;
							totalAnts++;
						}
						else
							board[i][j] = NULL;
					}
					else if(num == 3){
						board[i][j+1] = board[i][j];

						board[i][j+1]->changeIsMoved(true);
						//cout<<"MOved2: "<<(int)board[i][j+1]->getIsMoved();
						if(board[i][j+1]->canBreed()){
							//cout<<"made ant"<<endl;
							board[i][j] = new Ant();
							totalAnts++;
						}
						else
							board[i][j+1] = NULL;
					}





				}
			}
		}

	}
	numGen += 1;
}

