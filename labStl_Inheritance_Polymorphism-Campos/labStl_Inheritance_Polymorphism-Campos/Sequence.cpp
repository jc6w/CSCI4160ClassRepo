#include "Sequence.h"


//constructors
Sequence::Sequence()
{
	setLabel(" ");
	setID(0);
	setSeq(" ");
	setLength(0);
}

Sequence::Sequence(string Label, int ID, string SEQ, int Length):label(Label),accessID(ID),sequence(SEQ),seqLength(Length)
{
	setLabel(Label);
	setID(ID);
	setSeq(SEQ);
	setLength(Length);
}

//overloading operator to print to file
void Sequence::printInfo(std::ostream& os){}