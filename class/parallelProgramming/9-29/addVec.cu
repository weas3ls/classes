#include <stdio.h>

#define size 5

__global__ void addvec(int *c, const int *a, const int *b)
{
	int i = threadIdx.x;
	c[i] = a[i] + b[i];
}

int main()
{
	const int a[size] = {1, 2, 3, 4, 5};
	const int b[size] = {10, 20, 30, 40, 50};
	int c[size] = {0}; int *da, *db, *dc;
	cudaMalloc((void**)& dc, size*sizeof(int));
	cudaMalloc((void**)& da, size*sizeof(int));
	cudaMalloc((void**)& db, size*sizeof(int));
	cudaMemcpy(da, a, size*sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(db, b, size*sizeof(int), cudaMemcpyHostToDevice);
	addvec<<<1, size>>>(dc, da, db);
	cudaMemcpy(c, dc, size*sizeof(int), cudaMemcpyDeviceToHost);
	printf("{1, 2, 3, 4, 5} + {10, 20, 30, 40, 50} = {%d, %d, %d, %d, %d}\n", c[0], c[1], c[2], c[3], c[4]);
	cudaThreadSynchronize();
	cudaFree(dc); cudaFree(da); cudaFree(db);
	return 0;
}