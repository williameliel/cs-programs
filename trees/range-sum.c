#include "segment-tree.h"

/*
 * http://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/
 * O(log(n)) time to find the sum of a given range in an array!
 */

int findsum(segtree *t, int s, int e)
{
	int sl, sr;

	if(t->s >= s && t->e <= e)
		return t->m;
	else if( (t->s < s && t->e < s) || (t->s > e && t->e > e) )
		return 0;
	else {
		sl = findsum(t->left, s, e);
		sr = findsum(t->right, s, e);
		return (sl + sr);
	}
}

int main()
{
	int arr[] = {1, 3, 5, 7, 9, 11};
	int n = sizeof(arr)/sizeof(arr[0]);

	segtree *t;

	t = build_segtree(arr, 0, n-1);

	printf("sum = %d\n", findsum(t, 1, 4));
	return 0;
}
