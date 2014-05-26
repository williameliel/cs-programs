#include<stdio.h>
#include<stdlib.h>
// Longest Increasing Subsequence

#define NMAX 20
#define MAX_VAL 16

typedef struct nlist {
	int n;
	struct nlist *next;
} nlist;

typedef struct res {
	nlist *l;
	int size;
} res;

/* Better approach, O(n) space */
void printLongest(int a[], int n)
{
	nlist *l;
	res d[NMAX];
	int i, j, max, j_max, max_all = 0, i_max = 0;

	for(i = 0; i < n; i++) {
		l = calloc(sizeof(*l), 1);
		l->n = a[i];

		/* From 0->i-1 find, the index who's element is less than a[i] and
		 * who's LIS is greater than index i's LIS */
		max = 1;
		j_max = i;
		for(j = 0; j < i; j++) {
			if(a[i] > a[j] && d[j].size + 1 > max) {
				max = d[j].size + 1;
				j_max = j;
			}
		}

		d[i].size = max;
		d[i].l = l;

		if(j_max < i) {
			l->next = d[j_max].l;
			d[i].l = l;
		}

		if(max > max_all) {
			max_all = max;
			i_max = i;
		}
	}

	l = d[i_max].l;
	for(; l; l = l->next)
		printf("%d ", l->n);
		
	printf("\n");
}

#if 0
void printLongest(int a[], int n, int max) {
	res T[NMAX+1][MAX_VAL+1] = {}, r1, r2;
	int i, j, tmax;
	nlist *l;

	for(i = 1; i <= n; i++) {
		for(j = 1; j <= max; j++) {
			tmax = a[i-1];
			if(tmax > j) {
				T[i][j] = T[i-1][j];
			} else {
				r1 = T[i-1][j];    // not including
				r2 = T[i-1][tmax]; // including
				if(r2.size + 1 > r1.size) {
					l = malloc(sizeof(nlist));
					l->n = tmax;
					l->next = r2.l;
					T[i][j].l = l;
					T[i][j].size = r2.size + 1;
				}
				else {
					T[i][j] = r1;
				}
			}
		}
	}
	l = T[n][max].l;
	for(;l; l = l->next) printf("%d ", l->n);
	printf("\n");
}
#endif

int main()
{
	int l[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	printLongest(l, 16);
}
