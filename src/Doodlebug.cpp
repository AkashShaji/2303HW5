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
	return 4;
}


void Doodlebug::updateEligibility(){
	if(numAliveChances % 8 ==0){
		isEligible =  true;
	}
	isEligible = false;
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

