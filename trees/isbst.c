#include "../dsc/tree.h"
#include <stdbool.h>

bool is_bst = true;
int last = -1;

void process(int e)
{
	if (e < last)
		is_bst = false;
	last = e;
}

void inorder(tree *t)
{
	if (!t)
		return;

	inorder(t->left);
	process(t->e);
	inorder(t->right);
}

void main()
{
	tree *t = NULL;
	insert_tree(NULL, &t, 4);
	insert_tree(t, &t, 2);
	insert_tree(t, &t, 1);
	insert_tree(t, &t, 6);
	insert_tree(t, &t, 3);
	insert_tree(t, &t, 5);

	print_tree(t);

	inorder(t);

	printf("Tree is_bst ? = %d\n", is_bst);
}
