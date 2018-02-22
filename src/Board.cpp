/*
 * Board.cpp
 *
 *  Created on: Feb 21, 2018
 *      Author: student
 */

#include "Board.h"

Board::Board(int size) {
	this->size = size;
	board = new int[size][size];

}

Board::~Board() {
	delete board;
}

bool isAllDead(){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){

		}
	}
}

