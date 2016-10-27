#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::stoll;
using std::string;
using std::to_string;

const int MAXSIZE = 200;

class BigInteger
{
private:
	string StringNum;
public:
	//sets number to the proper  variable
	void set(string b) { StringNum = b; }



	//constructors
	BigInteger();
	BigInteger(string);

	//member functions
	int mod(int);
	void display();






};












#endif