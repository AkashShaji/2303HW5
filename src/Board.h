/*
 * Board.h
 *
 *  Created on: Feb 21, 2018
 *      Author: student
 */

#ifndef SRC_BOARD_H_
#define SRC_BOARD_H_
#include "Organism.h"
#include<stdio.h>

class Board {
public:
	Board(int size);
	virtual ~Board();
	bool isAllDead(Organism** board);
	void generateNext();
private:
	Organism** board1;
	Organism** board2;
	int size;
};

#endif /* SRC_BOARD_H_ */
