#include<stdio.h>
#include<string.h>

// abcdxabcd
// abcdmaaaaaaaaartinxabcd

int find_mismatch(char *str, char *inserted, int s, int e)
{
	int mid;

	if(s == 0 && inserted[0] != str[0])
		return 0;

	if(s == e)
		return -1;

	mid = (s + e) / 2;

	if(str[mid] == inserted[mid] && str[mid+1] != inserted[mid+1]) {
		// TODO: check for false positives
		return mid;
	}

	else if(str[mid] != inserted[mid])
		return find_mismatch(str, inserted, s, mid - 1);
	else
		return find_mismatch(str, inserted, mid + 1, e);
}

int main()
{
	char s[] = "abcd";
	char si[] = "abmatricd";
	int n, nc;
	n = strlen(si) - strlen(s);

	nc = find_mismatch(s, si, 0, strlen(s)-1);
	if(nc > 0)
		nc++;

	if(nc < 0) {
		if(strlen(si) > strlen(s)) {
			// string inserted in the end
			nc = strlen(s);
		}
	}

	if(nc < 0) {
		printf("not found\n");
	}
	else {
		si[nc + n] = '\0';
		printf("string is %s\n", si + nc);
	}
}
