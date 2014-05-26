/* This code is adopted from the solution given 
   @ http://effprog.blogspot.com/2011/01/spiral-printing-of-two-dimensional.html */
 
#include <stdio.h>
#define R 3
#define C 6

void diagPrint(int m, int n, int a[R][C])
{
	int i, k, l;

	m--;
	n--;

	for(i = 0; i <= m; i++) {
		k = i;
		l = 0;
		while(k >= 0 && l <= n) {
			printf("%d \n", a[k][l]);
			k--;
			l++;
		}
	}

	for(i = 1; i <= n; i++) {
		k = i; // column
		l = m; // row
		while(k <= n && l >= 0) {
			printf("%d \n", a[l][k]);
			k++;
			l--;
		}
	}
}
 
/* Driver program to test above functions */
int main()
{
    int a[R][C] = { {1,  2,  3,  4,  5,  6},
        {7,  8,  9,  10, 11, 12},
        {13, 14, 15, 16, 17, 18}
    };
 
    diagPrint(R, C, a);
    return 0;
}
 
/* OUTPUT:
  1 2 3 4 5 6 12 18 17 16 15 14 13 7 8 9 10 11
*/
