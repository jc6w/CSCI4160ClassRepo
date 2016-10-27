/*
Filename: DNAlist.h
Author: Mae Campos
Description: to create DNAlist class
*/

#ifndef DNALIST_H
#define DNALIST_H
#include "DNA.h"

struct DNAnode
{
		DNA* dnaptr;
		DNAnode* next;
};


class DNAlist
{

	private:
		DNAnode* newNode;
		int m_size;
	public:
		//constructors
		DNAlist();

		//destructor
		~DNAlist();

		//member function prototypes

		void push_back(DNA*);
		DNA* find(int);
		bool obliterate(int);
		int size();
};


#endif