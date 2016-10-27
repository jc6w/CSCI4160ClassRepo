/*********************************************************************
*
*        program name:      LinkedListDelete.cpp
*        author:            Mae Campos
*        date:              03/30/2015 
*        remarks:           
*                
*********************************************************************/
 
/*********************************
*  libraries here
**********************************/
#include <iostream>
//#include <conio.h>
using namespace std;
 
/*********************************
*   class definition
**********************************/
class Node
{
  private:
     // data items
     int*  number;               // number  
     Node* next;                // Node pointer  forward
     Node* prev;                // Node pointer  back
 
  public:
     /*************************************
     *   public data items and functions
     *************************************/
     // constructor
     Node(int);
 
     // destructor
     ~Node();  
   
     // member functions prototypes
     void setNext(Node* Node)    {next = Node;}
     void setPrev(Node* Node)    {prev = Node;}
     void  setNumber(int x)       {*number = x;}
      
     Node* getNext()             {return next;}
     Node* getPrev()             {return prev;}
     int   getNumber()           {return *number;}
   
     void display(Node* current);
}; 
 
/*********************
*   member functions
*********************/
Node :: Node (int num)
{
     number = new int();
     setNumber(num);
     setNext(NULL);
     setPrev(NULL);      
}
 
Node :: ~Node()
{
     delete number;     
}
 
/**********************************
*      list current node
*      previous node
*      next node
*      number held by the node
**********************************/
void Node :: display(Node* current)
{
    cout << "\n";
    cout << "number       " << getNumber() << "\n";
    cout << "prev Node    " << getPrev()   << "\n";
    cout << "next Node    " << getNext()   << "\n";
    cout << "current Node " << current     << "\n";   
    cout << "\n";
}
 
 
/*********************
*   PROTOTYPES
*********************/
Node* LoadLinkedList();
void  traverseList(Node**);
void  deleteNode(Node**, int);
void  insertNode(Node**, int);
void  testDeleteNode(Node**);
void  testInsertNode(Node**);
/*********************
*   main
*********************/
int main()
{
    // address of the beginning of the linked list
    Node* start;  
    // pointer to the address of the beginning of the LinkedList
    Node** ptrStart;
     
    // load the linked list
    // save beginning of the linked list in start     
    start = LoadLinkedList();
    ptrStart = &start;
     
 
    // print out the linkrd list
    // starting at 'start' (the beginning)
    // traverseList(ptrStart);
     
    // run the test code for the testInsertNode function
    testInsertNode(ptrStart);   
     
    // run the test code for the testDeleteNode function
     //testDeleteNode(ptrStart); 
     
    cout << "\n";
    return 0;
}
 
/*****************************
*  print out the linked list
*****************************/
void traverseList(Node** start)
{
     Node* current;
     current = *start;
     cout << "\n\n*** Linked List ***\n";
     current->display(current);
     while(current->getNext() != NULL)
     {
        current = current->getNext();
        current->display(current);
     }
 
}
 
/***************************************
*  delete a Node from the linked list
***************************************/
void deleteNode(Node** start, int numDelete)
{
     Node* current;
     current = *start;    
     while(current->getNumber() != numDelete && current->getNext() != NULL)
     {
        current = current->getNext();
     } 
     cout << "\n\nlooking for " << numDelete << "\n stopped at " << current->getNumber() << "\n";
     current->display(current);
      
     if (numDelete != current->getNumber())
     {
                   cout << "MISMATCH! NO NODES WITH THIS NUMBER!\n\n";
     }
     else if(current->getPrev() == NULL)
     {
           
          current->getNext()->setPrev(NULL);
          *start = current->getNext();
          cout << "YOU HAVE DELETED THE FIRST NODE\n\n";
           
     }
     else if(current->getNext() == NULL)
     {
          current->getPrev()->setNext(NULL);
          cout << "YOU HAVE DELETED THE LAST NODE\n\n";
     }
     else
     {
         current->getNext()->setPrev(current ->getPrev());
         current->getPrev()->setNext(current ->getNext());
         cout << "YOU HAVE DELETED NODE: " << current->getNumber()<< "\n\n";
     }
        
}
 
/**************************************
*  insert a Node into the linked list
**************************************/
void insertNode(Node** start, int numInsert)
{
     Node* current;
     current = *start;
     Node* temp;
     
     // following while loop should / stop on the proper node
     /*********************************************************************************/
     while(numInsert > current->getNumber() && current->getNext() != NULL)
     {
        current = current->getNext();
     } 
     cout << "\n\nadd node " << numInsert << "\n";
     current->display(current); 
     /*********************************************************************************************/
      
     // ifststement showing you know where you are
      
     if (numInsert == current->getNumber())
     {
                   cout << "THERE IS A NODE WITH THIS NUMBER ALREADY! WILL NOT DUPLICATE\n\n";
     }
     else if(current->getNext() == NULL)
     {
          if (current->getNumber() > numInsert)
          {
                   temp = new Node(numInsert);
                   temp->setPrev(current->getPrev());    
                   temp->setNext(current);
                   current->getPrev()->setNext(temp);
                   current->setPrev(temp);                   
          }
          else
          {
                   temp = new Node(numInsert);
                   temp->setPrev(current);
                   temp->setNext(NULL);
                   current->setNext(temp);
          }
           
     }
     else if(current->getPrev() == NULL)
     {
           
          if (current->getNumber() > numInsert)
          {
                   temp = new Node(numInsert);
                   temp->setPrev(NULL);    
                   temp->setNext(current);
                   current->setPrev(temp);
                   *start = current->getPrev();
          }
     }
     else if (current->getNumber() > numInsert)
     {
         temp = new Node(numInsert);
         temp->setPrev(current->getPrev());    
         temp->setNext(current);
         current->getPrev()->setNext(temp);
         current->setPrev(temp); 
     }
      
     // add the changong of next and prev nodes
     // to add the node in the proper place
     // in the linkes list      
}
 
/********************************************
*  testing code for the deleteNode function
********************************************/
void testDeleteNode(Node** start)
{
       traverseList(start);
       cout << "\n\n***Nodes to Delete in Linked List ***\n";
       deleteNode(start, 5);
       //traverseList(start);
       deleteNode(start, 15);
       //traverseList(start);
       deleteNode(start, 30);
       //traverseList(start);
       deleteNode(start, 1);
       //traverseList(start);
       deleteNode(start, 17);
       //traverseList(start);
       deleteNode(start, 31);
       //traverseList(start);
}
 
/********************************************
*  testing code for the insertNode function
********************************************/
void testInsertNode(Node** start)
{
        
       traverseList(start);
        
       cout << "\n\n***Nodes to Insert in Linked List ***\n";
        
       insertNode(start, 4);
       insertNode(start, 8);
       insertNode(start, 15);
       insertNode(start, 17);
       insertNode(start, 29);
       insertNode(start, 35);
       insertNode(start, 2);
       insertNode(start, 6);
       insertNode(start, 18);
       insertNode(start, 28);
       insertNode(start, 31);
       insertNode(start, 40);
       traverseList(start);
}
 
Node* LoadLinkedList()
{
    // we are basically just dealing with addresses of objects
    // we will store the address of the current object 
    //   and the address of the previous and next objects
    /*****************/
     
    // create linked list (using new for each Node)
    Node* start;
    Node* savePtr;
    Node* temp;
     
    start = new Node(5);          // create the 1st (start) Node
    savePtr = start;              // save address of CURRENT Node in savePtr
    //savePtr->display(savePtr);
     
    temp = new Node(10);          // create the next NEW Node
    savePtr->setNext(temp);       // set setNext of the PREVIOUS Node using address of CURRENT Node
    temp->setPrev(savePtr);       // set setPrevious of CURRENT Node using saved pointer
    savePtr = temp;               // save address of the new Node in savePtr 
    //savePtr->display(savePtr);
         
    temp = new Node(15);          // create the next NEW Node
    savePtr->setNext(temp);       // add Node to the end of the linked list
    temp->setPrev(savePtr);   
    savePtr = temp;               // save address of the new Node in savePtr 
    //savePtr->display(savePtr);
          
    temp = new Node(20);          // create the next NEW Node
    savePtr->setNext(temp);       // set setNext of the PREVIOUS Node using address of CURRENT Node
    temp->setPrev(savePtr);     
    savePtr = temp;               // save address of the new Node in savePtr 
     
    temp = new Node(25);          // create the next NEW Node
    savePtr->setNext(temp);       // set setNext of the PREVIOUS Node using address of CURRENT Node
    temp->setPrev(savePtr);     
    savePtr = temp;               // save address of the new Node in savePtr 
     
    temp = new Node(30);          // create the next NEW Node
    savePtr->setNext(temp);       // set setNext of the PREVIOUS Node using address of CURRENT Node
    temp->setPrev(savePtr);     
   
    return start;                 // return the beginning of the linked kist
}