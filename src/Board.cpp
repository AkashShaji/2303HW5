/*
 * Board.cpp
 *
 *  Created on: Feb 21, 2018
 *      Author: student
 */

#include "Board.h"

Board::Board(int size) {
	this->size = size;
	board1 = new Organism*[size];
	for(int i = 0; i < size; i++){
		board1[i] = new Organism[20];
	}
	board2 = new Organism*[size];
	for(int i = 0; i < size; i++){
		board2[i] = new Organism[20];
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
			if(!(board[i][j].type() == 'o')){
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
				if(board[i][j].type() == 'a'){
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
				if(board[i][j].type() == 'd'){
					count++;
				}
			}
		}
	return count;
}
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

void Board::generateNext(){
	Organism** newBoard = getNewBoard();
	Organism** oldBoard = getNewBoard();
	for(int i = 0; i < size; i++){
			for(int j = 0; j < 20; j++){
				if(!(oldBoard[i][j].type() == 'o')){
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
						}
						else
							workingBoard = 1;
					numGen += 1;


				}
			}
		}
}

