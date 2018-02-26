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
Ant::Ant() {
	// TODO Auto-generated constructor stub
	type = 'a';
	isMoved = true;
	turnsSinceLastBreed = 0;
}


Ant::~Ant() {
	// TODO Auto-generated destructor stub
}

char Ant::getType(){
	return 'a';
}

bool Ant::getIsMoved(){
	return isMoved;
}

void  Ant::changeIsMoved(){
	isMoved = !isMoved;
}

int Ant::move(Organism* nearby[]){
	int numEmpty = 0;
	for(int x = 0; x < 4; x++){
		if(!nearby[x]){
			numEmpty++;
		}
	}
	
	cout << "numEmpty: " <<	numEmpty;
	if(numEmpty == 0){
		return 4; //Return flag for no values remaining
	}
	else{
		numEmpty =  rand() % numEmpty;
		cout << " rand:" << numEmpty << endl;
		for(int x = 0; x < 4; x++){
			if(!nearby[x]){
				if(numEmpty-- == 0)
					return x;
			}
		}
	}
	return 4;
}

bool Ant::canBread(){
	if(turnsSinceLastBreed<3){
		return false;
	}
	else{
		return true;
	}
}


/*

int Ant::breed(Organism* nearby){

	//if(isEligible){
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

	else
		return 4;
}
*/

