#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define R 6
#define C 5

/*
 * Given a binary matrix, find out the maximum size square sub-matrix with all 1s.
 */

#define min(a,b) (a < b ? a : b)
#define min_3(a,b,c) min(min(a,b),c)

int max_sub(int a[R][C])
{
	int j, i;
	int max = 0, s[R][C], max_i, max_j;
	int m = R, n = C;

	for(i = 0; i < m; i++) { s[i][0] = a[i][0]; };
	for(j = 0; j < n; j++) { s[0][j] = a[0][j]; };

	for(i = 1; i < m; i++) {
		for(j=1; j < n; j++) {
			if(a[i][j] == 0)
				s[i][j] = 0;
			else
				s[i][j] = min_3(s[i-1][j], s[i][j-1], s[i-1][j-1]) + 1;

			if(s[i][j] > max) {
				max = s[i][j];
				max_i = i - (max - 1);
				max_j = j - (max - 1);
			}
		}
	}

	if(max > 0)
		printf("max size sub matrix with all-ones is of size %d, at (%d,%d)\n", max, max_i, max_j);
}


int main()
{
  int M[R][C] =  {{0, 1, 1, 0, 1}, 
                   {1, 1, 0, 1, 0}, 
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};
                
  max_sub(M);
}  
