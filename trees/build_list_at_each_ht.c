// Cracking coding interview problem

// Not compiled

// Build an linked list at each heigh

node *list[MAX_HT];

void build(tree *t, int c) {
	node *n;

	if(!t)
		return;
	n = malloc(sizeof(node));

	n->t = t;
	n->next = list[c];
	list[c] = n;

	build(t->left, c+1);
	build(t->right, c+1);
}
	
