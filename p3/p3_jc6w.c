#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void INThandler( int signum)
{
	printf("must be killed with SIGQUIT\n");
}

void QUIThandler(int signum)
{
	printf("handler called with signum = %d\n", signum);

	//kills parent
	//send user 2 signal to child
}

void CHLDhandler(int signum)
{
	printf("handler called with signum = %d\n", signum);
	//parent terminates;
}

void USR1handler(int signum)
{
	printf("In USR1 pid: %d\n", getpid());
}

void USR2handler(int signum)
{
	printf("In USR2 pid: %d\n", getpid());
	
//	kill(
}



int main (int argc, char *argv[])
{
	int cpid, status;

	alarm(120);

	cpid = fork();

		signal(SIGINT, INThandler);
		signal(SIGUSR1, USR1handler);
		signal(SIGCHLD, CHLDhandler);
		signal(SIGQUIT, QUIThandler);
		signal(SIGUSR2, USR2handler);
	if (cpid == 0)
	{
	
		printf("child status: %d\n",status); 
	}
	else
	{
		printf("In Parent pid: %d\n", getpid());
	}

	return 0;
}

