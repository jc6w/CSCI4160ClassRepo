#ifndef CLASSBIDDATABASE_H
#define CLSSBIDDATABASE_H

#include "ClassBid.h"

class ClassBidDatabase
{
private:
	map < string, vector<classBid*>> databaseMap;
	ofstream newFile;

public:
	ClassBidDatabase();
	ClassBidDatabase(string);

	~ClassBidDatabase();

	void importEntries(string, int);
	void deleteEntry(string, string);
	void print(int);

};


#endif