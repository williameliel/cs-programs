#include <stdio.h>

int bt(int a[4][4], int out[4][4], int r, int c)
{
	int i, j, ret;

	out[r][c] = 1;

	// solved?
	if(r == 3 && c == 3)
		return 1;

	// down
	if(r < 3 && a[r+1][c] == 1) {
		ret = bt(a, out, r+1, c);
		if(ret)
			return ret;
	}

	// forward
	if(c < 3 && a[r][c+1] == 1) {
		ret = bt(a, out, r, c+1);
		if(ret)
			return ret;
	}

	// unsolvable path
	out[r][c] = 0;
	return 0;
}

int main()
{
	int i, j;
	int maze[4][4] = {
		{1, 0, 0, 1},
		{1, 1, 1, 1},
		{0, 1, 0, 0},
		{1, 1, 1, 1}};
	int out[4][4] = {};

	bt(maze, out, 0, 0);

	printf("out: \n");
	for(i = 0; i < 4; i++) {
		for(j = 0; j < 4; j++) {
			printf("%d ", out[i][j]);
		}
		printf("\n");
	}

	return 0;
}

