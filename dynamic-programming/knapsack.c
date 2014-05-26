// 0/1 knapsack
// not compiled

#define WMAX 10
#define NMAX 10

typedef struct res {
	list *l;
	int max;
} res;

res knapsack(int wt[], int v[], int n, int w)
{
	res m[WMAX][NMAX] = {}, r1, r2, r3;
	int i, j;

	for(i = 1; i <= w; i++)
	{
		for(j = 1; j <= n; j++)
		{
			if (wt[i] > w)
			{
				r3 = m[i][j-1];		// item not included
			} else {
				r1 = m[i][j-1];		 // item not included
				r2 = m[i - w[j-1]][j-1]; // item included
				if(r2.max + v[j-1] > r1.max)
				{
					l = malloc(sizeof(list));
					l->next = r2.l;

					r3.l = l;
					r3.max = r2.max + v[j-1];
				}
				else
				{
					r3 = r1;
				}
			}
			m[i][j] = r3;
		}
	}

	// TODO: Free all nodes except m[w][n]
	return m[w][n];					
}
