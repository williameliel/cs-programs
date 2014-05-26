#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#include "../dsc/graphs.h"

int findMin(graph *g, int *pq, bool *added) {
	int i = 1, min = INT_MAX, min_i;
	for(i = 0; i <= g->nvertices; i++) {
		if(pq[i] < min && !added[i]) {
			min = pq[i];
			min_i = i;
		}
	}
	return min_i;
}

void sp(graph *g, int s) {
	int parent[VMAX+1];
	bool *added;
	int *pq, i, u;
	edgeNode *e;

	added = malloc(sizeof(bool)*(g->nvertices+1));
	pq = malloc(sizeof(int)*(g->nvertices+1));

	for(i = 1; i <= g->nvertices; i++) {
		added[i] = false;
		pq[i] = INT_MAX;
		parent[i] = -1;
	}

	pq[s] = 0;

	for(i = 1; i <= g->nvertices; i++) {
		u = findMin(g, pq, added);
		added[u] = true;

		e = g->edges[u];
		for(; e; e = e->next) {
			if(!added[e->y] && e->wt + pq[u] < pq[e->y]) {
				pq[e->y] = pq[u] + e->wt;
				parent[e->y] = u;
			}
		}
	}

	for(i = 1; i <= g->nvertices; i++) {
		printf("%d -> %d (distance from %d = %d)\n", parent[i], i, s, pq[i]);
	}
}


// driver program to test above function
int main()
{
   /* Let us create the following graph
          2    3
      (1)--(2)--(3)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (4)-------(5)
            9       */

	graph *g;
	g = init_graph(false, 0);

	add_edge(g, 1, 2, 2, false);
	add_edge(g, 1, 4, 6, false);
	add_edge(g, 2, 3, 3, false);
	add_edge(g, 2, 4, 8, false);
	add_edge(g, 2, 5, 5, false);
	add_edge(g, 3, 5, 1, false);
	add_edge(g, 4, 5, 9, false);


	sp(g, 1);
}
