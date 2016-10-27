/*
Filename: DNA.cpp
Author: Mae Campos
Description: to establish default constructor and overload << operator
*/
#include "DNA.h"
#include "sequenceDatabase.h"
#include <iostream>
#include <fstream>
using std::cout;

//default constructor
DNA::DNA()
{
	setLabel(" ");
    setID(0);
    setSeq(" ");
    setLength(0);
	setCode(-1);
}

//overloading constructor
DNA::DNA(string label, int accessID, string sequence, int seqLength, int regCode)
{
	label = " ";
	accessID = 0;
	sequence = " ";
	seqLength= 0;
	regCode = -1;
}


