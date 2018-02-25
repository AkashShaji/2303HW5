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
	board1 = new Organism*[size];
	for(int i = 0; i < size; i++){
		board1[i] = new Organism[20];
	}
	board2 = new Organism*[size];
	for(int i = 0; i < size; i++){
		board2[i] = new Organism[20];
	}
	
	int	numSpots = 20 * size;
	if(numAnt + numDood > numSpots){
		cout << "Number of organisms greater than board size, not popuating board" << endl;
	}
	else{
		srand(time(NULL));
		while((numAnt > 0) && (numDood > 0)){
			int	ran = rand() % numSpots;
			if(board1[ran/size][ran%size].getType() == 'o'){
				if(numAnt){
				board1[ran/size][ran%size] = (Organism) *(new Ant());
					numAnt--;
				}
				else{
				board1[ran/size][ran%size] = (Organism) *(new Doodlebug());
					numDood--;
				}
			}
		}
	}
	workingBoard = 1;
	numGen = 1;
}

Board::~Board() {
//	delete board;
	for(int i = 0; i < size; i++){
			delete[] board1[i];
		}
	delete[] board1;
	for(int i = 0; i < size; i++){
				delete[] board2[i];
			}
		delete[] board2;
}

bool Board::isAllDead(Organism** board){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < 20; j++){
			if(!(board[i][j].getType() == 'o')){
				return false;
			}
		}
	}
	return true;
}

int Board::numAnts(Organism** board){
	int count = 0;
	for(int i = 0; i < size; i++){
			for(int j = 0; j < 20; j++){
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
			for(int j = 0; j < 20; j++){
				if(board[i][j].getType() == 'd'){
					count++;
				}
			}
		}
	return count;
}

//TODO FIX JANKY CODE

//tells which board you have to work on
Organism** Board::getNewBoard(){
	if(workingBoard == 1){
		return board1;
	}
	else
		return board2;
}

Organism** Board::getOldBoard(){
	if(workingBoard == 1){
		return board2;
	}
	else
		return board1;
}

void Board::cleanBoard(Organism** board){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < 20; j++){
			board[i][j] = *(new Organism());
		}
	}
}

void Board::generateNext(){
	Organism** newBoard = getNewBoard();
	Organism** oldBoard = getNewBoard();
	for(int i = 0; i < size; i++){
			for(int j = 0; j < 20; j++){
				if(!(oldBoard[i][j].getType() == 'o')){
					Organism*arr[4];

					if(i == 0){
						arr[0] = (Organism*)NULL;
					}
					else
						arr[0] = &newBoard[i-1][j];
					if(j == 0){
						arr[1] = (Organism*)NULL;
					}
					else
						arr[1] = &newBoard[i][j-1];

					if(i == (size-1)){
						arr[2] = (Organism*)NULL;
					}
					else
						arr[2] = &oldBoard[i+1][j];

					if(j == 19){
						arr[3] = (Organism*)NULL;
					}
					else
						arr[3] = &oldBoard[i][j+1];
					//int num = oldBoard[i][j].move(arr);

					//TODO Add changes to new board

					if(workingBoard == 1){
							workingBoard = 2;
							cleanBoard(board1);
						}
						else{
							workingBoard = 1;
							cleanBoard(board2);
						}
					numGen += 1;


				}
			}
		}
}

