#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int* search(char *cy, char c)
{
	int i, j;
	int *cord;
	cord = malloc(sizeof(int)*2);
	cord[0] = -1;
	cord[1] = -1;

	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 7; j++)
		{
			if (cy[(i*7)+j]==c)
			{
				cord[0]=i;
				cord[1]=j;
				break;
			}
		}
	}
	return (cord);
}

char get(char *cy, int i, int j)
{
	return(cy[(i*7)+j]);
}

void decr(char *data)
{
	int *cord, *cordStream, k, l, size, i;
	char *decr;
	char cy[] = {"*&^$#!@() <>?abcdefghijklmnopqrstuvwxyz0123456789"};

	size = strlen(data);
	decr = malloc(sizeof(char)*size);
	cordStream = malloc(sizeof(int)*(2*size));
	k = 0;
	i=0;

	while (k<size)
	{
		cord = search(cy, data[k]);
		cordStream[i] = cord[0];
		cordStream[i+1] = cord[1];
		k++;
		i=i+2;
	}
	k=l=0;

	while (k<(size))
	{
		char c;
		c = get(cy, cordStream[k], cordStream[k+size]);
		decr[l] = c;
		k++;
		l++;
	}

	printf("%s\n", decr);
}

int main(int argc, char const *argv[])
{
	decr(argv[1]);
	return 0;
}