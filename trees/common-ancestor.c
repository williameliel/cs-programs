// not compiled

// Use DP to find out if left side of tree has one of the nodes
// and right has one. If so, then the current node is the ancestor

/*
 * better solution: https://github.com/joelagnel/cs-programs.git
 */

struct res {
	int n;
	tree *t; // Result containing common ancestor
};

struct res search(tree *t, int p, int q)
{
	struct res r1 = {}, r2 = {}, r3 = {};

	if(!t)
		return r1;

	if(t->e == p || t->e == q) {
		r1.n = 1;
		return r1;
	}

	r2 = search(t->left, p, q);
	r3 = search(t->right, p, q);

	r1.n = r2.n + r3.n;

	if(r2.n == 1 && r3.n == 1)
		r1.t = t;
	else
		if(r2.t)
			r1.t = r2.t;
		else
			r1.t = r3.t;
	return r1;
}
