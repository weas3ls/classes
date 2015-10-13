#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "wrapper.h"

int weasOpen(const char *fileName)
{
	int fd;
	fd=open(fileName, O_CREAT, S_IRUSR | S_IWUSR);
	if (fd < 0)
	{
		return fd;
	}
	return fd;
}

