/*
Filename: sequelDatabase.h
Author: Mae Campos
Description: to create SequelDatabase class, constructors, destructors, and methods
*/
#ifndef SEQUENCEDATABASE_H
#define SEQUENCEDATABASE_H
#include "DNA.h"
#include "DNAlist.h"
#include <iostream>
#include <fstream>
#include <string>
using std::ofstream;
using std::ifstream;
using std::string;

class SequenceDatabase
{
	private:
		DNAlist* dList;
        ofstream newFile;

	public:
		void setObj(DNAlist* dna) {dList = dna;}
		DNAlist* getObj() {return dList;}
			
		SequenceDatabase(); //default constructor
		SequenceDatabase(string); //opens an output file or overrides output file
	
		~SequenceDatabase(); //destructor for both ofstream and DNA pointer

		void importEntries(string); //imports data from file
		void dMethod(DNA*);			//to add entries
		void pMethod(int);	//to print an entry's information
		void oMethod(int);	//delete an entry
		void sMethod();			//how many entries

};
#endif