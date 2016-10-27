#ifndef SEQUENCEDATABASE_H
#define SEQUENCEDATABASE_H

#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
#include "AA.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <list>
using std::list;
using std::ofstream;
using std::ifstream;
using std::string;

class SequenceDatabase
{
private:
	list<Sequence*> databaseList;
	ofstream newFile;

public:

	SequenceDatabase();
	SequenceDatabase(string);
	~SequenceDatabase();

	
	void importEntries(string);		//imports data from file
	void dMethod(Sequence*);				//to add DNA entries
	void rMethod(Sequence*);					//to add RNA entries
	void aMethod(Sequence*);					//to add AA entries
	void pMethod(int);				//to print an entry's information
	void oMethod(int);				//delete an entry
	void sMethod();					//how many entries



};


#endif