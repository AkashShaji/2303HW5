/*
 * Board.h
 *
 *  Created on: Feb 21, 2018
 *      Author: student
 */

#ifndef SRC_BOARD_H_
#define SRC_BOARD_H_
#include "Organism.h"

class Board {
public:
	Board(int size);
	virtual ~Board();
	bool isAllDead();
private:
	Organism* board[];
	int size;
};

#endif /* SRC_BOARD_H_ */
