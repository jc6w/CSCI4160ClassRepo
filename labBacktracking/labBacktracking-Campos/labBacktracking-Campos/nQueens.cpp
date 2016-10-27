#include "nQueens.h"
#include <fstream>
using std::cout;
using std::ofstream;
using std::ostream;
using std::cerr;



void printNQueensSolution(int number, string outputName)
{
	int NQueenMat[MAX_SIZE][MAX_SIZE] = {0};
	ofstream openFile;
	bool Solved;

	openFile.open(outputName);
	if(!openFile.is_open())
	{
		cerr << "Unable to open  output file";
	}

	//goes to function to solve via backtracking
	Solved = solveNQ(0,number,NQueenMat);

	if(Solved == false)
	{
		openFile << "No solution possible for N queens!\n\n";
		return;
	}
	else
	{
		openFile << "Solved solution for " << number << " queens:\n";
		for(int i = 0; i < number; ++i)
		{
			for(int j = 0; j < number; ++j)
			{
				if(NQueenMat[i][j] == 1)
				{
					openFile << "Q ";
				}
				else
				{
					openFile << "- ";
				}
			}
			openFile << "\n";
		}


	}
	
}

bool solveNQ(int pos, int num, int mat[MAX_SIZE][MAX_SIZE]) /***BACTRACKING HERE***/
{
	//if the function has gone through all of the numbers and placed the queen
	if(pos >= num)
	{
		return true;
	}
	else
	{
		//for each queen(including the first one!)
		for(int x = 0; x < num; ++x)
		{
			//if the position of the queen does not conflict with past queen's position
			if(isGood(x,pos,num,mat) == true)
			{
				mat[x][pos] = 1;
				//recursively call to check position of new queen to place is good
				if(solveNQ(pos +1, num, mat) == true) 
				{
					return true;
				}
				//puts the queen away again to put in new position
				mat[x][pos] = 0;
			}
		}
	
	return false;
}






}
//checks to see if the position in the array is good
bool isGood(int row, int col,int maxNum, int mat[MAX_SIZE][MAX_SIZE])
{
	int checkRow, checkCol;
	//if the new queen is in the same row 
	for(checkCol = 0; checkCol < maxNum; ++checkCol)
	{
		if(mat[row][checkCol])
		{
			return false;
		}
	}
	
	//if the new queen is in the same left diagonal as another queen
	checkRow = row;
	checkCol = col;
	while(checkRow >=0 && checkCol >= 0)
	{
		if(mat[checkRow][checkCol])
		{
			return false;
		}
		--checkRow;
		--checkCol;
	}
	
	//if the new queen is in the same right diagonal as another queen
	checkRow = row;
	checkCol = col;
	while(checkRow < maxNum && checkCol >= 0)
	{
		if(mat[checkRow][checkCol])
		{
			return false;
		}
		++checkRow;
		--checkCol;
	}

	return true;
}

