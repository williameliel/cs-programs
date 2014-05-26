#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "stack.h"

/* Note anytime we encounter a case where we have to pop all the way till the
   end, then the correct value of s[i] = i+1. for this reason we set r=-1 for
   such cases, and the i-r gives the correct result */

void span(int a[], int s[], int n) {
	int i, c, r, found;
	struct Stack *st;

	st = create_stack(n);

	for(i = 0; i < n; i++) {
		/* r = -1 set for i=0 case who can't pop anymore */
		r = -1;
		while(pop(st, &r) != -1) {
			if(a[r] >= a[i]) {
				push(st, r);
				break;
			}
			else {
				/* r = -1 set for case where next pop fails  */
				r = -1;
			}
		}
		push(st, i);
		s[i] = (i-r);
	}
}

int main()
{
	int a[] = { 10, 2, 4, 9, 3};
	int s[5];
	int i;

	span(a, s, 5);
	for(i = 0; i < 5; i++)
		printf("%d\t%d\n", a[i], s[i]);
	
	return 0;
}
