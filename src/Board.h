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
#include "Organism.h"
#include "Ant.h"
#include "Doodlebug.h"
class Board {
public:
	Board(int,int,int);
	virtual ~Board();
	bool isBoardDead();
	void generateNext();
	int numAnts(Organism** board);
	int numBugs(Organism** board);
	Organism** getNewBoard();
	Organism** getOldBoard();
	void printBoard();
	void cleanBoard(Organism** board);
private:
	Organism** oldBoard;
	Organism** newBoard;
	int size;
	int numGen;
};

#endif /* SRC_BOARD_H_ */
