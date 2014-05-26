#include<stdio.h>
#include<string.h>

void print_all_rotations(char *str)
{
	int len, i, j, cur;

	if (!str)
		return;

	len = strlen(str);
	for(i = 0; i < len; i++) {
		// print after i rotations
		j = i;
		do {
			printf("%c", str[j]);
			j = (j+1) % len;
		} while (j != i);

		printf("\n");
	}
}

void main() {
	print_all_rotations("TOP");
}
