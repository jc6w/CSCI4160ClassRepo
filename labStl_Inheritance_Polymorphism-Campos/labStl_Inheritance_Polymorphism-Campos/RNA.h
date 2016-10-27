#ifndef RNA_H
#define RNA_H

#include "Sequence.h"
#include <string>
using std::string;

class RNA:public Sequence
{
private:
	enum RNA_t {mRNA = 0,rRNA, tRNA}type;

public:
	
	void setType(string);
	string getType();

	RNA();
	RNA(string, int, string, int, string);
	
	void printInfo(std::ostream& os)override;
};


#endif