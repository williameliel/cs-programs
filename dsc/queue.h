/*
 * simple circuilar queue
 * Author: Joel Fernandes <agnel.joel@gmail.com>
 */

typedef struct {
	int front;
	int rear;
	int n;
	int *a;
} queue;

queue *init_q(int n)
{
	queue *q;

	if(n <= 0)
		return NULL;
	q = malloc(sizeof(q));
	q->a = malloc(n*sizeof(int));
	q->n = n;
	q->front = -1;
	q->rear = -1;

	return q;
}

bool empty_queue(queue *q)
{
	return (q->front == -1 && q->rear == -1);
}

bool full_queue(queue *q)
{
	return (q->front + 1) % q->n == q->rear;
}

int enqueue(queue *q, int n)
{
	if(full_queue(q))
		return -1;

	q->front = (q->front + 1) % q->n;
	if(q->rear == -1)
		q->rear = 0;

	q->a[q->front] = n;

	return 0;
}

int dequeue(queue *q, int *n)
{
	if(empty_queue(q))
		return -1;

	*n = q->a[q->rear];

	if(q->front == q->rear) {
		q->front = -1;
		q->rear = -1;
	} else {
		q->rear = (q->rear + 1) % q->n;
	}
	return 0;
}

