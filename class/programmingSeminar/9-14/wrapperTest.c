#include <stdio.h>
#include <stdlib.h>
#include "wrapper.h"

int main()
{
	int file;
	file = weasOpen("testweasOpen.txt");
	printf("%d\n", file);
	return 0;
}