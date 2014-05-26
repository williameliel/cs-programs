#include<stdio.h>

#define N 5

// Rotate matrix 90 degree inplace

void printm(int a[N][N])
{
	int i, j;
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}
}


void swap_90(int a[N][N], int p, int q)
{
	int i, tmp, tmp1;
	for(i = 0; i < q-p; i++) {
		tmp = a[p][p+i];
		a[p][p+i] = a[q-i][p];
		a[q-i][p] = a[q][q-i];
		a[q][q-i] = a[p+i][q];
		a[p+i][q] = tmp;

	}
}

void rotate(int X[N][N])
{
	int p, q, r, s;
	p = 0;
	q = N-1;

	while(p <= q) {
		swap_90(X, p, q);
		p++;
		q--;
	}
}

void rotateLayers(int a[N][N])
{
    int layer, i, tmp;
    
    for(layer = 0; layer < N / 2; layer++)
    {
        for(i = layer; i < N - layer - 1; i++)
        {
            tmp                 =    a[layer][i];
            a[layer][i]         =    a[N-1-i][layer];
            a[N-1-i][layer]     =    a[N-1-layer][N-1-i];
            a[N-1-layer][N-1-i] =    a[i][N-1-layer];
            a[i][N-1-layer]     =    tmp;
        }        
    }
}

int main()
{
    int M[N][N] = {{1, 2, -1, -4, -20},
                       {-8, -3, 4, 2, 1},
                       {3, 8, 10, 1, 3},
                       {-4, -1, 1, 7, -6},
		     {1, 3, 4, 2, 6}};
 
    printm(M);
    printf("\n\n\n");
    rotateLayers(M);
    printm(M);

    return 0;
}

