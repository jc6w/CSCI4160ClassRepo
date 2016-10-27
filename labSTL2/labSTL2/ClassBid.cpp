#include "ClassBid.h"

//default constructor
classBid::classBid()
{
}

//overloading constructor
classBid::classBid(int b, string f, string l)
{
	numBid = b;
	firstName = f;
	lastName = l;
	studentName = f + " " + l;
}

//overloading print function based on where to print out
void classBid::print(ostream &os)
{
	os << studentName << " " << numBid << "\n\n";
}


