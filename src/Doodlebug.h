/*
 * Doodlebugs.h
 *
 *  Created on: Feb 21, 2018
 *      Author: student
 */

#ifndef SRC_DOODLEBUG_H_
#define SRC_DOODLEBUG_H_

#include "Organism.h"

class Doodlebug: public Organism {
public:
	Doodlebug();
	virtual ~Doodlebug();
	char getType();
	int move(Organism**);
	int breed(Organism**);

	bool getIsMoved();
	void changeIsMoved();
	bool canBread();

};

#endif /* SRC_DOODLEBUG_H_ */
