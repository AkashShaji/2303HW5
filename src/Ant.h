/*
 * Ant.h
 *
 *  Created on: Feb 21, 2018
 *      Author: Revant M. and Akash S.
 */

#ifndef SRC_ANT_H_
#define SRC_ANT_H_

#include "Organism.h"

class Ant: public Organism {
public:
	Ant();
	virtual ~Ant();
	char getType();
	int move(Organism**);
	bool canBreed();
	bool getIsMoved();
	void changeIsMoved();
	void changeIsMoved(bool);
};

#endif /* SRC_ANT_H_ */
