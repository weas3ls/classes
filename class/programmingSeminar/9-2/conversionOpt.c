#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	clock_t start, end;
	float c, k, d;
	int f, i, nf;
	d = 0.5555;

	start = clock();
	for (i = 0; i < 1000; i++)
	{
		for (f = 0; f <= 990; f=f+20)
		{
			c=(f-32)*d;
			k=(f+459.67)*d;
			printf("f=%d, c=%.2f, k=%.2f \n", f, c, k);

			nf = f+10;
			c=(nf-32)*d;
			k=(nf+459.67)*d;
			printf("f=%d, c=%.2f, k=%.2f \n", nf, c, k);
		}
	}
	end = clock();
	double t;
	t = (((double) (end-start))/CLOCKS_PER_SEC)/1000;
	printf("Time elapsed: %f \n", t);
	return 0;
}