#include "CardBoardGame.h"
//import data from .txt to the array
void cardBoardGame::importEntries(string inputName)
{
	ifstream openFile;
	char letter;						//for letter in Card object
	int numCards = 0, n, s, e, w;		//numCards for how many cards; n, e, s, w for the 4 numbers on the card
	solved = false;						//initialize solved

	openFile.open(inputName);
	if (!openFile.is_open())
	{
		cerr << "Unable to open input file";
	}
	while (!openFile.eof())
	{
		openFile >> letter;
		openFile >> n;
		openFile >> e;
		openFile >> s;
		openFile >> w;
		Card newCard(letter, n,e,s,w);	//grab input and initialize a new Card object
		cardTiles[numCards] = newCard;	//place object into array
		++numCards;						//count how many cards so far
	}
	cout << "Solution 1 of 4:\n";
	solveCards(cardTiles,0, numCards); //solve for a solution

	for (int x = 0; x < 3; x++)
	{
		rotateBoard();					//rotate whole solved board for other solutions
		solved = false;					//reset to solve
		cout << "Solution " << x + 2 << " of 4:\n";
		solveCards(cardTiles, 0, numCards); //solve
	}
}

void cardBoardGame::solveCards(Card cards[9], int start, int end)
{
	if (solved)
	{
		return;
	}
	else if (start == end)				//print if reached the very end; base case
	{
		solved = true;
		printCards();
		return;
	}
	else
	{
		for (int x = start; x < end; x++) //for every permutation
		{
			swapCards(cards, start, x); //swap cards 
			
			for (int y = 0; y < 4; y++)	//for every rotation per card
			{
				if (start == 0)			//if starting card is at index 0
				{
					solveCards(cards, 1, end); //solve next one
					if (!solved)		//if not solved, rotate the card, and solve again
					{
						cards[0].rotateCard();
					}
				}
				else if (compareCards(start)) //if cards 1 - 8 return true in compareCards
				{
					solveCards(cards, start + 1, end); //solve the next one
				}
				else
				{
					cards[start].rotateCard();	//else rotate the card	
				}
			}
			if (solved) //if it's solved, end
			{
				return;
			}
			else	//swap cards
			{
				swapCards(cards, start, x);
			}
		}
	}
}

bool cardBoardGame::compareCards(int i) //checks left (and above when applied) of each cards to see if they match; none for case 0(initial card)
{
	switch (i)
	{
	case 1: return (cardTiles[i].getW() + cardTiles[i - 1].getE() == 0);

	case 2: return (cardTiles[i].getW() + cardTiles[i - 1].getE() == 0);

	case 3: return (cardTiles[i].getN() + cardTiles[i - 3].getS() == 0);

	case 4: return (cardTiles[i].getW() + cardTiles[i - 1].getE() == 0 && cardTiles[i].getN() + cardTiles[i - 3].getS() == 0);

	case 5: return (cardTiles[i].getW() + cardTiles[i - 1].getE() == 0 && cardTiles[i].getN() + cardTiles[i - 3].getS() == 0);

	case 6: return (cardTiles[i].getN() + cardTiles[i - 3].getS() == 0);

	case 7: return (cardTiles[i].getW() + cardTiles[i - 1].getE() == 0 && cardTiles[i].getN() + cardTiles[i - 3].getS() == 0);

	case 8: return (cardTiles[i].getW() + cardTiles[i - 1].getE() == 0 && cardTiles[i].getN() + cardTiles[i - 3].getS() == 0);

	default: return true;
	}
}

//for swapping elements in the array
void cardBoardGame::swapCards(Card cards[9], int a, int b)
{
	Card temp = cards[a];
	cards[a] = cards[b];
	cards[b] = temp;
}
//rotate the finished solution board to get the other solutions
void cardBoardGame::rotateBoard()
{
	Card temp1 = cardTiles[2];
	Card temp2 = cardTiles[1];
	cardTiles[2] = cardTiles[0];
	cardTiles[1] = cardTiles[3];
	cardTiles[0] = cardTiles[6];
	cardTiles[3] = cardTiles[7];
	cardTiles[6] = cardTiles[8];
	cardTiles[7] = cardTiles[5];
	cardTiles[8] = temp1;
	cardTiles[5] = temp2;
}
//for printing
void cardBoardGame::printCards()
{
	for (int x = 0; x < 9; x++)
	{
		cardTiles[x].printCard();
		cout << " ";
		if (x == 2 || x == 5 || x == 8)
		{
			cout << "\n";
		}
	}
	cout << "\n\n";
}