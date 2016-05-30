/*
 * Different types of Linked List reversals
 */

#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"

void skip_k_rev_k(node_t *head, int n)
{
	node_t *cur, *prev, *lastskipped, *save, *save2;
	int i;

	lastskipped = NULL;
	cur = head;
	i = n;

	while (1) {
		if (i == 0)
			break;
		if (!cur)
			return;
		lastskipped = cur;
		cur = cur->next;
		i--;
	}

	i = n;
	prev = NULL;

	while (i--) {
		if (!cur)
			return;
		save = cur->next;
		cur->next = prev;
		prev = cur;
		cur = save;
	}

	save2 = lastskipped->next;
	lastskipped->next = prev;
	save2->next = cur;
}

int main() {
	node_t *head;
	head = create_node(1);

	create_nodes(head, 10);

	print_list(head);

	skip_k_rev_k(head, 7);

	print_list(head);

	return 0;
}

