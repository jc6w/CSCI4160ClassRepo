#include <stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include <unistd.h>
#include<time.h>

void* sub(void *arg);


int highRet, highRetId;
pthread_mutex_t m1;


int main(int argc, char *argv[])
{

	alarm(60);
	
	int is[4], rc;
	int numThreads = atoi(argv[1]);
	int section = 100/numThreads;
	int* size;
	
	
	pthread_t thrdid[4];

	pthread_mutex_init(&m1, NULL);

	int y = 0;
	
	for (y; y < 4; y++)
	{
		is[y] = 0;
	}
	int i = 0;
	
	for(i=0;i<numThreads;i++)
	{
		
		if (numThreads == 3)
		{
			is[i] = 33*(i + 1);
			is[1] = 34;
			size = malloc(sizeof(int));
			*size = is[i];
			rc = pthread_create(&thrdid[i],NULL,sub,size);

			
		}
		else
		{
			is[i] = section *(i + 1);
			size = malloc(sizeof(int));
			*size = is[i];
			rc = pthread_create(&thrdid[i],NULL,sub,size);
		}
		
	}
	
	for (i = 0; i < numThreads; i++)
	{
		pthread_join(thrdid[i],NULL);
	}
	
	
	printf("%d %d\n",highRetId,highRet);
	
	
	return 0;
}


void* sub(void*arg)
{
	int rc;
	int secSize = *((int *) arg); 
	int x = 100 - secSize;

	for (x; x < secSize; x++)
	{
		rc = p5test(x);
		if (rc > highRet)
		{
			pthread_mutex_lock(&m1);
			highRet = rc;
			highRetId = x;
			pthread_mutex_unlock(&m1);
		}
	}
	
}