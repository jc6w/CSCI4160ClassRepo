#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include<mpi.h>
#define MAXNUM (40)

int main(int argc, char*argv[])
{
	//to count how many players, and store its sleep time, how many times it has gone through,and its number
	int playerTime[40][3];
	//to store what players are playing in the server
	int play[3][2];
	
	
	int RunTime = 0;
	int finalNum;
	int serveMax;
	int sendTo;
	int copyCount;
	int count;
	
	
	int a[3];
	//for MPI
	int id, proc;
	
	//For MPI processing
	MPI_Status status;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &proc);
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	
	//RANK 0 passes players to  other corresponding ranks
	if(id==0)
	{
		for(count; count < MAXNUM && finalNum != -1; count++)
		{
			scanf("%d", &finalNum);
		
			playerTime[count][0] = count +1;
			playerTime[count][1] = finalNum;
			playerTime[count][2] = 0;
			
		
		}	
		for(serveMax = 0; serveMax < 3; serveMax++)
		{
			play[serveMax][0] = serveMax + 1;
			play[serveMax][1] = 1;
			MPI_Send(&playerTime[serveMax][0],3,MPI_INT,serveMax,1,MPI_COMM_WORLD);
		}
		
		MPI_Recv(&a,3,MPI_INT,MPI_ANY_SOURCE,1,MPI_COMM_WORLD,&status);
		sendTo = status.MPI_SOURCE;
		
		copyCount = count;
		
		while(RunTime < count)
		{
			if(a[2] <1)
			{
				playerTime[copyCount][0] = *a;
				copyCount++;
			}
			else
			{
				++RunTime;
			}
			if(RunTime >0)
			{
				MPI_Send(&playerTime[serveMax][0],3,MPI_INT,sendTo,1,MPI_COMM_WORLD);
				serveMax++;
				MPI_Recv(&a,3,MPI_INT,MPI_ANY_SOURCE,1,MPI_COMM_WORLD,&status);
				sendTo = status.MPI_SOURCE;
			}
			
		}
		playerTime[0][2]=0;
			
		for(serveMax = 0; serveMax < 3; serveMax++)
		{
			play[serveMax][0] = serveMax + 1;
			play[serveMax][1] = 1;
			MPI_Send(&playerTime[0][0],3,MPI_INT,serveMax,1,MPI_COMM_WORLD);
		}
		
		
	}
	else
	{
		
		MPI_Recv(&a,3,MPI_INT,0,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
		while(a[2] !=0)
		{
		//receives from 0
		MPI_Recv(&a,3,MPI_INT,0,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
		printf("Thread %d, Player %d, play length %d\n\n", id, a[0], a[1]);

		sleep(a[1]);
		//send 0 the info
		MPI_Send(&a,3,MPI_INT,0,1,MPI_COMM_WORLD);
		}
	}
	//printf("Thread %d, Player %d, play length %d\n\n", me, player, time);

	//sleep(time);
	
	//status.source
		
//	MPI_Barrier(MPI_COMM_WORLD);
	if(id==0)
	{
		printf("Sorry.  Offline for scheduled maintenance.\n\n");
	}
	//if (runTime == 2 && playerList[x].sleepTime == -1){player = 0;} 
	
	
	MPI_Finalize();
	
	return 0;
}
