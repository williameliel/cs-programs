#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 * http://www.careercup.com/question?id=4716965625069568
 */

int compar(const void *a, const void *b)
{
	if(*(char *)a == *(char *)b)
		return 0;

	if(*(char *)a < *(char *)b)
		return -1;

	if(*(char *)a > *(char *)b)
		return 1;
}

int substr(char *s, char *ss)
{
	int n, sn, i, j, k;
	char *ts;

	if(!s || !ss) return -1;

	n = strlen(s);
	sn = strlen(ss);
	ts = malloc(sn + 1);

	qsort(ss, sn, sizeof(char), compar);

	for(i = 0; i < n; i++) {
		k = i;
		j = 0;

		if(k + sn >= n)
			return -1;

		strncpy(ts, &s[k], sn);

		qsort(ts, sn, sizeof(char), compar);

		while(j < sn && ts[j] == ss[j])
			j++;

		if(j == sn)
			return i;  /* matched */
	}
	return -1;
}

int main()
{
	char s[] = "afdgzyxksldfm", ss[] = "xyz";
	printf("comparison of %s and %s = %d\n", s, ss, substr(s, ss));
}


