#include <stdio.h>

/*
 * http://www.google.com/url?q=http%3A%2F%2Fwww.careercup.com%2Fquestion%3Fid%3D15556758&sa=D&sntz=1&usg=AFQjCNFkzHcvSYVimFbiE0GKHScaOe54Vw
 */
#define N 4

double probdeath(int x,int y, int n)
{
	int corner = 0;
	int left = 0;
	int right = 0;

	if(n == 0)
		return 0;

	// top left
	if(x - 1 < 0 && y - 1 < 0)
		return ( (0.25 * probdeath(x+1, y, n-1)) + (0.25 * probdeath(x, y+1, n-1)) + 0.5 );

	// top right
	if(x - 1 < 0 && y + 1 >= N)
		return ( (0.25 * probdeath(x+1, y, n-1)) + (0.25 * probdeath(x, y-1, n-1)) + 0.5 );

	// bottom left
	if(x + 1 >= N && y - 1 < 0)
		return ( (0.25 * probdeath(x-1, y, n-1)) + (0.25 * probdeath(x, y+1, n-1)) + 0.5 );

	// bottom right
	if(x + 1 >= N && y + 1 >= N)
		return ( (0.25 * probdeath(x-1, y, n-1)) + (0.25 * probdeath(x, y-1, n-1)) + 0.5 );

	// top edge
	if(x - 1 < 0)
		return ( 0.25 + (0.25 * probdeath(x, y-1, n-1)) + (0.25 * probdeath(x, y+1, n-1)) + (0.25 * probdeath(x+1, y, n-1)) );

	// left edge
	if(y - 1 < 0)
		return ( 0.25 + (0.25 * probdeath(x-1, y, n-1)) + (0.25 * probdeath(x+1, y, n-1)) + (0.25 * probdeath(x, y+1, n-1)) );

	// bottom edge
	if(x + 1 >= N)
		return ( 0.25 + (0.25 * probdeath(x, y-1, n-1)) + (0.25 * probdeath(x, y+1, n-1)) + (0.25 * probdeath(x-1, y, n-1)) );

	// right edge
	if(y + 1 >= N)
		return ( 0.25 + (0.25 * probdeath(x-1, y, n-1)) + (0.25 * probdeath(x+1, y, n-1)) + (0.25 * probdeath(x, y-1, n-1)) );


	// center
	return ( (0.25 * probdeath(x-1, y, n-1)) + (0.25 * probdeath(x, y-1, n-1)) + (0.25 * probdeath(x, y+1, n-1)) + (0.25 * probdeath(x+1, y, n-1)) );
}

double probalive(int x,int y, int n)
{
	return (1 - probdeath(x, y, n));
}

int main() {
	printf("prob %f\n", probalive(1, 1, 2));
}
