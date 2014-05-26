// not compiled

/*
	if s[i] == s[j];  LCS[i, j] = 1 + LCS[i-1, j-1]
	if s[i] != s[j];  LCS[i, j] = max(LCS[i-1, j], LCS[i, j-1])
*/

typedef struct res
{
	list *l;
	int max;
} res;

res lcs(char *s, int n) {
	res r1, r2, r3;
	list *l;
	int i, j;
	res r[NMAX][NMAX] = {};

	for(i = 1; i <= n; i++) {
		for(j = 1; j <= n; j++) {
			if(s[i-1] == s[j-1]) {
				r1.max = 1;
				l = calloc(sizeof(l), 1);
				l->e = i;
				r1.l = l;
				if(i > 0 && j > 0) {
					r1.max += r[i-1][j-1].max;
					r1.l->next = r[i-1][j-1].l;
				}
			} else {
				if(i > 0)
					r2 = r[i-1][j];
				else
					r2.max = 0;

				if(j > 0)
					r3 = r[i][j-1];
				else
					r3.max = 0;

				if(r2.max > r3.max)
					r1 = r2;
				else
					r1 = r3;
			}
			r[i][j] = r1;
	}
	// TODO: Free up all the rest of the matrix O(N^2)
	return r[n][n];
}
