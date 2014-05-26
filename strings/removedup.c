#include<stdio.h>
#include<string.h>

/* Remove dups without additional space */

void removeDup(char *s, int n)
{
	int tail, i, j, dup;

	if(n <= 1) return;

	tail = 1;

	for(i = 1; i < n; i++) {
		for(j = 0; j < tail; j++) {
			if(s[j] == s[i])
				break;
		}

		if(j == tail)
			s[tail++] = s[i];
	}
	s[tail] = 0;
}

int main() {
	char s[] = "abbbabx";
	removeDup(s, strlen(s));
	printf("Remove dups: %s\n", s);
	return 0;
}
