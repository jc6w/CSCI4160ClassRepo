/*
Filename: DNAlist.cpp
Author: Mae Campos
Description: to establish constructors and member functions
*/

#include "DNAlist.h"
#include "DNA.h"

//constructor
DNAlist::DNAlist()
{
	newNode = nullptr;
	m_size = 0;
}

//destructor
DNAlist::~DNAlist()
{
	DNAnode* byeNode = newNode;
	while (newNode!= NULL)		//cycles through all the nodes
	{
		newNode = newNode->next;	//pushes the node forward
		byeNode->next = NULL;		
		delete byeNode->dnaptr;		//deletes node's information
		delete byeNode;				//deletes node
		m_size--;					//decrements size
		byeNode = newNode;
	}
}

//member functions

//inserts node
void DNAlist::push_back(DNA* obj)
{
	DNAnode* node =new DNAnode;	//establishes head node
	DNAnode* current;
	node->dnaptr = obj;				//creates a node
	node->next = NULL;
	
	if(newNode == NULL)
	{
		newNode = node;
		m_size++;
	}
	else
	{
		current = newNode;			//if there is a node, it pushes it to make room for the new node
		while (current->next!= NULL)
		{
			current= current->next;	
		}
		current->next= node;
		m_size++;
	}
}
//looking for ID
DNA* DNAlist::find(int ID)
{
	DNAnode* current;
	if (m_size == 0)		//if there is no list
	{
		return nullptr;
	}
	else
	{
		current = newNode;			//searches through the whole list
		while (current != NULL)
		{
			if(current->dnaptr->getID() == ID)		//if found, returns the ID
			{
				return current->dnaptr;
			}
			else
			{
				current = current->next;
			}

		}
		return nullptr;		//else if there is no node with that ID
	}
}

//returns true if ID is found, and deletes
bool DNAlist::obliterate(int ID)
{
	DNAnode *curr;
	DNAnode* prev = newNode;

	if(m_size == 0)			//if there is no list
	{
		return false;
	}
	else if(newNode->dnaptr->getID() == ID)
	{
		curr = newNode;
		newNode = curr->next;

		delete curr->dnaptr;
		delete curr;
		m_size--;
		return true;
	}
	else 
	{
		curr = newNode->next;
		while(curr!= NULL)
		{
			if(curr->dnaptr->getID()==ID)
			{
				prev->next=curr->next;
				delete curr->dnaptr;
				delete curr;
				m_size--;
				return true;

			}
			else
			{
				prev= curr;
				curr = curr->next;
			}
		}
			return false;
	}
}
//returns size of the node list
int DNAlist::size()
{
	return m_size;
}