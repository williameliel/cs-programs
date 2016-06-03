/*
 * Given a tree, find the largest subtree with identical left and right subtrees
 */

int maxnum = 0;
tree *maxtree;

typdef struct {
	int num;
	int val;
} bret;

bret getval(tree *t)
{
	bret ret = {}, left, right;

	if (!t)
		return ret;

	if (!t->left && !t->right) {
		ret.num = 1;
		ret.val = t->data;
	}

	left = getval(t->left);
	right = getval(t->right);

	ret.val = (2*left.val) + (3*right.val) + (5*(t->data));
	ret.num = left.num + right.num + 1;

	if (left == right && ret.num > maxnum) {
		maxnum = ret.num;
		maxtree = t;
	}

	return ret;
}
