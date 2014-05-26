#include <stdio.h>
#include <limits.h>

/*
 * http://www.careercup.com/question?id=16759664
 */

#define findmin(a, b, c) (a < b ? (a < c ? a : c) : (b < c ? b : c))
#define findmax(a, b, c) (a > b ? (a > c ? a : c) : (b > c ? b : c))

void minRange(int m1[], int m2[], int m3[], int n1, int n2, int n3)
{
	int i = 0, j = 0, k = 0, min, max, amin[3], minr = INT_MAX;

	while(i < n1 && j < n2 && k < n3) {
		min = findmin(m1[i], m2[j], m3[k]);
		max = findmax(m1[i], m2[j], m3[k]);

		if(max - min < minr) {
			minr = max - min;
			amin[0] = m1[i];
			amin[1] = m2[j];
			amin[2] = m3[k];
		}

		if(min == m1[i])
				i++;
		if(min == m2[j])
				j++;
		if(min == m3[k])
				k++;
	}

	printf("%d %d %d\n", amin[0], amin[1], amin[2]);
}

int main()
{
	int m1[5] = {4, 10, 15, 24, 26};
	int m2[5] = {0,  9, 12, 20, 35};
	int m3[5] = {5, 18, 22, 30, 50};

	minRange(m1, m2, m3, 5, 5, 5);
	return 0;
}
