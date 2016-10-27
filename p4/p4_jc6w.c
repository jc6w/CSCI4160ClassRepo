#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>

bool NotDone = true;


int main(int argc, char * argv[])
{
	alarm(100);
	
	int rchild, status, sock[2];
	char buf[10000];

	socketpair(AF_UNIX,SOCK_STREAM,0,sock);
	
	printf("fds: %d %d\n",sock[0], sock[1]);

	rchild = fork();

	printf(" rchild = %d\n", rchild);

		if (rchild > 0)
		{
			while (fgets(buf, 10000, stdin) && NotDone && buf[0] != '\n')
			{
				write(sock[1],buf, 100);
				read(sock[1],buf, 100);
				printf("Parent %d: recvd %s\n",getpid(),buf);
			}

			NotDone = false;

			shutdown(sock[0], SHUT_RDWR);
			shutdown(sock[1], SHUT_RDWR);
			

			kill(getpid()+1, SIGKILL);
			rchild = waitpid(-1, &status, 0);
			printf("status for child is %d\n", status);
		}
		else
		{
			while (NotDone)
			{
				read(sock[0],buf, 100);
		
				printf("Child %d: recvd %s\n",getpid(),buf);
		
				int x;

				for (x = 0; x < 100; x++)
				{
					buf[x] = toupper(buf[x]);
				}	
	
				write(sock[0],buf,100);
			}
		}
	return 0;
}
