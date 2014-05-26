#include<stdio.h>
#include<stdlib.h>

typedef struct segtree {
	struct segtree *left;
	struct segtree *right;
	// interval
	int s;
	int e;

	int m;	// some merging of left and right, can be sum
} segtree;

segtree *build_segtree(int a[], int i, int j)
{
	int mid;
	segtree *s;
	s = calloc(sizeof(*s),1);

	if(i == j) {
		s->m = a[i];
		s->s = i;
		s->e = i;
		return s;
	}
	mid = (i + j) / 2;

	s->s = i;
	s->e = j;
	s->left = build_segtree(a, i, mid);
	s->right = build_segtree(a, mid + 1, j);

	if(s->left)
		s->m += s->left->m;
	if(s->right)
		s->m += s->right->m;

	return s;
}
