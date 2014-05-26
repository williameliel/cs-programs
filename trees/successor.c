// not compiled

tree *succ(tree *t)
{
	tree *parent = t;
	if(t)
		return;

	if(parent->right) {
		// Find left most child of right node
		child = parent->right;
		do {
			parent = child;
			child = parent->left;
		} while(child);

		return parent;
	} else {
		// Find immediately right parent
		do {
			child = parent;
			parent = child->parent;
		} while(parent && parent->right == child);

		return parent;
	}
}
