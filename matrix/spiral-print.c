/* This code is adopted from the solution given 
   @ http://effprog.blogspot.com/2011/01/spiral-printing-of-two-dimensional.html */
 
#include <stdio.h>
#define R 3
#define C 6

/*
 * Adjusted to treat m and n as 0-based indices instead of sizes
 */
void spiralPrint1(int m, int n, int a[R][C])
{
    int j, k = 0, l = 0;
 
	m--;
	n--;

	while(k <= m && l <= n)
	{
		for(j=l; j <= n; j++)
			printf("%d ", a[k][j]);
		k++;

		for(j=k; j <= m; j++)
			printf("%d ", a[j][n]);
		n--;

		if(k > m)
			break;

		for(j = n; j >= l; j--)
			printf("%d ", a[m][j]);
		m--;

		if(l > n)
			break;

		for(j = m; j >= k; j--)
			printf("%d ", a[j][l]);
		l++;
	}
}

void spiralPrint(int m, int n, int a[R][C])
{
    int i, k = 0, l = 0;
 
    /*  k - starting row index
        m - ending row index
        l - starting column index
        n - ending column index
        i - iterator
    */
 
    while (k < m && l < n)
    {
        /* Print the first row from the remaining rows */
        for (i = l; i < n; ++i)
        {
            printf("%d ", a[k][i]);
        }
        k++;
 
        /* Print the last column from the remaining columns */
        for (i = k; i < m; ++i)
        {
            printf("%d ", a[i][n-1]);
        }
        n--;
 
        /* Print the last row from the remaining rows */
        if ( k < m)
        {
            for (i = n-1; i >= l; --i)
            {
                printf("%d ", a[m-1][i]);
            }
            m--;
        }
 
        /* Print the first column from the remaining columns */
        if (l < n)
        {
            for (i = m-1; i >= k; --i)
            {
                printf("%d ", a[i][l]);
            }
            l++;    
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
 
    spiralPrint(R, C, a);
    return 0;
}
 
/* OUTPUT:
  1 2 3 4 5 6 12 18 17 16 15 14 13 7 8 9 10 11
*/
