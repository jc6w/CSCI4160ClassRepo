/*********************************************************************
/	Author: Mae Campos
/	CSCI 4330
/	Dr. Pettey
/	lab1: using mutex threads to calculate Pi
*********************************************************************/
#include <stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include <math.h>

pthread_mutex_t m1;

double area, width;
void *trap(void*);



int main(int argc, char *argv[])
{
	int iteration[200];
	pthread_t threadid[200];
	int x, partitions;
	
	printf("Welcome!\n\n");
	printf("Please put the number of partitions needed: ");
	scanf("%d", &partitions);
	
	width = 2.0/partitions;
	area = 0.0;
	
	pthread_mutex_init(&m1, NULL);
	for( x = 0; x < partitions; x++)
	{
		iteration[x] = x;
		if( pthread_create(&threadid[x],NULL,trap, (void*)&iteration[x]) != 0)
		{
			perror("Pthread fail\n\n");
		}
	}
	
	for( x = 0; x < partitions; x++)
	{
		pthread_join(threadid[x],NULL);
	}
	
	printf("The area under the curve is %lf\n",area);
	
	return 0;
}



void *trap(void *arg)
{
	double side1, side2, Height1, Height2;
	side1 = width *  (*(int*)arg);
	side2 = side1 + width;
	Height1 = (sqrt((double)4.0 - side1* side1));
	Height2 =(sqrt((double)4.0 - side2* side2));
	Height1+= Height2;
	
	pthread_mutex_lock(&m1);
	area+=(Height1/(double)2.0)*width;
	printf("%lf", area);
	pthread_mutex_unlock(&m1);
	
}