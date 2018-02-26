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
	int numAnts();
	int numDoods();
	Organism*** getNewBoard();
	Organism*** getOldBoard();
	void printBoard();
	int getTotalAnts();
	int getTotalDoods();
	Organism** getNearby(int,int,Organism* arr[]);
private:
	Organism*** board;
	int size;
	int numGen;
	int totalAnts;
	int totalDoods;	
};

#endif /* SRC_BOARD_H_ */
