#ifndef DNA_H
#define DNA_H

#include "Sequence.h"
#include <string>
using std::string;

class DNA:public Sequence
{
private:
	int regCode;

public:
	void setCode(int code) {regCode = code;}
	int getCode() {return regCode;}

	DNA();
	DNA(string, int, string, int, int);

	void printInfo(std::ostream& os)override;
};




#endif