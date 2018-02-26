//============================================================================
// Name        : PA4_akashshaji2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <iomanip>
#include <math.h>
#include "Board.h"
using namespace std;



#define FAILURE -1



int main(int argc, char * argv[]) {

	if(argc < 1 || argc > 7 ){
		cout <<"Invalid number of arguments.\n Usage is ./PA5 gridSize #doodlebugs #ants #time_steps seed pause" << endl;
		return FAILURE;
	}

	for(int x = 0; x < argc; x++){
		cout << argv[x] << endl;
	}
	
	
	int gridSize = 20;
	int numDoods = 5;
	int numAnts = 100;
	int timeSteps = 1000;
	int seedVal = 1;
	int pause = 0;
	if(argc > 1){
		gridSize = atoi(argv[1]);
	}	//TODO still moves multiple times
	//		make correction
	if(argc > 2){
		numDoods = atoi(argv[2]);
	}
	if(argc > 3){
		numAnts = atoi(argv[3]);
	}
	if(argc > 4){
		timeSteps = atoi(argv[4]);
	}
	if(argc > 5){
		seedVal = atoi(argv[5]);
	}
	if(argc > 6){
		pause = atoi(argv[6]);
	}

	Board  board =  Board(gridSize,numAnts,numDoods);
	board.printBoard();

	for(int x = 0; x < timeSteps; x++)
	{
		cout << x << "------------------------------------------------------------------" << endl;
		board.generateNext();
		cout<<endl<<endl<<endl;
		cout << endl << endl;
		board.printBoard();
	}
	return 0;	


	//TODO Pause
	//TODO make Organism virtual class- problem with this is that you cannot mak organism objects as we do for walls
	//TODO Terminate game
	//TODO print the stats
	//TODO should we breed randomly. we don,t right now
	//TODO also should make our generate next board function smaller.

}
