#include<stdio.h>
#include<stdlib.h>

void print_pascal(int n)
{
	int i, j;
	int *a;

	a = malloc(sizeof(int)*i*j);

	for(i = 1; i <= n; i++) {
		for(j = 1; j <= i; j++) {
			if(j != 1 && j != i && i > 2)
				a[i*j] = a[(i-1)*j] + a[(i-1)*(j-1)];
			else
				a[i*j] = 1;
			printf("%3d", a[i*j]);
		}
		printf("\n");
	}
	free(a);
}

int main()
{
	print_pascal(7);
	return 0;
}
