#include "swap.h"


void swap(int *swapArray, int a, int b)
{
	int temp;
	temp = swapArray[a];
	swapArray[a] = swapArray[b];
	swapArray[b] = temp;

}