#ifndef CARDBOARDGAME_H
#define CARDBOARDGAME_H

#include "Card.h"

/**********************************
cardBoardGame class stores the tiles, 
and solves for a solution for the puzzle
***********************************/
class cardBoardGame
{
private:
	Card cardTiles[9];	//to store cards
	bool solved;		//for knowing when the whole board is solved
public:
	//constructor
	cardBoardGame() {}
	
	//import data from stdin
	void importEntries(string);
	
	//solver functions
	void solveCards(Card[9], int, int);
	bool compareCards(int);

	//other functions
	void swapCards(Card[9],int, int);
	void rotateBoard();

	void printCards();
};

#endif

