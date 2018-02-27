/*
 * Doodlebugs.cpp
 *
 *  Created on: Feb 21, 2018
 *      Author: student
 */

#include "Doodlebug.h"
#include "iostream"
using namespace std;
#include <stdlib.h>
Doodlebug::Doodlebug() {
	// TODO Auto-generated constructor stub
	type = 'x';
	isMoved = true;
	turnsSinceLastBreed = 0;
	numStarvingTurns = 0;

}

Doodlebug::~Doodlebug() {
	// TODO Auto-generated destructor stub
}

/**
 * @return char 'x' representing ant.
 */
char Doodlebug::getType(){
	return 'x';
}

/**
 * @param array of pointers representing possible move options.
 * @return integer representing the move to be made.
 */
int Doodlebug::move(Organism** nearby){

	int numAnts = 0;
	turnsSinceLastBreed++;
	int numEmpty = 0;
	for(int x = 0; x < 4; x++){
		if(!nearby[x]){
			numEmpty++;
		}
	}
	for(int x = 0; x < 4; x++){
		if(nearby[x] && nearby[x]->getType() == 'o'){

			numAnts++;
		}
	}

	//cout << "numEmpty: " <<	numEmpty;
	//cout << "numAnts: " <<	numAnts;
	if(numEmpty == 0 && numAnts == 0){
		return 4; //Return flag for no values remaining
	}
	else{
		if(numAnts){
			numStarvingTurns = 0;
			numAnts =  rand() % numAnts;
			//cout << " randAnts:" << numAnts << endl;
			for(int x = 0; x < 4; x++){
				if(nearby[x] && nearby[x]->getType() == 'o'){
					if(numAnts-- == 0){
						//cout<<"turnsSinceLastBreedwith -- ants: "<<turnsSinceLastBreed<<endl;
						return x;
					}
				}
			}
		}
		else{
			numEmpty =  rand() % numEmpty;
			numStarvingTurns++;
			//cout << " randEmp:" << numEmpty << endl;
			for(int x = 0; x < 4; x++){
				if(!nearby[x]){
					if(numEmpty-- == 0){
						turnsSinceLastBreed++;
						//cout<<"turnsSinceLastBreedwithout ants: "<<turnsSinceLastBreed<<endl;
						return x;
					}
				}
			}
		}
	}

	return 4;
}





/**
 * @return returns isMoved.
 */
bool Doodlebug::getIsMoved(){
	return isMoved;
}

/**
 * chanes is moved.
 */
void Doodlebug::changeIsMoved(){
	isMoved = !isMoved;
}

/**Changes isMoved.
 * @param a boolean representing state where true represents moved and false represents not moved.
 */
void Doodlebug::changeIsMoved(bool val){
	isMoved = val;
}

/**
 * @return if the doodlebug can breeed.
 */
bool Doodlebug::canBreed(){
	if(turnsSinceLastBreed < 8){
		return false;
	}
	else{
		turnsSinceLastBreed = 0;
		//cout<<"++++++++++++++++++++can doodle+++++++++++++++++++++++"<<endl;
		return true;

	}
}
/**
 * @return if the doodlebug is starving.
 *
 */
bool Doodlebug::isStarving(){
	if (numStarvingTurns > 3){
		return true;
	}
	else
		return false;
}
