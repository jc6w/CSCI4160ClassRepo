/* 
 *  Mae Campos
 *  Chrisila Pettey
 *  Parallel Processing
 *  4/13/2016
 *  
 *  using MPI to calculate the integral of a function via Rectangle Method with input being the number of processes
*/



#include<mpi.h>
#include<math.h>
#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>

const long double PI = 3.14159265359;


int main( int argc, char *argv[])
{
	//for MPI
	int id, proc;

	//for calculating the resulting area
	double num = 0;
	double temp = 0;
	double height = 0, result = 0, width = 0;
	

	//For MPI processing
	MPI_Status status;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &proc);
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	

	//let only 1 to process interval
	if(id == 0)
	{
		width = PI/proc;
	}

	//broadcast to rest of processes
	MPI_Bcast(&width,1,MPI_DOUBLE,0,MPI_COMM_WORLD);
	

	//beginning point of integration (addition)
	num = id*width +(width/2);
	height = sqrt(3*pow(sin(num/2),3));
	result = width*height;

	//creates a ring using MPI Sendrecv by sending to the next rank and receiving from the last rank
	if(id == 0)
	{
		
		MPI_Sendrecv(&result, 1,  MPI_DOUBLE, 1, 1,&temp,1,MPI_DOUBLE, proc - 1, 1,MPI_COMM_WORLD, &status);
		//adds result from last rank to result of rank 0
		result+= temp;
		
	}
	else
	{
		//receiving from previous rank
		MPI_Recv(&temp, 1, MPI_DOUBLE, id - 1, 1, MPI_COMM_WORLD,&status);
		//adds result from previous rank to current rank
		result+= temp;
		
		//send to rank 0 if last rank, else send to next rank
		if(id == proc - 1)
		{
			MPI_Send(&result,1,MPI_DOUBLE,0,1,MPI_COMM_WORLD);
		}
		else
		{
			MPI_Send(&result,1,MPI_DOUBLE,id + 1,1,MPI_COMM_WORLD);
		}
		
	}

	//one process prints total result
	if(id == 0)
	{
		printf("The total inegrated answer based on %d processes is: %lf\n\n",proc,result);
	}
	
	MPI_Finalize();
	
	return 0;
}
