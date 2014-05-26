#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define M 3
#define N 4

bool findpath(int m[M][N], char *str, int i, int j, int path[M][N])
{
	bool ret;

	if(!str || !(*str))
		return true;

	if(i < 0 || j < 0 || i > M || j > N)
		return false;

	if(path[i][j] == 1)
		return false;

	if(*str != m[i][j])
		return false;
	else {
		if(strlen(str) == 1)
			return true;
	}

	path[i][j] = 1;

	ret = findpath(m, str+1, i+1, j, path);
	if(ret == true)
		return ret;

	ret = findpath(m, str+1, i, j+1, path);
	if(ret == true)
		return ret;


	ret = findpath(m, str+1, i-1, j, path);
	if(ret == true)
		return ret;


	ret = findpath(m, str+1, i, j-1, path);
	if(ret == true)
		return ret;

	path[i][j] = 0;
	return false;
}

int main()
{
	bool ret;
	int i, j;
	char str[] = "follow";
	int m[M][N] =	{	{ 'o', 'f', 'a', 's' },
				{ 'l', 'x', 'q', 'w' },
				{ 'z', 'o', 'w', 'k' }		};
	int path[M][N] = {};

	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			if(m[i][j] == str[0]) {
				ret = findpath(m, str, i, j, path);
				if(ret) {
					printf("found\n"); return 0;
				}
			}
		}
	}
 }
