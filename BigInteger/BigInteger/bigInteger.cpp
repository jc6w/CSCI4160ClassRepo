#include "bigInteger.h"

BigInteger::BigInteger()
{
}

BigInteger::BigInteger(string num)
{
	StringNum = num;
}

//member functions
int BigInteger::mod(int d)
{
	int remainder;
	int Total = 0;
	int x = 0;
	string subNum;

	while ( x < StringNum.length())
	{
		Total = (9 - subNum.length());
		subNum += StringNum.substr(x, Total);
		remainder = stoi(subNum) % d;
		subNum = to_string(remainder);
		x += Total;
	}
	return remainder;
}

void BigInteger::display()
{
	cout << "Number String:\n" << StringNum << "\n\n";
}