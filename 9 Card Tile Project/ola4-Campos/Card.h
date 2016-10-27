#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::cerr;
using std::getline;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::stoi;
using std::string;
using std::vector;

/**********************************
Card class stores the letter of the tile,
its numbers based on position, and how many 
times it is rotated
***********************************/
class Card
{
private:
	char letterName;
	int North;
	int East;
	int South;
	int West;
	int rotateNum;
public:
	//constructors
	Card();
	Card(char, int, int, int, int);

	//getters
	int getN() { return North; }
	int getE() { return East; }
	int getS() { return South; }
	int getW() { return West; }
	int getRNum() { return rotateNum; }

	//other functions
	void rotateCard();
	void printCard();

};

#endif