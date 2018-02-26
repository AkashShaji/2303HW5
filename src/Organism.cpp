/*
 * Organism.cpp
 *
 *  Created on: Feb 21, 2018
 *      Author: student
 */

#include "Organism.h"

Organism::Organism() {
	// TODO Auto-generated constructor stub
	type = ' ';
	 turnsSinceLastBreed = 0;
	isMoved = true;
}

Organism::~Organism() {
	// TODO Auto-generated destructor stub
}

int Organism::move(Organism** o){
	return 0;
}

char Organism::getType(){
	return type;
}

bool Organism::getIsMoved(){
	return isMoved;
}

void  Organism::changeIsMoved(){
	isMoved = !isMoved;
}

bool Organism::canBreed(){
	return false;
}

