#include<stdio.h>
#include<stdlib.h>

int binsearch(int a[], int i, int j, int n, int s)
{
	int mid, l, r;

	if(i > j)
		return -1;

	mid = (i + j) / 2;

	if(a[mid] < n && ( (mid == s-1) || a[mid+1] >= n))
		return mid;
	else if(a[mid] < n)
		return binsearch(a, mid+1, j, n, s);
	else if(a[mid] > n)
		return binsearch(a, i, mid, n, s);
	else
		return mid;
}

int lis(int a[], int n)
{
	int *c, nc = 0;
	int *lisa, ret;
	int i, j;

	c = calloc(sizeof(int), n);
	c[0] = 0;

	lisa = calloc(sizeof(int), n);
	lisa[0] = 1;

	c[1] = a[0];
	nc = 2;

	for(i = 1; i < n; i++)
	{
		j = binsearch(c, 0, nc-1, a[i], nc);
		if(j <= 0) {
			lisa[i] = 1;
			if(a[i] <= c[1])
				c[1] = a[i];
			continue;
		}

		if(c[j] == a[i]) {
			lisa[i] = j;
			continue;
		}

		lisa[i] = j+1;

		// Update C-array
		if(lisa[i] == nc)
			c[nc++] = a[i];
		else
			c[j+1] = a[i];
	}
	free(c);
	ret = lisa[n-1];
	free(lisa);

	return ret;
}

int main()
{
        int l[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
        printf("lis = %d\n", lis(l, 16));

	return 0;
}

