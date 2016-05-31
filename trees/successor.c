// not compiled

/* Another way is to do inorder traversal from the top and get it in O(h) - like isbst */

tree *succ(tree *t)
{
	if(!t)
		return t;

	if(t->right) {
		// Find left most child of right node
		parent = t->right;
		child = parent->left;

		while (child) {
			parent = child;
			child = parent->left;
		}

		return parent;
	} else {
		child = t;
		parent = t->parent;

		while (parent && parent->right == child) {
			child = parent;
			parent = child->parent;
		}

		return parent;
	}
}
