#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// double pi(double);

double pi(double n)
{
	if (n==1)
	{
		return 4*1;
	} else
	{
		return(4*(pow(-1, n+1)*(1/(2*n-1)))+pi(n-1));
	}
}

int main()
{
	printf("Enter number n to value of pi: \n");
	int n;
	scanf("%d", &n);

	printf("%f\n", pi(n));
	return 0;
}