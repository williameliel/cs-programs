/*
 * http://www.careercup.com/question?id=4716965625069568
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define Z 3

typedef struct pair {
	int p;
	int q;
} pair;

typedef struct queue {
	int front;
	int rear;
	pair *a;
	int n;
} queue;

queue *create_queue(int n)
{
	queue *q;
	q = malloc(sizeof(queue));
	q->a = calloc(sizeof(*(q->a)), n);
	if(!q) return q;
	q->n = n;
	q->front = -1;
	q->rear = -1;
	return q;
}

void enqueue(queue *q, pair p)
{
	if((q->front + 1) % q->n == q->rear) {
		printf("queue full\n");
		return;
	}

	q->front = (q->front + 1) % q->n;
	q->a[q->front] = p;

	if(q->rear == -1)
		q->rear = q->front;
}

int dequeue(queue *q, pair *p)
{
	if(q->front == -1)
		return -1;

	*p = q->a[q->rear];

	if(q->rear == q->front) {
		q->rear = -1;
		q->front = -1;
	} else {
		q->rear = (q->rear+1) % q->n;
	}
}

void visit(int m[Z][Z], int disc[Z][Z], int dist, int p, int q, queue *qu)
{
	pair p1;
	if(p < 0 || p >= Z || q < 0 || q >= Z)
		return;
	if(m[p][q] == 'G' || m[p][q] == 'B' || dist >= m[p][q])
		return;
	m[p][q] = dist;
	p1.p = p;
	p1.q = q;
	enqueue(qu, p1);
	disc[p][q] = 1;
}


void bfs(int m[Z][Z], int p, int q)
{
	queue *qu;
	pair p1;
	int disc[Z][Z] = {};
	int dist;

	if(m[p][q] != 'G')
		return;

	p1.p = p;
	p1.q = q;

	qu = create_queue(100);

	enqueue(qu, p1);
	disc[p1.p][p1.q] = 1;

	while(dequeue(qu, &p1) != -1) {
		if(m[p1.p][p1.q] == 'G')
			dist = 1;
		else
			dist = m[p1.p][p1.q] + 1;

		visit(m, disc, dist, p1.p-1, p1.q, qu);
		visit(m, disc, dist, p1.p+1, p1.q, qu);
		visit(m, disc, dist, p1.p, p1.q-1, qu);
		visit(m, disc, dist, p1.p, p1.q+1, qu);

	}
}

void find_dist(int m[Z][Z])
{
	int i, j;

	for(i = 0; i < Z; i++) {
		for(j = 0; j < Z; j++) {
			if(m[i][j] == 0)
				m[i][j] = INT_MAX;
		}
	}

	for(i = 0; i < Z; i++)
		for(j = 0; j < Z; j++)
			bfs(m, i, j);
}

int main()
{
	int i, j;
	int m[Z][Z] = {	{  0,   0,   0 },
			{ 'B', 'G', 'G'},
			{ 'B',  0,   0 }	};
	find_dist(m);

	for(i = 0; i < Z; i++) {
		for(j = 0; j < Z; j++) {
			if(m[i][j] >= 'A')
				printf("%c ", (char)m[i][j]);
			else
				printf("%d ", m[i][j]);

		}
		printf("\n");
	}

	return 0;
}

