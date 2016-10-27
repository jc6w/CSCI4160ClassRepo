/***********************************************
PROGRAMMER:		Mae Campos
PROGRAM:		BigInteger
DUE DATE:		Wednesday 8/14/16
INSTRUCTOR:		Dr. Yoo

DESCRIPTION:
program that finds the remainder of a very long integer (D mod divider)
************************************************/

#include "bigInteger.h" // be careful when you copy/paste this code : “ may not work properly



int main()

{

	int divider = 97; //two digit number

	string str;

	int remainder;

	BigInteger big("7234987645791286234124781481841814812481247");

	big.display();

	remainder = big.mod(divider);

	cout << " remainder is " << remainder << endl;

	cout << "Enter long integer of any length : ";

	cin >> str;

	big.set(str);

	big.display();

	remainder = big.mod(divider);

	cout << " remainder is " << remainder << endl;

	return 0;

}