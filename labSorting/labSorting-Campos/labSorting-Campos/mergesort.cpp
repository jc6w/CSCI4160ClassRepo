#include "mergesort.h"
#include "swap.h"
#include <time.h>


void mergeMain(int *mArray, int first, int last)
{
	int mid;
	//base case
	if(first < last)
	{
		mid = (first+last)/2;

		//do first half
		mergeMain(mArray, first, mid);
		
		//do other half
		mergeMain(mArray,mid+1,last);

		//merge 2 arrays together
		merge(mArray,first,last);
	}
}


void merge(int *mArray, int first, int last)
{
	//newArray to temporarily hold the sorted array
	int mid, *newArray, a, b, c;

	mid = (first+last)/2;
	a =first;
	b = first;
	c = mid + 1;

	while(a <= mid && c <= last)
	{
		//goes through each half of the main array and compares each element
		if(mArray[a] < mArray[c])
		{
			newArray[b] = mArray[a];
			++a;
			++b;
		}
		else
		{
			newArray[b] = mArray[c];
			++b;
			++c;
		}
	}

	while(a <= mid)
	{
		newArray[b] = mArray[a];
		++a;
		++b;
	}
	while(b <= last)
	{
		newArray[b] = mArray[c];
		++b;
		++c;
	}

	//copies back the sorted array into the main array
	for(int x = first; x < b; x++)
	{
		mArray[x] = newArray[x];
	}

}

double mergesort(int *mergeArray, int counter)
{
	clock_t begin, end;
    begin = clock();

	mergeMain(mergeArray,0,counter);
	

	end = clock();

	
    return diffClocks( end, begin);
}