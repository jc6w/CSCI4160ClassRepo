#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int num[100];
	int rc, shm_size, shmfd;
	void *shmptr;
	
	shm_size = sysconf( _SC_PAGE_SIZE );
	
	
	num [ 0 ]= argc;
	int x, y;
        for ( x =1; x < argc ; x++ )
        {
                num [ x ] = atoi (argv [ x ] ); 
        }

	   shmfd = shm_open("jc6w_shm", O_CREAT|O_RDWR|O_TRUNC, S_IRWXU);
	
	   rc = ftruncate(shmfd,shm_size);
	
	   shmptr = mmap((void *)NULL, shm_size, PROT_WRITE|PROT_READ, MAP_SHARED, shmfd, 0);
		printf("shmptr %p\n",shmptr);

		for (y=0;  y < argc;  y++)
                {
                        *((int*)shmptr +y) = num [y];
                }

	close(shmfd);
	
	
    return 0;
}
