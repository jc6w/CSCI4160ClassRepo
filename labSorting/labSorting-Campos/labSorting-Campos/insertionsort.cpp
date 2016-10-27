#include "insertionSort.h"
#include <time.h>


double insertionSort(int *inArray, int counter)
{
	clock_t begin, end;
    begin = clock();

	int y, insert;

	//as size of array to compare increases
	for (int x = 0; x < counter; x++)
	{
		//take the element being compared
		insert = inArray[x];
		y = x;
		//moves some or all other elements 1 over
		while (y > 0 && inArray[y] < insert)
		{
			inArray[y] = inArray[y-1];
			y--;
		}
		//insert element at specified place
		inArray[y] = insert;
	}

	end = clock();

	
    return diffClocks( end, begin);
}