/*
 * Ants.h
 *
 *  Created on: Feb 21, 2018
 *      Author: student
 */

#ifndef SRC_ANTS_H_
#define SRC_ANTS_H_

#include "Organism.h"

class Ants: public Organism {
public:
	Ants();
	virtual ~Ants();
	char getType();
	int Move(Organism[]);
};

#endif /* SRC_ANTS_H_ */
