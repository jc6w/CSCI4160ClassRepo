#include "Card.h"

Card::Card()
{
	/*default constructor*/
}

//initialize Card object
Card::Card(char letter, int n, int e, int s, int w)
{
	letterName = letter;
	North = n;
	East = e;
	South = s;
	West = w;
	rotateNum = 0;
}

//rotate card or card's data clockwise
void Card::rotateCard()
{
	int temp = North;
	North = West;
	West = South;
	South = East;
	East = temp;
	rotateNum++;
	if (rotateNum > 3)
	{
		rotateNum = 0;
	}
}

//printer function
void Card::printCard()
{
	cout << letterName << rotateNum;
}