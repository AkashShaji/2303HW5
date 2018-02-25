/*
 * Organism.h
 *
 *  Created on: Feb 21, 2018
 *      Author: student
 */

#ifndef SRC_ORGANISM_H_
#define SRC_ORGANISM_H_

class Organism {
public:
	Organism();
	virtual ~Organism();
	virtual void move();
	bool isBreesingTime();
	char type();

private:
	int numAliveChances;
	bool isEligible;
};

#endif /* SRC_ORGANISM_H_ */
