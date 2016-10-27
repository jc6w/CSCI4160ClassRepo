#include "ClassBidDatabase.h"


//comparison function for sorting
bool greaterBid(classBid* a, classBid* b)
{
	return (a->getBid() > b->getBid());
}
//default constructor
ClassBidDatabase::ClassBidDatabase()
{

}
//overloading constructor
ClassBidDatabase::ClassBidDatabase(string outputName)
{
	newFile.open(outputName);
	if (!newFile.is_open())
	{
		cerr << "Unable to open  output file";
	}
}
//destructor
ClassBidDatabase::~ClassBidDatabase()
{
	newFile.close();
}
//grabs entries from the file and put into the database
void ClassBidDatabase::importEntries(string inputName, int capacity)
{
	vector<classBid*> classRoster;
	char bidOrDrop;
	int bidNum;
	string classNum;
	string firstName;
	string lastName;
	string fullName;
	classBid* bidder;


	//to open input file
	ifstream fromFile;

	fromFile.open(inputName);

	//if file is not there or could not be opened
	if (!fromFile.is_open())
	{
		cerr << "Unable to open input file";
		return;
	}

	while (!fromFile.eof())
	{
		//grabs the first letter on the line
		fromFile >> bidOrDrop;

		switch (bidOrDrop)
		{
		//if the letter is D, it goes to delete the Entry in another function
		case 'D':
			//reads from file and put in respective variables
			fromFile >> bidNum;
			fromFile >> classNum;
			fromFile >> firstName;
			fromFile >> lastName;

			fullName = firstName + " " + lastName;

			deleteEntry(classNum, fullName);
			break;

		//if the letter is D, it goes to insert the entry and sorts each time a new item is pushed to the vector
		case'B':
			//reads from file and put in respective variables
			fromFile >> bidNum;
			fromFile >> classNum;
			fromFile >> firstName;
			fromFile >> lastName;

			//puts data in a new student classBid
			bidder = new classBid(bidNum, firstName, lastName);

			//inserts the classNum and a new vector 
			databaseMap.insert(pair<string, vector<classBid*>>(classNum, classRoster));
			//pushes the student to the vector
			databaseMap[classNum].push_back(bidder);
			//sorts the whole vector within a specific classNum in descending order
			sort(databaseMap[classNum].begin(), databaseMap[classNum].end(), greaterBid);

		default:
			break;
		}

	}
	print(capacity);

}

//prints the whole list in an output .txt file
void ClassBidDatabase::print(int cap)
{
	map<string, vector<classBid*>>::iterator it = databaseMap.begin();
	vector<classBid*>::iterator it2;
	string classNum;

	if (databaseMap.empty())
	{
		newFile << "It's empty!\n\n";
	}
	else
	{
		while (it != databaseMap.end())
		{
			if (!it->second.empty())
			{
				classNum = it->first;
				//checks and drops students that have the lower bids and is past the capacity of the class
				if (databaseMap[classNum].size() > cap)
				{
					databaseMap[classNum].erase(databaseMap[classNum].begin() + cap, databaseMap[classNum].end());
				}
				newFile << it->first << "\t";
				//prints total entries in the class after dropping from overcapacity
				if (it->second.size() == 1)
				{
					newFile << it->second.size() << " total entry\n\n";
				}
				else
				{
					newFile << it->second.size() << " total entries\n\n";
				}
			}
			it2 = it->second.begin();
			//prints the whole vector 
			while (it2 != it->second.end())
			{
				(*it2)->print(newFile);
				it2++;
			}
			it++;
		}
	}


}

void ClassBidDatabase::deleteEntry(string classNum, string name)
{
	map<string, vector<classBid*>>::iterator it = databaseMap.begin();
	vector<classBid*>::iterator it2;

	if (databaseMap.empty())
	{
		newFile << "It's empty!\n\n";
	}
	else
	{
		while (it != databaseMap.end())
		{
			//sees if the class is in the map
			if (it->first == classNum)
			{
				it2 = it->second.begin();
				//looks for the student if class is found
				while (it2 != it->second.end())
				{
					if ((*it2)->getName() == name)
					{
						cout << name << " has dropped " << classNum << "\n\n";
						//drops the student from the class
						it->second.erase(it2);
						break;
					}
					it2++;
				}
				break;
			}
			it++;
		}
	}

}