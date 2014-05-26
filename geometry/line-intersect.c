#include <stdio.h>

typedef struct point {
	int x;
	int y;
} point;

// return 0 = col, 1 = left, 2 = right
int orient(point p1, point p2, point p3)
{
	int diff;
	diff = ((p2.y - p1.y) * (p3.x - p2.x)) - ((p3.y - p2.y) * (p2.x - p1.x));

	if(!diff)
		return 0;	// col

	return (diff > 0 ? 2 : 1);
}

void swap(int *a, int *b) {
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

int overlaps(int a, int b, int c, int d) {
	int tmp;
	if(a > b) {
		swap(&a, &b);
	}
	if(c > d) {
		swap(&c, &d);
	}

	return ((c >= a && c <= b) || (a >= c && a <= d));
}

int main()
{
	point p1 = {2, 4}, q1 = {2, 2}, p2 = {2, 3}, q2 = {2, 1};
	int xovl, yovl, intersect = 0;

	if(orient(p1, q1, p2) == 0 && orient(p1, q1, q2) == 0)
	{
		// Lines are collinear
		// Check intercept overlap
		xovl = overlaps(p1.x, q1.x, p2.x, q2.x);
		yovl = overlaps(p1.y, q1.y, p2.y, q2.y);
		intersect = (xovl && yovl);
	} else {
		if( (orient(p1, q1, p2) != orient(p1,q1,q2)) && (orient(p2, q2, p1) != orient(p2, q2, q1)) )
			intersect = 1;
	}

	if(intersect)
		printf("Lines intersect\n");
}
