#include<stdio.h>

/*
 * http://www.careercup.com/question?id=7781671
 */

int findmult(int a) {
	int mult = 1;
	while(a) {
		a = a / 10;
		mult = mult * 10;
	}

	return mult;
}

int compar(void *a, void *b)
{
	int c = *((int *)a);
	int d = *((int *)b);
	int i, j;
	int cmult, dmult;

	cmult = findmult(c);
	dmult = findmult(d);

	i = (c * dmult) + d;
	j = (d * cmult) + c;

	if(i == j)
		return 0;
	else if(i > j)
		return -1;
	else
		return 1;
}


int main() {
	int n[] = { 9, 94, 4, 14, 1 };
	int i;

	qsort(n, 5, sizeof(int), compar);

	for(i = 0; i < 5; i++)
		printf("%d \n", n[i]);
}
