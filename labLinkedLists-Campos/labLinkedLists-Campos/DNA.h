/*
Filename: DNA.h
Author: Mae Campos
Description: to create DNA class
*/

#ifndef DNA_H
#define DNA_H
#include<ostream>
#include <string>
using std::string;

class DNA
{
	private:
		string label;
		int accessID;
		string sequence;
		int seqLength;
		int regCode;

	public:
		//setters
		void setLabel(string l) { label = l;}
		void setID(int id) { accessID = id;}
		void setSeq(string seq) { sequence = seq;}
		void setLength(int length) { seqLength = length;}
		void setCode(int code) {regCode = code;}

		//getters
		string getLabel() {return label;}
		int getID() {return accessID;}
		string getSeq() {return sequence;}
		int getLength() {return seqLength;}
		int getCode() {return regCode;}
	
		//constructors
		DNA();
		DNA(string, int, string, int, int);
		
		//overloading operator
		friend std::ostream& operator<<  (std::ostream& os, DNA & dn)
		{
			dn.print(os);
			return os;
		}

		//print function

		void print(std::ostream& os)
		{
			os << "Label: " << label << "\t";
			os << "ID: " << accessID << "\t";
			os << "Sequence: " << sequence << "\t";
			os << "Length: " << seqLength << "\t";
			os << "cDNAStartIndex: " << regCode << "\n\n";


		}
};


#endif