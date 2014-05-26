#include<stdio.h>
#include<stdbool.h>

#define Z 10

bool isSafe(int b[Z][Z], int x, int y)
{
	int p, q;

	for(p = x, q = y; p < Z && q < Z; p++, q--)
		if(b[p][q])
			return false;

	for(p = x, q = y; p >= 0 && q >= 0; p--, q--)
		if(b[p][q])
			return false;

	for(p = x, q = y; q >= 0; q--)
		if(b[p][q])
			return false;

	return true;
}

bool bt(int brd[Z][Z], int col, int nq)
{
	int i;
	bool r;

	if(nq == 0)
		return true;
	if(col >= Z)
		return false;

	for(i = 0; i < Z; i++) {
		// Check if Queen can be placed
		if(isSafe(brd, i, col)) {
			// place it
			brd[i][col] = 1;

			// see if future columns are happy with this
			r = bt(brd, col+1, nq-1);
			if(r)
				return r;

			// not happy so remove from brd and try others
			brd[i][col] = 0;
		}
	}

	return false;
}

int main()
{
        int i, j;
        int brd[Z][Z] = {};

	bt(brd, 0, 10);

        printf("board: \n");
        for(i = 0; i < Z; i++) {
                for(j = 0; j < Z; j++) {
                        printf("%d ", brd[i][j]);
                }
                printf("\n");
        }
}
