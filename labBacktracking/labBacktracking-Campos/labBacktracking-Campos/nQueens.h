#ifndef NQUEENS_H
#define NQUEENS_H

#include <iostream>
#include <string>
using std::string;

//maximum size of array
#define MAX_SIZE 50


void printNQueensSolution(int, string);
bool solveNQ(int, int, int[MAX_SIZE][MAX_SIZE]);
bool isGood(int, int, int, int[MAX_SIZE][MAX_SIZE]);





#endif