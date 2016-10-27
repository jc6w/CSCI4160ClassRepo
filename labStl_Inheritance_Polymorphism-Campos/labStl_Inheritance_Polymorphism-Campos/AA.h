#ifndef AA_H
#define AA_H


#include "Sequence.h"
#include <string>
using std::string;

class AA:public Sequence
{
private:
	int ORF;

public:
	
	void setORF(int orf) {ORF = orf;}
	int getORF() {return ORF;}

	AA();
	AA(string, int, string, int, int);
	
	void printInfo(std::ostream& os)override;
};

#endif