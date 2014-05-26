// Given a set, find all elements that add up to a sum

// not compiled

typedef struct res {
	list *l;
	bool found;
} res;

res subset_sum(int set[], int n, int sum)
{
	list *l;
	res r[NMAX][SMAX] = {};
	int i, j;

	// i > 0 and sum == 0, found.
	for(i = 1; i <= n; i++) {
		r[i][0].found = true;
		l = calloc(sizeof(list),1);
		l->e = i;
		r[i][0].l = l;
	}

	// if no elements (n = 0), not found
	for(i = 0; i <= sum; i++)
		r[0][i].found = false;

	for(i = 1; i <= sum; i++) {
		for(j = 1; j <= n; j++) {
			// Without even including the j-1 th element (last element), we already found a subset. just copy it
			if(r[j-1][i].found == true)
				r[j][i] = r[j-1][i];
			// Only try next step if we can subtract set[j-1] (that's the last element), from the current sum.
			else if(set[j-1] <= i) {
				// Including this element
				r[j][i] = r[j-1][i-set[j-1]];
				// Are we true?
				if(r[j][i]) {
					l = calloc(sizeof(list),1);
					l->e = j-1;
					l->next = r[j][i].l;
					r[j][i].l = l;
				}
			}
		}
	}

	return r[n][sum];
}


