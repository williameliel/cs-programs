typedef struct node {
	int n;
	struct node *next;
} node_t;

node_t *create_node(int a) {
	node_t *head;
	head = malloc(sizeof(node_t));
	if (head) {
		head->n = a;
		head->next = NULL;
	} else {
		perror("malloc failed\n");
	}
	return head;
}

void print_list(node_t *head) {
	printf("Printing LL...\n");
	while(head) {
		printf("Current element:  %d\n", head->n);
		head = head->next;
	}
	printf("Done...\n");
}

/*
 * Create n additional nodes after current
 * assigning the data incrementally starting with 2
 */
void create_nodes(node_t *cur, int n) {
	for(int i = 2; i <= n; i++) {
		cur->next = create_node(i);
		if(cur->next) {
			cur = cur->next;
		}
		else {
			printf("Error: Couldn't create new node\n");
			exit(1);
		}
	}
}
