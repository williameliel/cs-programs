#include<stdio.h>
#include<string.h>

char *my_strstr(char *s, char *ss)
{
	int n, sn, i, j;

	if(!s || !ss) return NULL;

	n = strlen(s);
	sn = strlen(ss);

	for(i = 0; i < n; i++) {
		for(j = 0; j < sn; j++) {
			if (i + j >= n)
				return NULL;
			if (s[i + j] != ss[j])
				break;
		}

		if (j == sn)
			return (s + i);
	}
	return NULL;
}

int main()
{
	printf("strstr: %s %s = %s\n", "ababba", "abb", my_strstr("ababba", "abb"));
}
