#include "AA.h"
#include "Sequence.h"


AA::AA():Sequence()
{
	setORF(0);
}
AA::AA(string Label, int ID, string Seq, int Length, int orf):Sequence(Label, ID, Seq, Length)
{
	setORF(orf);
}



void AA::printInfo(std::ostream& os)
{
	os << "Label: " << label << "\t";
	os << "ID: " << accessID << "\t";
	os << "Sequence: " << sequence << "\t";
	os << "Length: " << seqLength << "\t";
	os << "ORF: " << ORF << "\n\n";
}