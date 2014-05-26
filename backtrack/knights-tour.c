#include<stdio.h>
#include<stdlib.h>

// Size of board
#define Z 5

typedef struct tour {
	int r;
	int c;
	struct tour *next;
} tour;

#define visit(x, y) \
	rt = bt(visited, nt, r+x, c+y, n_visited); \
	if(rt) return rt;

tour *bt(int visited[Z][Z], tour *t, int r, int c, int n_visited)
{
	tour *nt, *rt;

	if(r < 0 || r > Z-1 || c < 0 || c > Z-1)
		return NULL;

	if(visited[r][c])
		return NULL;

	visited[r][c] = 1;

	nt = malloc(sizeof(*nt));
	nt->r = r;
	nt->c = c;
	nt->next = t;

	n_visited++;

	// are we done?
	if(n_visited == Z*Z)
		return nt;

	// recursively visit (step on) each of the options
	visit( 1,  2);
	visit( 2,  1);
	visit(-1,  2);
	visit(-2,  1);
	visit(-2, -1);
	visit(-1, -2);
	visit( 1,  -2);
	visit( 2,  -1);

	// nothing worked, free our end of tour and return
	free(nt);

	visited[r][c] = 0;
	return NULL;
}

void main()
{
	tour *t;
	int visited[Z][Z] = {};
	t = bt(visited, NULL, 0, 0, 0);

	for(; t; t = t->next)
		printf("(%d, %d)\n", t->r, t->c);
}



