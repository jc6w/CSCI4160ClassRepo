/****************************************************************************
*														 
*	Name:	Josephine Campos								 
*	Code: 	ola3											
*	Professor: Pettey										 
*	Purpose:	This program lets the user input how many instructions,		 
*			and what is the initial tape, and how many steps to make the  
*			Turing machine run on the tape. It outputs what the tape 
*														 
****************************************************************************/

#include <iostream>
#include<iomanip>
using std::cout;
using std::cin;
using std::fill_n;

void runTape(char [50], char [20][5], char, int, int);

int main()
{
	
	//Variables to hold tape and instruction data in arrays
	char tape[50], TuringInstruct[20][5];

	//to initialize all spots in tape with 'b'
	fill_n(tape, 50, 'b');
	
	//To hold user's input: how many number of steps in the TuringInstruct, tape element and maximum run of the steps
	int TuringStep,MAXrun;
	char  blank, Telement;

	//to hold starting state, halting state, and number of initialized elements in the tape
	char startState = '0', haltState = '0';
	int InitNum = 0;

	
	
	
	cout << "********Turing Machines********\n\n\n";
	cout << "Hello!\n\nPlease input the number of quintuples:    ";
	cin >> TuringStep;
	
	//checks for input
	while (TuringStep < 0 || TuringStep > 20)
	{
		cout << "\n\nINVALID NUMBER! Please enter the number of quintuples you have.\n";
		cout << "It must be greater than 0 and less than or equal to 20: ";
		cin >>  TuringStep;
	}
	
	
	
	TuringInstruct[TuringStep][5];


	//for inputting the turing steps
	cout << "Please input the " << TuringStep << " quintuple(s):\n";
	for (int x = 0; x < TuringStep; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			cin >> TuringInstruct[x][y];
		}
	}
	
	//to catch the '\n' made by the cin before
	cin.get();
	//to initialize the tape
	cout << "Please input the initial tape configuration (Enter to stop inputting into the tape):\n";

	//skips the rest of initialization if there is no tape
	
	if(cin.get() == '\n')
	{
		InitNum ++;
	}
	else
	{
		cin.get();
		while ( Telement!= '\n')
		{	
			cin >> Telement;
			tape[InitNum] = Telement;
			InitNum++;
			if(cin.get() == '\n')
			{
				break;
			}
		}
	}
	
	
	
	cout << "Please input the maximum number of steps:  ";
	cin >> MAXrun;
	
	
	cout << "initial tape ";
	for ( int x = 0; x < InitNum; x++)
	{
		cout << tape[x] << " ";		
	}
	cout << "start state " << startState << "\n";
	
	runTape( tape, TuringInstruct, startState, InitNum, MAXrun);
	


	return 0;
	
}



void runTape(char tape[50], char turing[20][5], char start, int inNum, int max)
{
	//for running the tape: current state, moving within tape
	char currentState = start;
	int moveTape = 0,moveInstruct, biggerNum = inNum;
	int loopNum = 0;
	
	
	//keeps doing instructions until it reaches the maximum alloted steps
	while (loopNum <= max)
	{
		 moveInstruct = 0;
		
		//looks for the correct state
		while(currentState != turing[moveInstruct][0])
		{
			moveInstruct++;
		}
		
		//looks for the correct input within found states
		while(turing[moveInstruct][1] != tape[moveTape] && turing[moveInstruct][0] == currentState)
		{
			moveInstruct++;
		}
		
		//breaks out of the function if there are no more rules that matches the input of the tape
		if(turing[moveInstruct][1] != tape[moveTape])
		{
			
			break;
		}
		
		tape[moveTape] = turing[moveInstruct][2];
		
		if( moveTape >= biggerNum)
		{
			biggerNum++;
		}
		switch (toupper(turing[moveInstruct][4]))
		{
			case 'L':moveTape--;
					break;
			case 'R':moveTape++;
					break;
			default:cout << "THIS SHOULD NOT EVEN HAPPEN!!!!\n\n\n\n";
					break;
		}
		cout << "tape ";
		for ( int x = 0; x < biggerNum; x++)
		{
			cout  << tape[x] << " ";
		}
		
		currentState = turing[moveInstruct][3];
		cout << " state " <<  currentState << "\n";
		
		
		loopNum++;
	}
}



