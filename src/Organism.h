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

	virtual char getType();
	virtual bool canBreed();
	bool getIsMoved();
	void changeIsMoved();
	void changeIsMoved(bool);
protected:
	char type;
	int turnsSinceLastBreed ;
	bool isMoved;
};

#endif /* SRC_ORGANISM_H_ */
