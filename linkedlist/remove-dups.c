#include<stdio.h>
#include<stdlib.h>


// remove duplicates

typedef struct node {
	struct node *next;
	int n;
} node;


struct node *create_node(int a) {
	struct node *head;
	head = malloc(sizeof(struct node));
	if (head) {
		head->n = a;
		head->next = NULL;
	} else {
		perror("malloc failed\n");
	}
	return head;
}

void print_list(struct node *head) {
	printf("Printing LL...\n");
	while(head) {
		printf("Current element:  %d\n", head->n);
		head = head->next;
	}
	printf("Done...\n");
}

void create_nodes(struct node *cur) {
	for(int i = 2; i < 10; i++) {
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


void remove_dups(node *head)
{
	node *tail, *i, *j;

	if (!head || !head->next)
		return;

	tail = head; // tail->next stores next unique

	for(i = head->next; i != NULL; i = i->next) {
		// search for all elements till i == tail->next
		for(j = head; j != tail->next; j++) {
			if (i->n == j->n)
				break;
		}

		if(j == tail->next) {
			tail->next->n = i->n;
			tail = tail->next;
		}
	}
	tail->next = NULL;
}

int main() {
	struct node *head;
	head = create_node(1);

	create_nodes(head);

	head->next->next->next->n=1;
	head->next->next->next->next->n=3;
	head->next->next->next->next->next->n=2;

	print_list(head);

	remove_dups(head);

	printf("After removing dups....\n");

	print_list(head);

	return 0;
}


