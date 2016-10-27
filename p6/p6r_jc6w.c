#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int rc, shm_size, shmfd;
    void *shmptr;
    int x = 0;
	
    shm_size = sysconf( _SC_PAGE_SIZE );
    
    shmfd = shm_open("jc6w_shm", O_RDONLY, 0);
    
    shmptr = mmap((void *)NULL, shm_size, PROT_READ, MAP_SHARED, shmfd, 0);

   	int num[100];
	   num [ 0 ]= argc;
	
        for ( x =1; x < *((int *) shmptr); x++ )
        {
                printf ( "value: %d\n", *((int *) shmptr + x) ) ;
        }



    munmap(shmptr,shm_size);
    close(shmfd);
	
    shm_unlink("jc6w_shm");

    return 0;
}
