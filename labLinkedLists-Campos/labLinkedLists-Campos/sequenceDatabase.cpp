/*
Filename: sequenceDatabase.cpp 
Author: Mae Campos
Description: to open a file, read and allocate parsed inputs to a DNA object, and write on output files
*/
#include "DNA.h"
#include "sequenceDatabase.h"
#include "DNAlist.h"
#include <iostream>
#include <string>
#include <fstream>
using std::string;
using std::cout;
using std::cerr;
using std::ofstream;
using std::ifstream;
using std::getline;


//default constructor
SequenceDatabase::SequenceDatabase()
{
	dList = new DNAlist;
}

//parameterized constructor; opens the file for output
SequenceDatabase::SequenceDatabase(string outputName)
{
	dList = new DNAlist;
	newFile.open(outputName);

	if (!newFile.is_open())
	{
		cerr << "Unable to open  output file";
    }
}

//destructor and closes output file
SequenceDatabase::~SequenceDatabase()
{
	delete dList;
    newFile.close();
}

//imports entries from text file unto a variable (via pointer for linkedLists)
void SequenceDatabase::importEntries(string inputName)
{
	//this is to help read each line in the text (linkedLists)

	DNA* toList = new DNA;

	//variables to hold each parsed variable from file
	string label;
	int ID;
	string seq;
	int length;
	int code;
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
			toList = new DNA;
			toList->setLabel(label);
			toList->setID(ID);
			toList->setSeq(seq);
			toList->setLength(length);
			toList->setCode(code);

			dMethod(toList);
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
			cout << "Not a valid code!\n\n";	//catches any other letter that could come through
		}

	}

    newFile.close();
}


//d Method function; adds a new node
void SequenceDatabase::dMethod( DNA* object)
{
	newFile << "Adding " << object->getID() << " ...\n\n";
	dList->push_back(object);
}

//p Method function; prints out the information from the ID
void SequenceDatabase::pMethod( int ID)
{
	newFile << "Printing " << ID << " ...\n";

	DNA* hey = dList->find(ID);

	if(hey == nullptr)
	{
		newFile << "Can not find item (" << ID << ")!\n\n";
	}
	else
	{
		newFile <<  "DNA:\t" << *hey;
	}
}

//o Method function; deletes information
void SequenceDatabase::oMethod(int ID)
{
	bool YesNo = dList->obliterate(ID);
	
	if(YesNo == false)
	{
		newFile << "Obliterating " << ID << " ...\n";
		newFile << "Can not delete DNA (" << ID << "), NOT found!\n\n";
	}
	else
	{
		newFile << "Obliterating " << ID << " ...\n\n";
	}
}

//s Method function; how many entries are in the list
void SequenceDatabase::sMethod()
{
	int Listsize = dList->size();
	newFile << "Entries: " << Listsize << "\n\n";
}

	
