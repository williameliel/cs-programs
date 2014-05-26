#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

int main()
{
	struct Stack *s;
	int ret = 0;

	s = create_stack(3);
	
	printf("push(2) = %d\n", push(s,2));
	printf("push(4) = %d\n", push(s,4));
	printf("push(1) = %d\n", push(s,1));
	printf("push(5) = %d\n", push(s,5));

	while(pop(s, &ret) != -1) {
		printf("popped %d\n", ret);
	}

	return 0;
}
