#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define WA 3
#define WB 3
#define HA 3
#define HB 3
#define WC 3
#define HC 3


void randomInit(float* data, int size)
{
	for (int i = 0; i < size; ++i)
	{
		data[i] = rand()/(float)RAND_MAX;
	}
}

int main(int argc, char** argv)
{
	srand(2006);

	unsigned int size_A = WA*HA;
	unsigned int mem_size_A = sizeof(float)*size_A;
	float* h_A = (float*) malloc(mem_size_A);

	unsigned int size_B = WB*HB;
	unsigned int mem_size_B = sizeof(float)*size_B;
	float* h_B = (float*) malloc(mem_size_B);

	randomInit(h_A, size_A);
	randomInit(h_B, size_B);

	printf("\n\nMathrix A\n");
	for (int i = 0; i < size_A; i++)
	{
		printf("%f ", h_A[i]);
		if (((i+1)%WA)==0)
		{
			printf("\n");
		}
	}

	printf("\n\nMatrix B\n");
	for (int i = 0; i < size_B; i++)
	{
		printf("%f ", h_B[i]);
		if (((i+1)%WB)==0)
		{
			printf("\n");
		}
	}

	unsigned int size_C = WC*HC;
	unsigned int mem_size_C = sizeof(float)*size_C;
	float* h_C = (float*) malloc(mem_size_C);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			for (int k = 0; k < p; ++k)
			{
				a[i+n*j] += b[i+n*k]*c[k+p*j];
			}
		}
	}

	printf("\n\nMatric C (Results)\n");
	for (int i = 0; i < size_C; i++)
	{
		printf("%f ", h_C[i]);
		if (((i+1)%WC)==0)
		{
			printf("\n");
		}
	}
	printf("\n");
	free(h_A);
	free(h_B);
	free(h_C);
	return 0;
}