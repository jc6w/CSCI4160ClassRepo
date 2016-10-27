#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <ostream>
#include <string>
using std::string;


class Sequence
{
protected:
	string label;
	int accessID;
	string sequence;
	int seqLength;

public:
	//setters
	void setLabel(string l) { label = l;}
	void setID(int id) { accessID = id;}
	void setSeq(string seq) { sequence = seq;}
	void setLength(int length) { seqLength = length;}

	//getters
	string getLabel() {return label;}
	int getID() {return accessID;}
	string getSeq() {return sequence;}
	int getLength() {return seqLength;}

	//constructors
	Sequence();

	Sequence(string, int, string, int);


	friend std::ostream& operator<<  (std::ostream& os, Sequence & seq)
	{
		seq.printInfo(os);
		return os;
	}

	virtual void printInfo(std::ostream& os);


};



#endif