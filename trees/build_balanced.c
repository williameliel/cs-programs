//From cracking coding

// Given a sorted array, build a balanced tree

// Program not compiled:

void build(tree *t, int *a, int i, int j) {
	int mid;

	if(i < j)
		return;

	mid = (i+j)/2;
	insert_tree(t, a[mid]);
	build(t, a, i, mid-1);
	build(t, a, mid+1, j);
}
