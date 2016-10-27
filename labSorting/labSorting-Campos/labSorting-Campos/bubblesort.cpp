#include "bubbleSort.h"
#include "swap.h"
#include <time.h>


double bubbleSort(int *bubbleArray, int counter)
{
	clock_t begin, end;
    begin = clock();
	//as size for comparing the elements in array decreases
	for(int a = counter-1; a > 0; a--)
	{
		//goes through the whole array being used
		for(int b = 0; b < a; b++)
		{
			//and swaps the two elements being compared
			if(bubbleArray[b] < bubbleArray[b+1])
			{
				swap(bubbleArray,b,b+1);
			}
		}

	}
	

	end = clock();

	
    return diffClocks( end, begin);
}