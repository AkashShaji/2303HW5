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
	virtual int move(Organism**);
	bool isBreesingTime();
	virtual char getType();
	void updateEligibility();
	bool getIsMoved();
	void changeIsMoved();
protected:
	char type;
	int numAliveChances;
	bool isEligible;
	bool isMoved;
};

#endif /* SRC_ORGANISM_H_ */
