/*Mae Campos*/



#include <stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include <unistd.h>
#include <stdbool.h>

int Front = 0;
pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t wait = PTHREAD_COND_INITIALIZER;
struct Player
{
	int player;
	int sleepTime;
}playerList[3];
int count;



void* game(void* arg);

int main (int argc, char* argv[])
{
	
	int y, i;
	int locked;
	int is[3] ={0,1,2};
	
	
	pthread_t threadID[3];
	
	pthread_mutex_init(&m1, NULL);
	
	for(y = 0; y < 3; y++)
	{
		pthread_create(&threadID[y],NULL,game,&is[y]);
	}
	
	 i = 0;
	
	while(i < 10)
	{
		locked = pthread_mutex_trylock(&m1);
		
		if(locked != 0)
		{
			pthread_mutex_unlock(&m1);
		}
		else
		{
			scanf("%d", &playerList[Front].sleepTime);
			playerList[Front].player = i; 
		
			pthread_cond_wait(&wait, &m1);
			
			if (Front == 3)
			{
				Front = 0;
			}
			else
			{
				Front++;
			}
			i++;
			
			pthread_mutex_unlock(&m1);
			
		}
	}
	

	
	for (i = 0; i < 3; i++)
	{
		pthread_join(threadID[i],NULL);
	}
	return 0;
	
}

void* game(void* arg)
{
	
	int me = *(int *) arg;
	int time;
	int player;
	int locked;
	
	while (player < 10)
	{
		locked = pthread_mutex_trylock(&m1);
		
		if(locked != 0)
		{
			pthread_mutex_unlock(&m1);
		}
		else
		{
			player = playerList[Front].player;
			time = playerList[Front].sleepTime;
		
			if (Front == 3)
			{
				Front = 0;
			}
			else
			{
				Front++;
			}
			
			player++;
			
			pthread_mutex_unlock(&m1);
			
			pthread_cond_signal(&wait);
			
			if(time != 0)
			{
				printf("Thread %d, Player %d, play length %d\n\n", me, player, time);
			;
			}
			
		}
			
	}
}
	
	

