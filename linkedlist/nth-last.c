/*
 * Different types of Linked List reversals
 */

#include<stdio.h>
#include<stdlib.h>

struct node {
	int n;
	struct node *next;
};

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

void skip_k_rev_k(struct node *head, int k)
{
	struct node *prev, *save, *save_skipped_last, *save_rev_first;

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

	create_nodes(head);

	print_list(head);

	nth = nth_last(head, 5);

	if(nth)
		printf("nth last=%d\n", nth->n);

	return 0;
}

