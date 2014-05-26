#include "tree.h"

void main() {
	tree *t = NULL;
	insert_tree(NULL, &t, 4);
	insert_tree(t, &t, 3);
	insert_tree(t, &t, 1);
	insert_tree(t, &t, 6);
	insert_tree(t, &t, 2);
	insert_tree(t, &t, 5);

	delete_tree(&t, 1);
	delete_tree(&t, 4);

	print_tree(t);
}
