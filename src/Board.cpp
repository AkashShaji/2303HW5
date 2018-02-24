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

}

Board::~Board() {
//	delete board;
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


