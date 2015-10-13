#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// #define size 5

__global__ void addvec(int *c, const int *a, const int *b)
{
	int i = threadIdx.x;
	c[i] = a[i] + b[i];
}


// __global__ void sqrtvec(int *b, const int *a)
// {
// 	int i = threadIdx.x;
// 	b[i] = sqrt(a[i]);
// }

// void randomInit(int* data, int size)
// {
// 	for (int i = 0; i < size; ++i)
// 	{
// 		data[i] = rand();
// 	}
// }

// int main()
// {
// 	const int a[size];
// 	randomInit(a, size);
// 	printf("%d\n", a);
// 	return 0;
// }