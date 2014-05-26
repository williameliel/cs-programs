#include<stdio.h>
#include<stdlib.h>

// Given N sorted lists, merge them to return a list with 
// least comparisons and extra space.

typedef struct list {
	int n;
	struct list *next;
} list;

// Max size of any list
#define N

list *merge_n(list *l[], int s, int e)
{
	int mid, cur;
	list *left, *right, *tmp = NULL, *tmp2, *ret = NULL, *savel, *saver;

	if(s == e)
		return l[s];

	mid = (s+e) / 2;

	left = merge_n(l, s, mid);
	right = merge_n(l, mid + 1, e);

	savel = left;
	saver = right;

	while(left && right) {
		tmp2 = calloc(sizeof(list), 1);
		if(left->n < right->n) {
			tmp2->n = left->n;
			left = left->next;
		}
		else {
			tmp2->n = right->n;
			right = right->next;
		}

		if(!tmp)
			ret = tmp2;
		else
			tmp->next = tmp2;

		tmp = tmp2;
	}

	while(left) {
		tmp2 = calloc(sizeof(list), 1);
		tmp2->n = left->n;

		if(!tmp)
			ret = tmp2;
		else
			tmp->next = tmp2;

		tmp = tmp2;
		left = left->next;
	}

	while(right) {
		tmp2 = calloc(sizeof(list), 1);
		tmp2->n = right->n;

		if(!tmp)
			ret = tmp2;
		else
			tmp->next = tmp2;

		tmp = tmp2;
		right = right->next;
	}

	/* Make sure not to free input lists that are passed */
	while(savel && s != mid) {
		tmp = savel;
		free(savel);
		savel = tmp->next;
	}
	
	while(saver && (mid + 1) != e) {
		tmp = saver;
		free(saver);
		saver = tmp->next;
	}
	
	return ret;
}

void listify(list *l, int n) {
	int i = 0;
	l[n-1].next = NULL;

	while(--n) {
		l[i].next = &l[++i];
	}
}

int main() {
	list l1[4] = { { 1, 0 }, { 4, 0 }, { 6, 0 }, { 14, 0 } };
	list l2[4] = { { 3, 0 }, { 5, 0 }, { 8, 0 }, { 10, 0 } };
	list *l[] = { &l1[0], &l2[0] };

	int nl = 2;

	list *ret;

	listify(l1, (sizeof(l1)/sizeof(list)));
	listify(l2, (sizeof(l2)/sizeof(list)));

	ret = merge_n(l, 0, nl - 1);

	while(ret) {
		printf("%d\n", ret->n);
		ret = ret->next;
	}
}



