#include "RNA.h"
#include "Sequence.h"

void RNA::setType(string t)
{
	if( t == "mRNA")
	{
		type = mRNA;
	}
	else if(t == "rRNA")
	{
		type = rRNA;
	}
	else if(t == "tRNA")
	{
		type = tRNA;
	}
}

string RNA::getType()
{
	if( type == mRNA)
	{
		return "mRNA";
	}
	else if(type == rRNA)
	{
		return "rRNA";
	}
	else if(type == tRNA)
	{
		return "tRNA";
	}
}

RNA::RNA():Sequence()
{
	setType(0);
}

RNA::RNA(string Label, int ID, string Seq, int Length, string t):Sequence(Label, ID, Seq, Length)
{
	setType(t);
}


void RNA::printInfo(std::ostream& os)
{
	os << "Label: " << label << "\t";
	os << "ID: " << accessID << "\t";
	os << "Sequence: " << sequence << "\t";
	os << "Length: " << seqLength << "\t";
	os << "Type: " << getType() << "\n\n";
}