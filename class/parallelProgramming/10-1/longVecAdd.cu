#include <stdio.h>

#define N 2048

__global__ void addvec(int *dc, const int *da, const int *db)
{
	int tid = blockIdx.x * blockDim.x + threadIdx.x;
	while (tid < N)
	{
		dc[tid] = da[tid] + db[tid];
		tid += blockDim.x * gridDim.x;
	}
}

int main()
{
	int a[N], b[N], c[N], *da, *db, *dc;
	for (int i = 0; i < N; i++)
	{
		a[i] = -i; b[i] = i*i;
	}
	cudaMalloc((void**)& dc, N*sizeof(int));
	cudaMalloc((void**)& da, N*sizeof(int));
	cudaMalloc((void**)& db, N*sizeof(int));
	cudaMemcpy(da, a, N*sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(db, b, N*sizeof(int), cudaMemcpyHostToDevice);
	addvec<<<(N+127)/128, 128>>>(dc, da, db);
	cudaMemcpy(c, dc, N*sizeof(int), cudaMemcpyDeviceToHost);
	cudaFree(dc); cudaFree(da); cudaFree(db);
	return 0;
}