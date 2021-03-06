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
	bool isStarving();
	bool getIsMoved();
	void changeIsMoved();
	void changeIsMoved(bool);
	bool canBreed();
private:
	int numStarvingTurns;

};

#endif /* SRC_DOODLEBUG_H_ */
