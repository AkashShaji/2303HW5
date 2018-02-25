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
	virtual void move(Organism[]);
	bool isBreesingTime();
	virtual char getType();

private:
	int numAliveChances;
	bool isEligible;
protected:
	char type;
};

#endif /* SRC_ORGANISM_H_ */
