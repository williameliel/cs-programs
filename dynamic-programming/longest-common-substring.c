#include<stdio.h>

#define NMAX 20

void find_lcs(char s1[], char s2[], int m, int n)
{
	int lcs[NMAX][NMAX] = {};
	int i, j, max_i, max_j, max = 0;

	// Find all longest common suffix for all subsets
	for(i = 1; i <= m; i++) {
		for(j = 1; j <= n; j++) {
			if(s1[i-1] == s2[j-1]) {
				lcs[i][j] = 1 + lcs[i-1][j-1];
			} else {
				lcs[i][j] = 0;
			}

			// Find maximum such longest common suffix, this becomes the lcs(ubstring)
			if(lcs[i][j] > max) {
				max_i = i;	
				max_j = j;
				max = lcs[i][j];
			}
		}
	}

	printf("Longest common substring length=%d\n", max);

	if(max)
	for(i = max_i - max; i < max_i; i++) {
		printf("%c", s1[i]);
	}
	printf("\n");
}

int main() {
	char *s1 = "ABAB";
	char *s2 = "BABA";

	find_lcs(s1, s2, 4, 4);
}
