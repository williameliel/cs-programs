#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "queue.h"

main() {
	int n;
	queue *q;
	q = init_q(5);

	printf("%d\n", enqueue(q, 3));
	printf("%d\n", enqueue(q, 4));
	printf("%d\n", enqueue(q, 1));
	printf("%d\n", enqueue(q, 2));
	printf("%d\n", enqueue(q, 5));
	printf("%d\n", enqueue(q, 6));

	while(dequeue(q, &n) != -1)
		printf("dequeued %d\n", n);
}
