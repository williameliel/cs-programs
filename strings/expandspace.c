#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Remove dups without additional space */

char *expand(char *s, int n)
{
	char *r;
	int i, j, c;

	c = 0;
	for(i = 0; i < n; i++)
		if(s[i] == ' ')
			c++;

	r = malloc(n+2*c);

	i = n-1;
	j = n + 2*c - 1;
	r[j+1] = '\0';

	while(i >= 0) {
		if(s[i] == ' ') {
			r[j--] = '0';
			r[j--] = '2';
			r[j--] = '%';
		} else {
			r[j--] = s[i];
		}
		i--;
	}
	return;
}

int main() {
	char *s = "ab ba b  x";
	char *r = expand(s, strlen(s));
	printf("printf r: %s\n", r);
	return 0;
}
