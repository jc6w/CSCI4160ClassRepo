#include "quicksort.h"
#include "swap.h"
#include <time.h>

double quicksort(int *quickArray, int counter)
{
	clock_t begin, end;
    begin = clock();

	quickMain(quickArray, 0, counter);

	end = clock();

	
    return diffClocks( end, begin);


}

void partition(int *qArray, int first, int last)
{
	int pivotIndex, marker = first, mid = (first+ last)/2;
	//find median to use as pivot
	if(qArray[first] < qArray[last])
	{
		if(qArray[mid] < qArray[first])
		{
			pivotIndex = mid;
		}
		else
		{
			pivotIndex = first;
		}
	}
	else
	{
		if(qArray[mid] < qArray[last])
		{
			pivotIndex = mid;
		}
		else
		{
			pivotIndex = last;
		}
	}

	swap(qArray,first, pivotIndex);

	for(int unknown = first; unknown <= last; ++unknown)
	{
		if(qArray[unknown] < qArray[pivotIndex])
		{
			marker++;
			swap(qArray,unknown,marker);
		}

	}

}

void quickMain(int *qArray, int first, int last)
{
	int pivot;

	if(first < last)
	{
		//choose pivot
		partition(qArray, first, last);

		//recursively do the same for each partition
		quickMain(qArray, first, pivot - 1);
		quickMain(qArray, pivot + 1, last);
		
	}

}