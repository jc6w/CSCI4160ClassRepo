#include <iostream>
#include <string>
#include <fstream>
using std::cerr;
using std::cout;
using std::cin;
using std::getline;
using std::ifstream;
using std::string;
#define MAXSIZE (100)

const string defaultInput = "ola3data.txt";

//functions for  recursion
void permuteString(char[], int, int);
bool primeOrNot(int, int);
bool traverseMaze(char[][MAXSIZE],int, int, int, int, int, int, int[][MAXSIZE]);
//for checking if value is within maze's bounds
bool mazeSafe(char[][MAXSIZE],int, int, int, int, int[][MAXSIZE]);
//swaps characters within the string
void swap(char[], int, int);

int main()
{
	//for grabbing from file
	ifstream openFile;
	string inputName;

	//variables to do permutation
	int numOfWords;
	string words;
	char* charArray;
	int stringLen;

	//variables for seeing if number is a prime number
	int numOfNums;
	int number;
	bool isPrimeNum = false;

	//to iterate and find a path on the maze
	int goalX, goalY;
	int startX, startY;
	int numRows, numCols;
	int solveMaze[MAXSIZE][MAXSIZE] = { 0 };
	char maze[MAXSIZE][MAXSIZE];
	bool mazeSuccess = false;

	//  defaultInput if pressing enter, else, cin filename
	cout << "Please enter the input filename (to use " << defaultInput << ", press enter)\n";
	getline(cin, inputName);
	if (inputName == "") {
		inputName = defaultInput;
	}


	openFile.open(inputName);
	if (!openFile.is_open())
	{
		cerr << "Unable to open input file";
		return -1;
	}
	while (!openFile.eof())
	{
		openFile >> numOfWords;
		cout << "Grabbing " <<  numOfWords << " words to recursively find its permutations.\n\n";
		for (int x = 0; x < numOfWords; x++)			//iterates through each word to permutate
		{
			openFile >> words;
			stringLen = words.size();					//grabs length of the word
			charArray = new char[MAXSIZE];
			charArray[stringLen];						//creates a new array of the same length
			//converts string to char
			for (int y = 0; y < stringLen; y++)
			{
				charArray[y] = words[y];
			}
			//pass to permutation function
			permuteString(charArray, 0, stringLen);
			cout << "\n";
		}

		openFile >> numOfNums;
		cout << "Grabbing " << numOfNums << " numbers to find if each one is a prime number or not.\n\n";
		for (int x = 0; x < numOfNums; x++)							//iterates to each number
		{
			openFile >> number;
			isPrimeNum = primeOrNot(number, number - 1);			//check if the number is prime
			if (isPrimeNum == true)
			{
				cout << number << " is a prime number.\n\n";
			}
			else
			{
				cout << number << " is not a prime number.\n\n";
			}
		}
		//size of matrix
		openFile >> numRows;
		openFile >> numCols;
		//starting points in matrix
		openFile >> startX;
		openFile >> startY;
		//goal points in matrix
		openFile >> goalX;
		openFile >> goalY;

		//recieve input and put in each proper place
		for (int x = 0; x < numRows; x++)
		{
			for (int y = 0; y < numCols; y++)
			{
				openFile >> maze[x][y];
			}
		}
		//stop any repeats just in case
		break;

	}

	cout << "Finding if there is a path to reach the goal in a " << numRows << " x " << numCols << " matrix.\n";
	maze[numRows][numCols];
	cout << "Start position: maze[" << startX << "][" << startY << "]\n";
	cout << "Goal position: maze[" << goalX << "][" << goalY << "]\n\n";

	//iterate through the maze, and come back with the solved, or unsolved answer
	mazeSuccess = traverseMaze(maze, startX, startY, goalX, goalY, numRows, numCols, solveMaze);

	if (mazeSuccess == false)
	{
		cout << "Solution does not exist.\n\n";
	}
	else
	{
		for (int x = 0; x < numRows; x++)
		{
			for (int y = 0; y < numCols; y++)
			{
				if (solveMaze[x][y] == 1)
				{
					cout << "+ ";
				}
				else if (solveMaze[x][y] == 0 && maze[x][y] == '#')
				{
					cout << "_ ";
				}
				else if (solveMaze[x][y] == 0 && maze[x][y] != '#')
				{
					cout << "/ ";
				}
			}
			cout << "\n";
		}

		//maze is shaped in twenty one pilots logo (for fun)
		cout << "THE FEW, THE PROUD, THE EMOTIONAL \n\n";
	}

	return 0;
}



void permuteString(char Array[], int start, int end)
{
	//if done, print array
	if (start == end-1)
	{
		for (int x = 0; x < end; x++)
		{
			cout << Array[x];
		}
		cout << "\n";
	}
	else
	{
		for (int x = start; x < end; x++)
		{
			swap(Array,start, x);						//swap elements
			permuteString(Array, start + 1, end);		//go through any middle swaps
			swap(Array, start, x);						//last swap (backtrack)
		}
	}
}

void swap(char Arr[], int a, int b)
{
	char temp = Arr[a];
	Arr[a] = Arr[b];
	Arr[b] = temp;
}

bool primeOrNot(int number, int	div)
{
	if (number < 2)									//number is 1 or 0; both neither prime nor composite
	{
		cout << "This number is less than 2.\n\n";
		return false;
	}

	if (div == 1)									//if modulus is 1 after all possibilites, then it is prime
	{
		return true;
	}

	if (number % div == 0)							//evenly divided by a number below it
	{
		return false;
	}
	
	return primeOrNot(number, div - 1);
}


bool mazeSafe(char maze[][MAXSIZE], int x, int y, int row, int col, int solve[][MAXSIZE])
{
	if (x >= 0 && y >= 0 && x <= row && y <= col && maze[x][y] =='.' && solve[x][y] == 0)	//along with other intel; if path is within the maze, then it is safe
	{
		return true;
	}

	return false;
}

bool traverseMaze(char maze[][MAXSIZE], int row, int col, int xGoal, int yGoal, int numR, int numC, int solved[][MAXSIZE])
{
	//base case
	if (row == xGoal && col == yGoal)
	{
		solved[row][col] = 1;
		return true;
	}


	if (mazeSafe(maze, row, col, numR, numC,solved) == true)
	{
		//marks poiont
		solved[row][col] = 1;
		if (traverseMaze(maze, row +1 , col, xGoal, yGoal, numR, numC, solved) == true)				//if there is a path below
		{
			return true;
		}
		else if (traverseMaze(maze, row, col + 1, xGoal, yGoal, numR, numC,solved) == true)			//if there is a path beside(to the right) the current position
		{
			return true;
		}
		else if (traverseMaze(maze, row - 1, col, xGoal, yGoal, numR, numC, solved) == true)		//if there is a path above the point
		{
			return true;
		}
		else if (traverseMaze(maze, row, col - 1, xGoal, yGoal, numR, numC, solved) == true)		//if there is a path beside(to the left) the current position 
		{
			return true;
		}

		solved[row][col] = 0;
		return false;
	}

	return false;

}



