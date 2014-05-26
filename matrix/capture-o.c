// http://yihuad.blogspot.com/2013/10/surrounded-regions-leetcode.html
#include <stdio.h>

#define Z 5

void dfs(int a[Z][Z], int p, int q)
{
	if(p < 0 || p > Z-1 || q < 0 || q > Z-1)
		return;

	if(a[p][q] != 'O')
		return;

	a[p][q] = 'N';

	dfs(a, p+1, q);
	dfs(a, p, q+1);
	dfs(a, p-1, q);
	dfs(a, p, q-1);

	// Extension, check diags also
	dfs(a, p-1, q-1);
	dfs(a, p+1, q-1);
	dfs(a, p-1, q+1);
	dfs(a, p+1, q+1);
}

void cap(int m[Z][Z])
{
	int i, j;

	for(i = 0; i < Z; i++) {
		dfs(m, i, 0);
		dfs(m, i, Z-1);
	}

	for(j = 0; j < Z; j++) {
		dfs(m, 0, j);
		dfs(m, Z-1, j);
	}

	for(i = 0; i < Z; i++)
		for(j = 0; j < Z; j++) {
			if(m[i][j] == 'O')
				m[i][j] = 'X';
			if(m[i][j] == 'N')
				m[i][j] = 'O';
		}
}

int main()
{
	int i, j;
	int m[Z][Z] =
	{
	{ 'X', 'O', 'X', 'X', 'X'},
	{ 'X', 'X', 'O', 'X', 'X'},
	{ 'X', 'X', 'O', 'O', 'X'},
	{ 'X', 'X', 'O', 'O', 'X'},
	{ 'X', 'X', 'X', 'X', 'X'}};

	cap(m);

	for(i = 0; i < Z; i++) {
		for(j = 0; j < Z; j++) {
			printf("%c ", (char)m[i][j]);
		}
		printf("\n");
	}
}
