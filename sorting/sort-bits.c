#include<stdio.h>
#include<stdlib.h>

/*
 * http://www.careercup.com/question?id=7781671
 */

int count_ones(int p) {
	int c = 0;
	int x = p;

	while (p) {
		if (p & 0x1)
			c++;
		p = p >> 1;
	}

	return c;
}

int compar(void *a, void *b)
{
	int p, q, pn, qn;

	p = *((int *)a);
	q = *((int *)b);

	pn = count_ones(p);
	qn = count_ones(q);

	return (pn - qn);
}

int get_max(int i)
{
	int ret = 0;
	while(i--) {
		ret = ret | 1;
		ret = ret << 1;
	}
	ret = ret >> 1;

	return ret;
}

int main() {
	int *n;
	int i;
	int k = 3;

	i = get_max(k) + 1;
	n = (int *)malloc(sizeof(int)*i);

	for(k = 0; k < i; k++)
		n[k] = k;
	
	qsort(n, i, sizeof(int), compar);

	for(k = 0; k < i; k++)
		printf("%d \n", n[k]);
}












