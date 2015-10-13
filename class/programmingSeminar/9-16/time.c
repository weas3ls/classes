#include <sys/time.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "time.h"
#include <time.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define BILLION 1000000000L

int localpid(void) {
	static int a[9] = { 0 };
	return a[0];
}
int main(int argc, char const *argv[])
{
	uint64_t diff;
	struct timespec start,end;
	int i;

	clock_gettime(CLOCK_MONOTONIC, &start);
	sleep(1);
	clock_gettime(CLOCK_MONOTONIC, &end);

	diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
	printf("elapsed time = %llu nanoseconds\n", (long long unsigned int) diff);
	return 0;
}