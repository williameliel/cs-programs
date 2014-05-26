#include <stdio.h>

/*
 * http://en.wikipedia.org/wiki/Longest_alternating_subsequence
 */

int longestAlt(int a[], int  n)
{
	int dir = 0, cur = 0, i;

	for(i = 1; i < n; i++)
	{
		if(a[i] > a[i-1] && cur == 1) {
			cur = 0;
			dir++;
		} else if(a[i] < a[i-1] && cur == 0) {
			cur = 1;
			dir++;
		}
	}

	return dir + 1;
}

int main()
{
	int a[] = { 1, 4, 6, 5, 3, 2, 7, 6, 9, 4, 5, 6, 6 };

	printf("longest %d\n", longestAlt(a, sizeof(a) / sizeof(int)));
}
