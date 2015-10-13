#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	DIR *mydir;
	struct dirent *mydent;
	struct stat mystat;

	// printf("%s\n", argv[0]);
	
	mydir = opendir(argv[1]);

	mydent=readdir(mydir);
	stat(mydent->d_name, &mystat);
	printf("filename: %s ", mydent->d_name);
	printf("size: %d, blocks: %d, IO blocks: %d\n", mystat.st_size, mystat.st_blocks, mystat.st_blksize);
	printf("deviceID: %d\n", mystat.st_dev);
	

	return 0;
}