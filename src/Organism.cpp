/*
 * Organism.cpp
 *
 *  Created on: Feb 21, 2018
 *      Author: student
 */

#include "Organism.h"
/**
 * Organism Constructor
 */
Organism::Organism() {
	// TODO Auto-generated constructor stub
	type = ' ';
	 turnsSinceLastBreed = 0;
	isMoved = true;
}
/**
 * Organism Destructor
 */
Organism::~Organism() {
	// TODO Auto-generated destructor stub
}
/**
 * Organism Move function
 */
int Organism::move(Organism** o){
	return 4;
}
/**
 * Returns the type of the organism.
 * @return the type of the organism.
 */
char Organism::getType(){
	return type;
}
/**
 * Returns if the organism has been moved.
 * @return whether or not the organism has been moved.
 */
bool Organism::getIsMoved(){
	return isMoved;
}
/**
 * Changes whether or not the organism has moved.
 */
void  Organism::changeIsMoved(){
	isMoved = !isMoved;
}
/**
 * Returns if the organism can breed.
 */
bool Organism::canBreed(){
	return false;
}
/**
 * Sets if the organism has moved or not.
 * @param whether or not the organism has moved.
 */
void  Organism::changeIsMoved(bool val){
	isMoved = val;
}

