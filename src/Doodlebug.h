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
};

#endif /* SRC_DOODLEBUG_H_ */
