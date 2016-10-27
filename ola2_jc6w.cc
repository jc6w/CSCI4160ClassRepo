/****************************************************************************
*														 
*	Name:	Josephine Campos								 
*	Code: 	ola2											
*	Professor: Pettey										 
*	Purpose:	This program lets the user input A tree with left, middle, and right children.		 
*			And output its preorder, postorder, and inorder representation and create various		 
*			infromation like adjacency matrices and array representation.						 
*														 
****************************************************************************/

#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::setw;

//function prototypes to be used in menu
void	InputArray(int[10][10], int[10][3], int);
void printArray(int [10][10],int [10][3], int);
void PREOrder(int [10][3], int);
void POSTOrder(int [10][3], int);
void INOrder(int [10][3], int);

int main ()
{
        //Variables to hold data in arrays
	int LMRChildArray [10][3], ADJarray[10][10];
	
	
	//To hold user's input: how many number of nodes
	int  NODEnum;
	
	
	
	
	cout << "********Left Middle and Right, and Order Representations********\n\n\n";
	cout << "Hello!\n\nPlease input the number of nodes: ";
	cin >> NODEnum;
	
	
	//this is to ensure that user does not go over 10 or go 0 and under
	while (NODEnum <= 0 || NODEnum > 10)
	{
		cout << "INVALID NUMBER! Please enter the number of nodes you are using.\n";
		cout << "It must be greater than 0 and less than or equal to 10: ";
		cin >>  NODEnum;
	}
	
	
	//go to function InputArray
	InputArray(ADJarray, LMRChildArray, NODEnum);
	
	// go to function printArray
	printArray(ADJarray, LMRChildArray, NODEnum);
	
	
	cout << "\n\nThe Preorder traversal is:\n";
	// go to function PREOrder
	PREOrder(LMRChildArray, 0);


	cout << "\n\nThe Inorder traversal is:\n";
	// go to function INOrder
	INOrder(LMRChildArray, 0);


	cout << "\n\nThe Postorder traversal is:\n";
	// go to function POSTOrder
	POSTOrder(LMRChildArray, 0);
	
	cout << "\n\n";
	
        return 0;
}

void InputArray(int ADJarray[10][10], int LMRArray[10][3], int node)
{
	//creates the exact number of rows needed by the user for the Adjacency matrix
	ADJarray[node][node];
	
	//creates the exact number of rows needed by the user for the child representation
	LMRArray [node][3];
	
	//This is to help for creation of the adjacency matrix
	int ROWnode;													
	
	
	cout << "\n\nPlease enter the Left, Middle, then Right child for each node:\n";
	
	for (int y = 0; y < node; y++)
	{
		cout << "Node " << y + 1 << ": ";
		for (int z = 0; z < 3; z++)
		{
			cin >> LMRArray[y][z];
		}
	}
	cout << "\n";
	
	
	//Initializing the Adjacency Matrix
	for (int y = 0; y < node; y++)
	{
		for (int z = 0; z < node; z++)
		{
			ADJarray[y][z] = 0;
		}
	}
	
	//This is for creating the Adjacency Matrix	
	for (int y = 0; y < node; y++)
	{
		for (int z = 0; z < 3; z++)
		{
			//checks if the row has all -1s or not
			if (LMRArray[y][z] != -1)
			{
				ROWnode = LMRArray[y][z] -1;
				
				//puts a 1 if there is adjacency on the first node
				ADJarray[y][ROWnode] = 1;
				
			}	
		}
	}
}

//This is to print the Adjacency Matrix and the Left Middle Right Child Representation
void printArray(int ADJarray[10][10], int LMRArray[10][3], int node)
{
	cout << "The adjacency matrix is:\n\n";
	
	for (int y = 0; y < node; y++)
	{
		for (int z = 0; z < node; z++)
		{
			cout << setw(3) << ADJarray[y][z];
		}
		cout << "\n";
	}
	cout <<"\n";
	
	cout << "\n\nThe left child, middle child, right child representation is:\n\n";
	
	for (int y = 0; y < node; y++)
	{
		
		for (int z = 0; z < 3; z++)
		{
			cout << setw(5) << LMRArray[y][z] ;
		}
		cout << "\n";
	}
}


//This is to determine the preorder of the tree
void PREOrder(int LMRarray[10][3], int node)
{
	int nextNODE;	
	
	cout << node + 1  << " ";
	
	for ( int y = 0; y < 3; y++)
	{
		if (LMRarray[node][y] != -1)
		{
			nextNODE = LMRarray[node][y] -1;
			PREOrder(LMRarray, nextNODE);
		}
	}
}



//This is to determine the postorder of the tree
void POSTOrder(int LMRarray[10][3], int node)
{
	
	int nextNODE;	
	
	for ( int y = 0; y < 3; y++)
	{
		if (LMRarray[node][y] != -1)
		{
			nextNODE = LMRarray[node][y] -1;
			POSTOrder(LMRarray, nextNODE);
		}
	}
	
	cout << node + 1 << " ";
	
	
}

//This is to determine the inorder of the tree
void INOrder(int LMRarray[10][3], int node)
{
	int nextNODE;	
	
	if (LMRarray[node][0] != -1)
	{
		nextNODE = LMRarray[node][0] -1;
		INOrder(LMRarray, nextNODE);
	}
		
	cout << node + 1 << " ";
		
	for ( int y = 1; y < 3; y++)
	{
		if (LMRarray[node][y] != -1)
		{
			nextNODE = LMRarray[node][y] -1;
			INOrder(LMRarray, nextNODE);
		}
	}

}

