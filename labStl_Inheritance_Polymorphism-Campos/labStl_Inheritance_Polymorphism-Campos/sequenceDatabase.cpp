#include "sequenceDatabase.h"
#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
#include "AA.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <algorithm>
using std::string;
using std::cout;
using std::cerr;
using std::ofstream;
using std::ifstream;
using std::ostream;
using std::find;


SequenceDatabase::SequenceDatabase(string outputName)
{
	newFile.open(outputName);
	if (!newFile.is_open())
	{
		cerr << "Unable to open  output file";
    }
}

SequenceDatabase::~SequenceDatabase()
{
	newFile.close();
}


//imports entries from text file unto a variable (via pointer for linkedLists)
void SequenceDatabase::importEntries(string inputName)
{
	list<Sequence*>::iterator it;
	//this is to help read each line in the text (linkedLists)

	it = databaseList.begin();

	//to set up polymorphic method calls
	Sequence* seq1;
	Sequence* seq2;
	Sequence* seq3;

	//variables to hold each parsed variable from file
	string label;
	int ID;
	string seq;
	int length;
	int code;
	string t;
	int ORF;
	char stream;

	//to open input file
    ifstream fromFile;

	fromFile.open(inputName);

	//if file is not there or could not be opened
	if (!fromFile.is_open())
	{
		cerr << "Unable to open input file";
        return;
    }
    

	newFile << "Importing " << inputName << " ...\n";
  
	while (!fromFile.eof())
    {
		fromFile >> stream; //grabs first letter to know which method to use
		
		if(fromFile.eof())
		{
			break;
		}
		else if (stream == 'D') //goes to dMethod
		{ 
			fromFile >> label;
			fromFile >> ID;
			fromFile >> seq;
			fromFile >> length;
			fromFile >> code;

			//stores variables to new DNA object;
			// *** polymorphic method call ***
			seq1 = new DNA(label, ID, seq, length, code);

			dMethod(seq1);
		}
		else if (stream == 'R') //goes to rMethod
		{ 
			fromFile >> label;
			fromFile >> ID;
			fromFile >> seq;
			fromFile >> length;
			fromFile >> t;

			//stores variables to new RNA object;
			// *** polymorphic method call ***
			seq2 = new RNA(label, ID, seq, length, t);

			rMethod(seq2);
		}
		else if (stream == 'A') //goes to aMethod
		{ 
			fromFile >> label;
			fromFile >> ID;
			fromFile >> seq;
			fromFile >> length;
			fromFile >> ORF;

			//stores variables to new AA object;
			// *** polymorphic method call ***
			if(ORF <= 2 && ORF >= -3)
			{
				seq3 = new AA(label, ID, seq, length, ORF);
				aMethod(seq3);
			}
			else
			{
				newFile << "INVALID ORF\n\n!";
			}
		}
		else if(stream == 'P')		//goes to pMethod
		{	
			fromFile >> ID;

			pMethod(ID);
		}
		else if(stream == 'O')		//goes to oMethod
		{
			fromFile >> ID;
			oMethod( ID);
		}
		else if (stream == 'S')		//goes to sMethod
		{
			sMethod();
		}
		else
		{
			newFile << "Not a valid code!\n\n";	//catches any other letter that could come through
		}
	}
}


//to add DNA entries
void SequenceDatabase::dMethod(Sequence* dna)
{
	newFile << "Adding " << dna->getID() << " ...\n\n";
	databaseList.push_back(dna);
}

//to add RNA entries
void SequenceDatabase::rMethod(Sequence* rna)
{
	newFile << "Adding " << rna->getID() << " ...\n\n";
	databaseList.push_back(rna);
}

//to add AA entries
void SequenceDatabase::aMethod(Sequence* aa)
{
	newFile << "Adding " << aa->getID() << " ...\n\n";
	databaseList.push_back(aa);
}

//to print an entry's information
void SequenceDatabase::pMethod(int ID)
{
	list<Sequence*>::iterator it = databaseList.begin();
	newFile << "Printing " << ID << " ...\n";

	if(databaseList.empty())
	{
		newFile << "Can not find item (" << ID << ")!\n\n";
	}
	else
	{
		while(it != databaseList.end())
		{
			if ((*it)->getID() == ID)
			{
				(*it)->printInfo(newFile);
				break;
			}
			++it;
			if(it == databaseList.end())
			{
				newFile << "Can not find item (" << ID << ")!\n\n";
				break;
			}
		}

	}
}

//delete an entry
void SequenceDatabase::oMethod(int ID)
{
	list<Sequence*>::iterator it = databaseList.begin();
	if(databaseList.empty())
	{
		newFile << "Obliterating " << ID << " ...\n";
		newFile << "Can not delete item (" << ID << "), NOT found!\n\n";
	}
	else
	{
		while(it != databaseList.end())
		{
			if ((*it)->getID() == ID)
			{
				newFile << "Obliterating " << ID << " ...\n\n";
				databaseList.erase(it);
				break;
			}
			++it;
			if(it == databaseList.end())
			{
				newFile << "Obliterating " << ID << " ...\n";
				newFile << "Can not find item (" << ID << ")!\n\n";
				break;
			}
		}
	}
}

//to find the list's size
void SequenceDatabase::sMethod()
{
	newFile << "Entries: " << databaseList.size() << " total\n\n";
}