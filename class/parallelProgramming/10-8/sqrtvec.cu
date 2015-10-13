#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define size 1024

__global__ void sqrtvec(float *b, const float *a)
{
	int i = threadIdx.x;
	b[i] = sqrtf(a[i]);
}

int main()
{
	float a[size];
	for (int i = 0; i < size; i++)
	{
		a[i] = (float)i;
	}
	float b[size] = {0}; float *da, *db;
	cudaMalloc((void**)& db, size*sizeof(int));
	cudaMalloc((void**)& da, size*sizeof(int));
	cudaMemcpy(da, a, size*sizeof(int), cudaMemcpyHostToDevice);
	sqrtvec<<<1, size>>>(db, da);
	cudaMemcpy(b, db, size*sizeof(int), cudaMemcpyDeviceToHost);
	for (int i = 0; i < size; i++)
	{
		printf("%f\n", b[i]);
	}
	cudaThreadSynchronize();
	cudaFree(db);
	cudaFree(da);
	return 0;
}