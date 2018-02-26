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
}

Ant::~Ant() {
	// TODO Auto-generated destructor stub
}

char Ant::getType(){
	return 'a';
}

int Ant::move(Organism* nearby){
	int numEmpty = 0;
	cout << "revant has an enormous penis" << endl;
	for(int x = 0; x < 4; x++){
		if(nearby ==  NULL){
			numEmpty++;
		}
		nearby++;
		cout << nearby << endl;
	}
	if(numEmpty == 0){
		return 4; //Return flag for no values remaining
	}
	else{
		cout << "numEmpty: " <<	numEmpty;
		numEmpty =  rand() % numEmpty;
		cout << " rand:" << numEmpty << endl;
		for(int x = 0; x < 4; x++){
			if(nearby == NULL){
				if(numEmpty-- == 0)
					return x;
				nearby++;
			}
		}
	}
	return 4;
}

void Ant::updateEligibility(){
	if(numAliveChances % 3 ==0){
		isEligible =  true;
	}
	isEligible = false;
}

int Ant::breed(Organism* nearby){

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
	else
		return 4;
}


