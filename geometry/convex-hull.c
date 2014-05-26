#include <stdio.h>
#include<stdlib.h>

typedef struct point {
	int x;
	int y;
} point;

point p0;

struct Stack {
        point *a;
        int n;
        int top;
};

typedef struct Stack stack;

struct Stack *create_stack(int n) {
        struct Stack *ret = NULL;

        ret = malloc(sizeof(*ret));

        if(ret) {
                ret->n = n;
                ret->top = -1;
                ret->a = malloc(sizeof(*ret->a) * n);
                if(!ret->a) {
                        free(ret);
                        return NULL;
                }
        }

        return ret;
}

int push(struct Stack *s, point a) {
        if(!s || s->top == s->n-1)
                return -1;

        s->a[++s->top] = a;
        return 0;
}

int pop(struct Stack *s, point *ret) {
        if(!s || s->top == -1)
                return -1;

        *ret = s->a[s->top--];
        return 0;
}
// return 0 = col, 1 = left, 2 = right
int orient(point p1, point p2, point p3)
{
	int diff;
	diff = ((p2.y - p1.y) * (p3.x - p2.x)) - ((p3.y - p2.y) * (p2.x - p1.x));

	if(!diff)
		return 0;	// col

	return (diff > 0 ? 2 : 1);
}

int compare(const void *pin1, const void *pin2)
{
	point p1, p2;
	p1 = *((point *)pin1);
	p2 = *((point *)pin2);

	int o;
	o = orient(p0, p1, p2);

	if(o == 0) {
		if(p1.x == p2.x && p1.y == p2.y) {
			return 0;
		}
		else if(p1.x < p2.x)
			return -1;
		else
			return 1;
	}

	return (o == 2 ? -1 : 1);
}

point starting(point *p, int n)
{
	point s;
	int i;

	s = *p;
	for(i = 1; i < n; i++)
	{
		if(p[i].y == s.y && p[i].x < s.x) {
			s = p[i];
		} else {
			if(p[i].y < s.y)
				s = p[i];
		}
	}
	return s;
}

int main()
{
	point p[] = { {0,0}, {1,1}, {2,2}, {3,3}, {2,0}, {2,1}, {5,5} };
	int i, n;
	stack *S;
	point tmp;

	n = sizeof(p) / sizeof(point);

	p0 = starting(p, n);

	qsort(p, n, sizeof(point), compare);

	S = create_stack(n);

	push(S, p[0]);
	push(S, p[1]);

	for(i = 2; i < n; i++) {
		while(orient(S->a[S->top-1], S->a[S->top], p[i]) == 1)
			pop(S, &tmp);
		push(S, p[i]);
	}	
	while(pop(S, &tmp) != -1)
		printf("(%d, %d)\n", tmp.x, tmp.y);
}



