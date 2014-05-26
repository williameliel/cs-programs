#include<stdio.h>
#include<string.h>

int substr(char *s, char *ss)
{
	int n, sn, i, j, k;

	if(!s || !ss) return -1;

	n = strlen(s);
	sn = strlen(ss);

	for(i = 0; i < n; i++) {
		k = i;
		j = 0;
		while(k < n && j < sn && s[k] == ss[j]) { k++; j++; }

		if(j == sn)
			return i;  /* matched */
		if(i == n)
			return -1; /* ran out of i (i = n & j < sn) */
	}
	return -1;
}

int main()
{
	printf("substr: %s %s = %d\n", "aaab", "axb", substr("aaab", "axb"));
}
