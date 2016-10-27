#include "ClassBidDatabase.h"

const string defaultInput = "registrationBid.txt";
const string defaultOutput = "listOfClassesFilled.txt";

int main() {
	string inputFilename;
	string outputFilename;

	int capacity = 15;
	
	string cap;
	
	//  defaultInput if pressing enter, else, cin filename
	cout << "Please enter the input filename (to use " << defaultInput << ", press enter)\n";
	getline(cin, inputFilename);
	if (inputFilename == "") {
		inputFilename = defaultInput;
	}

	//defaultOutput if pressing enter, else, cin filename
	cout << "Please enter the output filename (to use " << defaultOutput << ", press enter)\n";
	getline(cin, outputFilename);
	if (outputFilename == "") {
		outputFilename = defaultOutput;
	}

	//capacity if pressing enter, else, cin capacity
	
	cout << "Please enter the maximum amount for all classes (to use " << capacity << ", press enter)\n";
	getline(cin, cap);
	if (cap == "") {
		capacity = capacity;
	}
	else
	{
		capacity = stoi(cap);
	}
	ClassBidDatabase entries(outputFilename);
	entries.importEntries(inputFilename, capacity);

	return 0;
}