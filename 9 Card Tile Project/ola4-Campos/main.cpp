#include "CardBoardGame.h"

const string defaultInput= "ola4data.txt";

int main()
{
	//for grabbing from file
	string inputName;

	//  defaultInput if pressing enter, else, cin filename
	cout << "Please enter the input filename (to use " << defaultInput << ", press enter)\n";
	getline(cin, inputName);
	if (inputName == "") {
		inputName = defaultInput;
	}

	cardBoardGame newGame;
	newGame.importEntries(inputName);

	return 0;
}
