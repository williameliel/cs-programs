#include<stdio.h>

/* Array A must be sorted first */
void summing_pair_march(int a[], int size, int sum, int pair[2]) {
	int i, j;
	for(i = 0, j = size-1; i < j;) {
		if(a[i] + a[j] == sum) {
			pair[0] = a[i];
			pair[1] = a[j];
			return;
		} else if(a[i] + a[j] < sum) {
			i++;
		} else {
			j--;
		}
	}
	pair[0] = -1;
	pair[1] = -1;
}

/* Assuming 8-bit positive integers */
void summing_pair_hash(int a[], int size, int sum, int pair[2]) {
	int ht[255] = {};

	for(int i = 0; i < size; i++) {
		ht[a[i]] = i;
		if(ht[sum - a[i]] && ht[a[i]] != ht[sum - a[i]]) {
			pair[0] = a[i];
			pair[1] = sum - a[i];
			return;
		}
	}
	pair[0] = -1;
	pair[1] = -1;
	return;
}

int main() {
	int a[5] = {1,3,5,9};
	int pair[2] = {};

	summing_pair_hash(a, 4, 10, pair);

	printf("pair returned %d, %d\n", pair[0], pair[1]);

	return 0;
}
