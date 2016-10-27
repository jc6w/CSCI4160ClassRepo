/****************************************************************************
*														 
*	Name:	Josephine Campos								 
*	Code: 	ola1											
*	Professor: Pettey										 
*	Purpose:	This program lets the user input how many nodes,		 
*			and its linked list representation and create various		 
*			infromation like adjacency matrices and knowing			 
*			which are isolated nodes, etc.						 
*														 
****************************************************************************/


#include <iostream>
using std::cout;
using std::cin;

//function prototypes to be used in menu
void printADJarray(int [10][10], int);
void ISOnodes(int [20][2], int);
void NODEdegree(int [10][10], int);
void NODEadjacent(int [10][10]);
void ADJrep(int [10][10], int);

int main ()
{
        //Variables to hold data in arrays
	int APTarray [20][2], ADJarray[10][10];
	
	
	//To hold user's input: how many number of nodes, number of rows, and which number of the menu they want to choose
	int  NODEnum, ROWnum, MENUnum;
	
	
	//This is to help for creation of the adjacency matrix
	int ROWnode;	
	
	
	//for looping purposes
	bool EXITLOOP = true;
	
	
	
	cout << "********Adjacency Matrices and Linked Lists********\n\n\n";
	cout << "Hello!\n\nPlease input the number of nodes: ";
	cin >> NODEnum;
	
	
	//this is to ensure that user does not go over 10 or go 0 and under
	while (NODEnum <= 0 || NODEnum > 10)
	{
		cout << "INVALID NUMBER! Please enter the number of nodes you are using.\n";
		cout << "It must be greater than 0 and less than or equal to 10: ";
		cin >>  NODEnum;
	}
	
	ADJarray[NODEnum][NODEnum];																//creates the exact number of rows needed by the user for the Adjacency matrix
	
	
	cout << "Please enter the number of rows in the array pointer representation: ";
	cin >> ROWnum;
	
	
	
	//this is to ensure that user does not go over 20 or go 0 and under for number of rows
	while (ROWnum <= 0 || ROWnum > 20)
	{
		cout << "INVALID NUMBER! Please enter the number of rows you have.\n";
		cout << "It must be greater than 0 and less than or equal to 20: ";
		cin >>  ROWnum;
	}
	
	APTarray [ROWnum][2];																	//creates the exact number of rows needed by the user for the Array pointer representation
	
	
	cout << " Please enter the array pointer representation:\n";
	
	for (int y = 0; y < ROWnum; y++)
	{
		for (int z = 0; z < 2; z++)
		{
			cin >> APTarray[y][z];
		}
	}
	cout << "\n";
	
	
	//Initializing the Adjacency Matrix
	for (int y = 0; y < NODEnum; y++)
	{
		for (int z = 0; z < NODEnum; z++)
		{
			ADJarray[y][z] = 0;
		}
	}
	
	//This is for creating the Adjacency Matrix	
	for (int y = 0; y < NODEnum; y++)
	{
		if (APTarray[y][1] !=-1)																	//checks if the row is an isolated node or not
		{
			
			ROWnode = APTarray[y][1] - 1;
			ADJarray[y][APTarray[ROWnode][0] -1] = 1;											//puts a 1 if there is adjacency on the first node
			
			while (APTarray[ROWnode][1]  != -1)
			{
				ROWnode++;
				ADJarray[y][APTarray[ROWnode][0] -1] = 1;										//puts a 1 if there is an adjacent node within the same row
			}
		}	
	
	}
	
	
	//Using switch statement and while loop to create menu
	while (EXITLOOP)
	{
		cout << "What would you like to do now?\n\n";
		cout << "1. Print the adjacency matrix\n";
		cout << "2. Determine if there are any isolated nodes\n";
		cout << "3. Determine the degree of a node\n";
		cout << "4. Determine if one node is adjacent to another\n";
		cout << "5. Print an adjacency list representation\n";
		cout << "6. Quit\n";
		
		cin >> MENUnum;
		
		
		switch(MENUnum)
		{
			case 1:	printADJarray(ADJarray, NODEnum);											// go to function printADJarray
					EXITLOOP = true;
					break;
			case 2:	ISOnodes (APTarray, NODEnum);												// go to function ISOnodes
					EXITLOOP = true;
					break;
			case 3:	NODEdegree(ADJarray, NODEnum);											// go to function NODEdegree
					EXITLOOP = true;
					break;
			case 4:	NODEadjacent(ADJarray);													// go to function NODEadjacent
					EXITLOOP = true;
					break;
			case 5:	ADJrep(ADJarray, NODEnum);												// go to function ADJrep
					EXITLOOP = true;
					break;
			case 6:	cout << "\n\nGoodbye\n\n";
					EXITLOOP = false;
					break;
			default: 	cout << "PLEASE CHOOSE ONLY THE NUMBERS IN THE MENU!!!!\n\n";				//checks for any number greater than 6 or less than 1
					EXITLOOP = true;
		}
	}
	
		
        return 0;
}



//This is to print the Adjacency Matrix
void printADJarray(int ADJarray[10][10], int node)
{
	cout << "\nThe adjacency matrix is:\n\n";
	for (int y = 0; y < node; y++)
	{
		for (int z = 0; z < node; z++)
		{
			cout << ADJarray[y][z];
		}
		cout << "\n";
	}
	cout <<"\n";
}


//This is to determine if any nodes are isolated
void ISOnodes(int APTarray[20][2], int node)
{
	cout << "\n";
	bool NOisoNode = true;														//checks to see if there are any isolated nodes
	for (int x = 0; x < node; x++)
	{
		if ( APTarray[x][1] == -1)
		{
			cout << x+1 << " is an isolated node\n";
			NOisoNode = false;
		}
	}
	
	if (NOisoNode == true)														//prints if and only if none of the rows are isolated
	{
		cout << "There are no isolated nodes.\n";
	}
	
	cout << "\n\n";
}


//This is to determine the degree of the node
void NODEdegree(int ADJarray[10][10], int NODEmax)
{
	int degreeSUM = 0, degree = 0, node;
	
	cout << "\n\nInput the node in question: ";
	cin >> node;																	//User inputs of what node they want to check
	
	for (int y = 0; y < NODEmax; y++)
	{
		if ( y == (node-1))
		{
			degree = (ADJarray[node -1][y] )* 2;										//doubles the number if the node has a loop (1 on the main diagonal)
		}
		else
		{
			degree = (ADJarray[node -1][y]);
		}
		
		degreeSUM += degree;														//adds all the 1's (and any loops) on the row of the node inquestion 
	}
	cout << "The degree of Node " << node << " is " << degreeSUM << "\n\n";
}

//This is to show if the first node and the second node is adjacent to each other
void NODEadjacent(int ADJarray[10][10])
{
	 int node1, node2;
	
	
	cout <<"\n\nInput the two nodes:\n";
	cin >> node1;
	cin >> node2;
	
	if ( node1 == node2 && ADJarray[node1 -1][node2 -1] == 1) 							//if there is a 1 on the main diagonal
	{
		cout << node1  << " is adjacent to itself (a loop)\n";
	}
	else if (ADJarray[node1 -1][node2 -1] == 1)
	{
		cout << node1 << " is adjacent to " << node2 << "\n\n";
	}
	else 
	{
		cout << node1 << " is NOT adjacent to " << node2 << "\n\n";
	}
}

//This is to show the Linked list representation via Adjacency Matrix
void ADJrep(int ADJarray[10][10], int node)
{
	cout << "\n";
	for (int y = 0; y < node; y++)
	{
		cout << y+1 << " ";														//prints what node on the row
		
		for (int z = 0; z < node; z++)
		{
			 if (ADJarray[y][z] == 1)
			{
				cout << z+1 << " ";												//prints all nodes that have a 1 within the row
			}
		}
		cout << "\n";
	}
	cout << "\n";
}


