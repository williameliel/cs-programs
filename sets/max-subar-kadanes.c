#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// Kadane's algorithm

typedef struct res {
	int i;
	int j;
	int sum;
} res;

res *max_sub(int a[], int n)
{
	int i;
	res max, max_cur, *maxsub;

	maxsub = calloc(sizeof(res), n);
	
	max_cur.sum = -1 * INT_MAX;
	max = max_cur;

	for(i = 0; i < n; i++) {
		if(max_cur.sum < 0) {
			max_cur.sum = a[i];
			max_cur.i = i;
			max_cur.j = i;
		} else {
			max_cur.sum += a[i];
			max_cur.j = i;
		}

		if(max_cur.sum > max.sum)
			max = max_cur;

		maxsub[i] = max;
	}

	return maxsub;
}

int main() {
	int a[10] = { 1, -2 , 3, 4, 5, -6, 10, -5, 100, -3 };
	res *r1 = max_sub(a, 10), r;

	r = r1[9];

	printf("max sub arr, sum=%d  i=%d, j=%d\n", r.sum, r.i, r.j);
	return 0;
}
