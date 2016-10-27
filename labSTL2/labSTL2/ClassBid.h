#ifndef CLASSBID_H
#define CLASSBID_H

#include <iostream>
#include <fstream>
#include <map>
#include<algorithm>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::string;
using std::map;
using std::vector;
using std::pair;
using std::find;
using std::sort;
using std::cerr;
using std::ofstream;
using std::ifstream;
using std::ostream;
using std::stoi;
using std::getline;

class classBid
{
private:
	int numBid;
	string firstName;
	string lastName;
	string studentName;

public:

	//constructors
	classBid();
	classBid(int, string,string);

	//setters
	void setBid(int b) { numBid = b; }
	void setName(string f, string l) { firstName = f; lastName = l; studentName = f + " " + l; }

	//getters
	int getBid() const { return numBid; }
	string getName() { return studentName; }

	void print(ostream& os); 

	//to overload > operator for comparing between elements in vector
	bool operator > (const classBid* rhs) const
	{
		return (numBid > rhs->numBid);
	}

};



#endif