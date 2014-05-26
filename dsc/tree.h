#include <stdlib.h>
#include <stdio.h>

typedef struct tree {
	struct tree *left;
	struct tree *right;
	struct tree *parent;
	int e;
} tree;

tree *create_tree(int e) {
	tree *t;
	t = calloc(sizeof(tree), 1);
	t->e = e;
	return t;
}

void insert_tree(tree *parent, tree **t, int e) {
	if(!*t) {
		*t = create_tree(e);
		(*t)->parent = parent;
		return;
	}

	if(e < (*t)->e)
		insert_tree(*t, &(*t)->left, e);
	else
		insert_tree(*t, &(*t)->right, e);
}

void delete_tree(tree **t, int e) {
	tree *this = *t, *succ;

	if(!this) {
		/* Not found */
		return;
	}

	if(this->e == e) {
		// Found node to delete
		if(this->left && this->right) {
			// Take immediate successor
			succ = this->right;
			while(succ->left)
				succ = succ->left;

			this->e = succ->e;

			/* This is a bit tricky
			 * We need to know if the succ is the left or right node
			 * of the parent. Accordingly, we modify the corresponding
			 * pointer of the parent.
			 * We set the right node of the successor (NULL or otherwise)
			 * to the corresponding child of the successor's parent
			 * and set the parent of the successor's right node if it exists
			 * to the succesor's parent */
			if(succ->parent->left == succ)
				succ->parent->left = succ->right;
			else
				succ->parent->right = succ->right;

			if(succ->right)
				succ->right->parent = succ->parent;
			free(succ);
			return;
		}
		else if(this->left) {
			*t = this->left;
			this->left->parent = this->parent;
			free(this);
			return;
		}
		else if(this->right) {
			*t = this->right;
			this->right->parent = this->parent;
			free(this);
			return;
		}
		else {
			free(this);
			*t = NULL;
			return;
		}
	}
	else {
		if(e < this->e)
			delete_tree(&this->left, e);
		else
			delete_tree(&this->right, e);
	}
}

#if 0
void insert_sub_tree(tree *parent, tree **t, tree *sub) {
	if(!sub)
		return;

	if(!*t) {
		*t = sub;
		(*t)->parent = parent;
		return;
	}

	if(sub->e < (*t)->e)
		insert_sub_tree(*t, &(*t)->left, sub);
	else
		insert_sub_tree(*t, &(*t)->right, sub);
}


void delete_tree(tree *parent, tree **t, int e) {
	tree *tmp;

	if(!*t)
		return;
	if((*t)->e == e) {
		tmp = *t;
		if((*t)->right) {
			insert_sub_tree((*t)->right, &(*t)->right, (*t)->left);
			*t = (*t)->right;
			(*t)->parent = parent;
		}
		else {
			*t = (*t)->left;
			if(*t)
				(*t)->parent = parent;
		}
		free(tmp);
	}
	else {
		if(e < (*t)->e)
			delete_tree(*t, &(*t)->left, e);
		else
			delete_tree(*t, &(*t)->right, e);
	}
}
#endif

void _print_tree(tree *t, int c, int left) {
	int i;
	if(t) {
		for(i = 0; i < c; i++)
			printf(" ");
		if(c == 0)
			printf("root: %d\n", t->e);
		else if(left)
			printf("left: %d\n", t->e);
		else
			printf("right: %d\n", t->e);
		_print_tree(t->left, c+1, 1);
		_print_tree(t->right, c+1, 0);
	}
}

void print_tree(tree *t) {
	_print_tree(t, 0, 0);
}
