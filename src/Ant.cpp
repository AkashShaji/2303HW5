/*
 * Ant.cpp
 *
 *  Created on: Feb 21, 2018
 *      Author: student
 */

#include "Ant.h"
#include "iostream"
using namespace std;
#include <stdlib.h>
/**
 * Constructs an ant, fixes initial conditions
 */

Ant::Ant() {
	// TODO Auto-generated constructor stub
	type = 'o';
	isMoved = true;
	turnsSinceLastBreed = 0;
}

/**
 * Deconstructs an ant
 */
Ant::~Ant() {
}

/**
 * Returns the type of the ant for classification and printing
 * @return type of organism. 
 */
char Ant::getType(){
	return type;
}

/**
 * Returns if the ant has been moved this turn yet.
 */
bool Ant::getIsMoved(){
	return isMoved;
}
/**
 * Toggles if the ant has been moved or not.
 */
void  Ant::changeIsMoved(){
	isMoved = !isMoved;
}

/**
 * Sets whether the ant has been moved or not.
 * @param has the ant been moved?
 */
void  Ant::changeIsMoved(bool val){
	isMoved = val;
}
/**
 * Takes in an array of potential spots and picks one for the ant to move to.
 * @param, an array of size 4 that contains pointers to potential locations for the ant to move
 * @return either the index that the ant will move to, or 4 which means the ant does not move.
 */
int Ant::move(Organism* nearby[]){
	//This loop calculates the number of free spots avaliable
	int numEmpty = 0;
	for(int x = 0; x < 4; x++){
		if(!nearby[x]){
			numEmpty++;
		}
	}
	//If there are no empty spots avaliable, the flag for not moving is returned	
	if(numEmpty == 0){
		return 4; //Return flag for no values remaining
	}
	//Otherwise a random spot is chosen, and the index of that spot in the array is returned.
	else{
		numEmpty =  rand() % numEmpty;
		for(int x = 0; x < 4; x++){
			if(!nearby[x]){
				if(numEmpty-- == 0){
					turnsSinceLastBreed++;
					return x;
				}
			}
		}
	}
	return 4;
}

/**
 * Checks to see if the ant can breed and if it can it resets the amount of time until it breeds
 * Note: This function is only called when the there is a spot for a new ant to be placed
 * @return whether or not the ant can breed.
 */
bool Ant::canBreed(){
	if(turnsSinceLastBreed<3){
		return false;
	}
	else{
		turnsSinceLastBreed = 0;
		return true;
	}
}
