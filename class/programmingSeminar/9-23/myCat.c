#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char ch;
	FILE *fp;
	int i;

	if (argc < 2)
	{
		printf("%s\n", "Error! You need a filename");
		exit(0);
	} 
	for (i = 1; i < argc; i++)
	{
		fp = fopen(argv[i], "r");
		if( fp == NULL )
		{
	    perror("Error while opening the file.\n");
	    exit(EXIT_FAILURE);
	  }
		printf("What's inside '%s' you ask? Take a look: \n", argv[i]);
		while ((ch = fgetc(fp)) != EOF )
		{
			printf("%c", ch);
		}
	}
		
	fclose(fp);
	return 0;
}