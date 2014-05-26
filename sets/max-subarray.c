#include<stdio.h>

struct res {
	int i;
	int j;
	int sum;
};

struct res max_sub(int a[], int i, int j)
{
	int mid, left_sum = 0, right_sum = 0, sum, left_ind, right_ind, p;
	struct res r, left, right, center;

	// printf("max_sub(a, %d, %d) ", i, j);
	mid = (i+j)/2;

	if (i == j) {
		r.i = r.j = i;
		r.sum = a[i];
		goto ret;
	}

	right = max_sub(a, mid + 1, j);
	left = max_sub(a, i, mid);

	/* Find max left and right sum and track indices */
	sum = 0;
	left_ind = mid;

	for(p = mid; p >= i; p--) {
		sum += a[p];
		if(sum > left_sum) {
			left_sum = sum;
			left_ind = p;
		}
	}

	sum = 0;
	right_ind = mid + 1;

	for(p = mid + 1; p <= j; p++) {
		sum += a[p];
		if(sum > right_sum) {
			right_sum = sum;
			right_ind = p;
		}
	}

	center.sum = right_sum + left_sum;
	center.i = left_ind;
	center.j = right_ind;

	if(left.sum > right.sum)
		r = left;
	else
		r = right;

	if(r.sum < center.sum)
		r = center;

ret:
	// printf(" --> (%d, %d). sum = %d\n", r.i, r.j, r.sum);
	return r;
}

int main() {
	int a[10] = { 1, -2 , 3, 4, 5, -6, 10, -5, 100, -3 };
	struct res r = max_sub(a, 0, 9);

	printf("max sub arr, sum=%d  i=%d, j=%d\n", r.sum, r.i, r.j);
	return 0;
}
