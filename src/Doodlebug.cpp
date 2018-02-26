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
	type = 'd';
	isMoved = true;
	turnsSinceLastBreed = 0;
	numStarvingTurns = 0;
}

Doodlebug::~Doodlebug() {
	// TODO Auto-generated destructor stub
}

char Doodlebug::getType(){
	return 'd';
}

int Doodlebug::move(Organism** nearby){
	/*int numEmpty = 0;
	for(int x = 0; x < 4; x++){
		if(nearby == NULL){
			numEmpty++;
		}
		nearby++;
	}
	if(numEmpty == 0){
		return 4; //Return flag for no values remaining
	}
	else{
		cout << "numEmpty: " <<	numEmpty;
		numEmpty =  rand() % numEmpty;
		cout << " rand:" << numEmpty << endl;
		for(int x = 0; x < 4; x++){
			if(nearby[x].getType() == 'a'){
				if(numEmpty-- == 0)
					return x;
			}
		}
		for(int x = 0; x < 4; x++){
			if(nearby[x].getType() == ' '){
				if(numEmpty-- == 0)
					return x;
			}
		}

	}*/
	int numAnts = 0;
	//numStarvingTurns++;
	int numEmpty = 0;
		for(int x = 0; x < 4; x++){
			if(!nearby[x]){
				numEmpty++;
			}
		}
		for(int x = 0; x < 4; x++){
					if(nearby[x] && nearby[x]->getType() == 'a'){

						numAnts++;
					}
				}

		cout << "numEmpty: " <<	numEmpty;
		cout << "numAnts: " <<	numAnts;
		if(numEmpty == 0 && numAnts == 0){
			return 4; //Return flag for no values remaining
		}
		else{
			if(numAnts){
				numStarvingTurns = 0;
				turnsSinceLastBreed = 0;
				numAnts =  rand() % numAnts;
				cout << " randAnts:" << numAnts << endl;
				for(int x = 0; x < 4; x++){
					if(nearby[x] && nearby[x]->getType() == 'a'){
						if(numAnts-- == 0){

							return x;
						}
					}
				}
			}
			else{
			numEmpty =  rand() % numEmpty;
			cout << " randEmp:" << numEmpty << endl;
			for(int x = 0; x < 4; x++){
				if(!nearby[x]){
					if(numEmpty-- == 0){
						numStarvingTurns++;
						return x;
					}
				}
			}
			}
		}

		return 4;
}




int Doodlebug::breed(Organism** nearby){
/*
	if(isEligible){
	int numEmpty = 0;
		for(int x = 0; x < 4; x++){
			if(nearby == NULL){
				numEmpty++;
			}
			nearby++;
		}
		if(numEmpty == 0){
			return 4; //Return flag for no values remaining
		}
		else{
			cout << "numEmpty: " <<	numEmpty;
			numEmpty =  rand() % numEmpty;
			cout << " rand:" << numEmpty << endl;
			for(int x = 0; x < 4; x++){
				if(nearby[x].getType() == ' '){
					if(numEmpty-- == 0){
						return x;
					}
				}
			}
		}
		return 4;
	}
	else*/
		return 4;
}

bool Doodlebug::getIsMoved(){
	return isMoved;
}

void Doodlebug::changeIsMoved(){
	isMoved = !isMoved;
}

void Doodlebug::changeIsMoved(bool val){
	isMoved = val;
}

bool Doodlebug::canBreed(){
	if(turnsSinceLastBreed<8){
		return false;
	}
	else{
		turnsSinceLastBreed = 0;
		return true;

	}
}

bool Doodlebug::isStarving(){
	if (numStarvingTurns > 3){
		return true;
	}
	else
		return false;
}
