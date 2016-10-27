#include "DNA.h"
#include "Sequence.h"



DNA::DNA():Sequence()
{
	
		setCode(-1);
}

DNA::DNA(string Label, int ID, string Seq, int Length, int Code):Sequence(Label, ID, Seq, Length)
{
	setCode(Code);
}


void DNA::printInfo(std::ostream& os)
{
	os << "Label: " << label << "\t";
	os << "ID: " << accessID << "\t";
	os << "Sequence: " << sequence << "\t";
	os << "Length: " << seqLength << "\t";
	os << "cDNAStartIndex: " << regCode << "\n\n";
}

