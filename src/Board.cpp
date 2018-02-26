/*
 * Board.cpp
 *
 *  Created on: Feb 21, 2018
 *      Author: student
 */

#include "Board.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
Board::Board(int size, int numAnt, int numDood) {
	this->size = size;
	board = new Organism**[size];
	for(int i = 0; i < size; i++){
		board[i] = new Organism*[size];
	}
	int	numSpots = size * size;
	if(numAnt + numDood > numSpots){
		cout << "Number of organisms greater than board size, not popuating board" << endl;
		totalAnts = 0;
		totalDoods = 0;
	}
	else{
		totalAnts = numAnt;
		totalDoods = numDood;
		srand(time(NULL));
		while((numAnt > 0) || (numDood > 0)){
			int	ran = rand() % numSpots;
			//cout << ran << " " << ran/size << " " << ran%size << endl;
			if(!board[ran%size][ran/size]){
				if(numAnt){
					board[ran%size][ran/size] =  new Ant();
					numAnt--;
				}
				else{
					board[ran%size][ran/size] = new Doodlebug();
					numDood--;
				}
			}
		}
	}
	numGen = 0;
}





//TODO fix
Board::~Board() {
	//	delete board;
	for(int i = 0; i < size; i++){
		for(int j =0; j < size; j++){
			delete board[i][j];
		}
	}
}

bool Board::isBoardDead(){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if((board[i][j])){
				return false;
			}
		}
	}
	return true;
}

int Board::numAnts(){
	int count = 0;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(board[i][j] && board[i][j]->getType() == 'a'){
				count++;
			}
		}
	}
	return count;
}

int Board::numDoods(){
	int count = 0;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(board[i][j] && board[i][j]->getType() == 'd'){
				count++;
			}
		}
	}
	return count;
}

int Board::getTotalAnts(){
	return totalAnts;
}
int Board::getTotalDoods(){
	return totalDoods;
}

void Board::printBoard(){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(board[i][j]){
				cout << board[i][j]->getType();
			}
			else{
				cout << " ";
			}
		}
		cout << endl;
	}
}


void Board::generateNext(){
	numGen += 1;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(board[i][j]){
				board[i][j]->changeIsMoved();
			}
		}
	}
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			//cout << "i:"<< i << "j:"<< j << endl;
			if(board[i][j] ){
				if(!(board[i][j]->getIsMoved()) && board[i][j]->getType() == 'd'){
					//					cout<<"MOved: "<<(int)board[i][j]->getIsMoved();

					Organism*arr[4];
					//cout << board[i][j]->getType() << endl;
					if(i == 0){
						arr[0] = new Organism();
					}
					else{
						arr[0] = board[i-1][j];
					}
					if(j == 0){
						arr[1] = new Organism();
					}
					else{
						arr[1] = board[i][j-1];
					}
					if(i == (size-1)){
						arr[2] = new Organism();
					}
					else{
						arr[2] = board[i+1][j];
					}

					if(j == (size-1)){
						arr[3] = new Organism();
					}
					else{
						arr[3] = board[i][j+1];
					}
					int num = board[i][j]->move(arr);
					board[i][j]->changeIsMoved();
					//					cout << "num" << num << endl;

					if(((Doodlebug*)board[i][j])->isStarving()){
						//						cout<<endl<<endl<<"starving"<<endl<<endl;
						board[i][j] = NULL;
					}
					else{
						if(num == 0){
							board[i-1][j] = board[i][j];
							board[i-1][j]->changeIsMoved(true);
							//cout<<"MOved2: "<<(int)board[i-1][j]->getIsMoved();
							if(board[i-1][j]->canBreed()){
								//								//cout<<"*******Made bug******"<<endl;
								totalDoods++;
								board[i][j] = new Doodlebug();
							}
							else
								board[i][j] = NULL;
						}
						else if(num == 1){
							board[i][j-1] = board[i][j];
							board[i][j-1]->changeIsMoved(true);
							//cout<<"MOved2: "<<(int)board[i][j-1]->getIsMoved();
							if(board[i][j-1]->canBreed()){
								board[i][j] = new Doodlebug();
								//								cout<<"*******Made bug******"<<endl;
								totalDoods++;
							}
							else
								board[i][j] = NULL;
						}
						else if(num == 2){
							board[i+1][j] = board[i][j];
							board[i+1][j]->changeIsMoved(true);
							//cout<<"MOved2: "<<(int)board[i+1][j]->getIsMoved();
							if(board[i+1][j]->canBreed()){
								board[i][j] = new Doodlebug();
								//								cout<<"*******Made bug******"<<endl;
								totalDoods++;
							}
							else
								board[i][j] = NULL;
						}
						else if(num == 3){
							board[i][j+1] = board[i][j];
							board[i][j+1]->changeIsMoved(true);
							//						cout<<"MOved2: "<<(int)board[i][j+1]->getIsMoved();
							if(board[i][j+1]->canBreed()){
								board[i][j] = new Doodlebug();
								//							cout<<"*******Made bug******"<<endl;
								totalDoods++;
							}
							else
								board[i][j] = NULL;
						}


					}


				}
			}
		}
	}
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			//cout << "i:"<< i << "j:"<< j << endl;
			if(board[i][j] ){
				if (!(board[i][j]->getIsMoved()) && board[i][j]->getType() == 'a'){
					//						cout<<"MOvedA1: "<<(int)board[i][j]->getIsMoved();
					Organism*arr[4];
					//						cout << board[i][j]->getType() << endl;
					if(i == 0){
						arr[0] = new Organism();
					}
					else{
						arr[0] = board[i-1][j];
					}
					if(j == 0){
						arr[1] = new Organism();
					}
					else{
						arr[1] = board[i][j-1];
					}
					if(i == (size-1)){
						arr[2] = new Organism();
					}
					else{
						arr[2] = board[i+1][j];
					}

					if(j == (size-1)){
						arr[3] = new Organism();
					}
					else{
						arr[3] = board[i][j+1];
					}
					int num = board[i][j]->move(arr);
					board[i][j]->changeIsMoved();
					//						cout << "num" << num << endl;

					if(num == 0){
						board[i-1][j] = board[i][j];

						board[i-1][j]->changeIsMoved(true);
						//								cout<<"MOved2: "<<(int)board[i-1][j]->getIsMoved();
						if(board[i-1][j]->canBreed()){
							board[i][j] = new Ant();
							//cout<<"made ant"<<endl;
							totalAnts++;
						}
						else
							board[i][j] = NULL;
					}
					else if(num == 1){
						board[i][j-1] = board[i][j];

						board[i][j-1]->changeIsMoved(true);
						//cout<<"MOved2: "<<(int)board[i][j-1]->getIsMoved();
						if(board[i][j-1]->canBreed()){
							board[i][j] = new Ant();
							//cout<<"made ant"<<endl;
							totalAnts++;
						}
						else
							board[i][j] = NULL;
					}
					else if(num == 2){
						board[i+1][j] = board[i][j];

						board[i+1][j]->changeIsMoved(true);
						//cout<<"MOved2: "<<(int)board[i+1][j]->getIsMoved();
						if(board[i+1][j]->canBreed()){
							board[i][j] = new Ant();
							//cout<<"made ant"<<endl;
							totalAnts++;
						}
						else
							board[i][j] = NULL;
					}
					else if(num == 3){
						board[i][j+1] = board[i][j];

						board[i][j+1]->changeIsMoved(true);
						//cout<<"MOved2: "<<(int)board[i][j+1]->getIsMoved();
						if(board[i][j+1]->canBreed()){
							//cout<<"made ant"<<endl;
							board[i][j] = new Ant();
							totalAnts++;
						}
						else
							board[i][j+1] = NULL;
					}





				}
				/////////////////
			}
		}

	}
	numGen += 1;
}

