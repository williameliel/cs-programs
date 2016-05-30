/*
 * Different types of Linked List reversals
 */

#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"

void skip_k_rev_k(node_t *head, int k)
{
	node_t *prev, *save, *save_skipped_last, *save_rev_first;

	/* Skip k and return if we reach end */
	for(int i = 0; i < k; i++) {
		if(!head)
			return;
		prev = head;
		head = head->next;
	}


	if(!head)
		return;

	/* Save first element in the subset list being reversed */
	save_rev_first = head;

	/* Reverse entire subset list */
	for(int i = 0; i < k; i++) {
		/* Break for cases where we run out list since we still need to fixup */
		if(!head)
			break;
		save = head->next;
		head->next = prev;
		prev = head;
		head = save;
	}

	/* Retrieve last element of the initial skipped list */
	save_skipped_last = save_rev_first->next;

	/* Point it to the last element of the skipped list */
	save_skipped_last->next = prev;

	/* Point last element of the now reversed list to the next element of the list it reversed */
	save_rev_first->next = head;
}

int main() {
	node_t *head;
	head = create_node(1);

	create_nodes(head, 10);

	print_list(head);

	skip_k_rev_k(head, 3);

	print_list(head);

	return 0;
}

