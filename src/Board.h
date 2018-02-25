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
	int numAnts(Organism** board);
	int numBugs(Organism** board);
	Organism** getNewBoard();
	Organism** getOldBoard();
private:
	Organism** board1;
	Organism** board2;
	int size;
	int workingBoard;//1 for board1 , 2 for board2
	int numGen;
};

#endif /* SRC_BOARD_H_ */
