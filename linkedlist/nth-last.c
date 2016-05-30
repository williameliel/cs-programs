/*
 * Different types of Linked List reversals
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

struct node *nth_last(struct node *head, int n)
{
	struct node *tmp;
	if(n <= 0) return NULL;

	tmp = head;
	while(n--) {
		if(!tmp)
			return NULL;
		tmp = tmp->next;
	}

	while(tmp) {
		tmp = tmp->next;
		head = head->next;
	}

	return head;
}

int main() {
	struct node *head, *nth;
	head = create_node(1);

	create_nodes(head, 10);

	print_list(head);

	nth = nth_last(head, 5);

	if(nth)
		printf("nth last=%d\n", nth->n);

	return 0;
}

