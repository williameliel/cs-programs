#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void merge_sort(int a[], int i, int j)
{
	int mid, *b, p, q, tmp;

	if(i == j)
		return;

	mid = (i+j) / 2;

	merge_sort(a, i, mid);
	merge_sort(a, mid+1, j);

	/* Merge left and right */
	b = malloc((j-i+1)*sizeof(int));

	p = i;
	q = mid + 1;
	tmp = 0;

	/* The most beautiful merge loop known to mankind! */
	while(p <= mid && q <= j) {
		if(a[p] > a[q])
			b[tmp++] = a[p++];
		else
			b[tmp++] = a[q++];
	}

	while(p <= mid)
		b[tmp++] = a[p++];
	while(q <= j)
		b[tmp++] = a[q++];

	memcpy(a+i, b, (j-i+1) * sizeof(int));
	free(b);
}

void sort(int a[], int n)
{
	merge_sort(a, 0, n-1);
}

#include "run-sort.h"
