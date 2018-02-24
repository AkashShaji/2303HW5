/*
 * Doodlebugs.h
 *
 *  Created on: Feb 21, 2018
 *      Author: student
 */

#ifndef SRC_DOODLEBUGS_H_
#define SRC_DOODLEBUGS_H_

#include "Organism.h"

class Doodlebugs: public Organism {
public:
	Doodlebugs();
	virtual ~Doodlebugs();
	char type();
};

#endif /* SRC_DOODLEBUGS_H_ */
