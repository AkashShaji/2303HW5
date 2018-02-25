/*
 * Ants.cpp
 *
 *  Created on: Feb 21, 2018
 *      Author: student
 */

#include "Ants.h"
#include "iostream"
using namespace std;
#include <stdlib.h>
Ants::Ants() {
	// TODO Auto-generated constructor stub
	type = 'a';
}

Ants::~Ants() {
	// TODO Auto-generated destructor stub
}

char Ants::getType(){
	return 'a';
}

int Ants::Move(Organism nearby[]){
	int numEmpty = 0;
	for(int x = 0; x < 4; x++){
		if(nearby == NULL){
			numEmpty++;
		}
	}
	if(numEmpty == 0){
		return 4; //Return flag for no values remaining
	}
	else{
		cout << "numEmpty: " <<	numEmpty;
		numEmpty =  rand() % numEmpty;
		cout << " rand:" << numEmpty << endl;
		for(int x = 0; x < 4; x++){
			if(nearby[x].getType() == 'o'){
				if(numEmpty-- == 0)
					return x;
			}
		}
	}
	return 4;
}
