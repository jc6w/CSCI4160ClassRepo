#include "heapsort.h"
#include "swap.h"
#include <time.h>

void bubbleDown(int*dArray,int a, int size)
{
	int child;
	while((a*2 + 1) < size)
	{
		int child = 2*a + 1;
	
		//if there are 2 children
		if ((child + 1 < size) && (dArray[child] < dArray[child+1]))
		{
			child++;
		}
       //put in max heap order
		if (dArray[a] < dArray[child])
		{
			swap( dArray,child, a);  
			// repeat bubble down          
			a = child;  
		}        
		else    
		{
			return;
		}


	}

}

double heapsort(int *heapArray, int counter)
{
	clock_t begin, end;
    begin = clock();



	//heapify function
	for(int x = counter/2;x >= 0; x --)
	{
		bubbleDown(heapArray, x, counter);
	}

	while(counter - 1 > 0)
	{
		//swap the last element of the heap with the first element
		swap(heapArray,counter-1,0);
		bubbleDown(heapArray,0,counter-1);
		counter--;

	}


	

	end = clock();

	
    return diffClocks( end, begin);
}