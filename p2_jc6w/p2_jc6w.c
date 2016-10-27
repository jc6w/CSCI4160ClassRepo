#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>


int main (int argc, char *argv[])
{
	DIR *direct;
	struct dirent *DirEntry;

	if (argv[1] == NULL)
	{
		direct = opendir(".");
	}
	else
	{
		direct = opendir(argv[1]);
	}
		

	if (direct == NULL)
	{
		printf( "%s	UNKNOWN DIRECTORY\n", argv[1]);
		exit (1);
	}
	


	while ((DirEntry = readdir(direct)) != NULL)
	{
		printf("%s	", DirEntry->d_name);
	}

	printf("\n");	
	
	


	closedir(direct);

	return 0;
}
