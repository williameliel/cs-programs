#include<stdio.h>
#include "../dsc/graphs.h"
#include "../dsc/queue.h"

void bfs(graph *g, int s) {
	int u, i;
	queue *q;
	edgeNode *e;

	int parent[VMAX+1];
	bool visited[VMAX+1];
	bool processed[VMAX+1];

	q = init_q(VMAX+1);

	for(i = 1; i < g->nvertices; i++) {
		parent[i] = -1;
		visited[i] = false;
		processed[i] = false;
	}

	visited[s] = true;
	enqueue(q, s);

	while(empty_queue(q) == false) {
		dequeue(q, &u);
		processed[u] = true;

		printf("Processed %d\n", u);

		e = g->edges[u];

		for(; e; e = e->next) {
			/* The idea here is 
				For an undirected graph, if the opposite vert of
				the edge hasn't been processed, then we are seeing
				this edge for the first time. Otherwise we would've
				already traversed this edge in the reverse-direction
				when the opp. vert of the edge was processed.
				This is not true for DAGs however, in a DAG it is
				possible that the opposite vert of the edge has already
				been processed but the edge is not traversed yet. This
				can happen if the opposite vert has this edge as an
				incoming edge */
			if(processed[e->y] == false || g->directed) {
				/* process edge e*/
			}
			if(!visited[e->y]) {
				visited[e->y] = true;
				parent[e->y] = u;
				enqueue(q, e->y);
			}
		}
	}

	for(i = 1; i <= g->nvertices; i++)
		printf("%d -> %d\n", parent[i], i);
}

int main() {
        graph *g;
        g = init_graph(false);

        add_edge(g, 1, 2, 3, false);
        add_edge(g, 1, 3, 8, false);
        add_edge(g, 1, 4, 5, false);
        add_edge(g, 2, 4, 7, false);
        add_edge(g, 3, 4, 9, false);

	printf("g->nvertices=%d\n", g->nvertices);
	bfs(g, 1);
}
