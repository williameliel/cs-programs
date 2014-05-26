#include<stdlib.h>
#include<stdbool.h>
#define VMAX 100

struct _edgeNode {
	int y;
	int wt;
	struct _edgeNode *next;
};

typedef struct _edgeNode edgeNode;

typedef struct {
	edgeNode *edges[VMAX+1];
	int nedges;
	int nvertices;
	bool directed;
} graph;

graph *init_graph(bool directed, int nvertices) {
	graph *g = calloc(sizeof(graph),1);
	g->directed = directed;
	/* For directed graphs, calculating nvertices is
	   difficult, so pass it along */
	if(directed)
		g->nvertices = nvertices;

	return g;
}

int add_edge(graph *g, int u, int v, int w, bool directed) {
	edgeNode *e;
	
	if(u < 1 || u > VMAX || v < 1 || v > VMAX)
		return -1;

	/* nvertices calculation only done for undirected graphs */
	if(!g->directed && !g->edges[u])
		g->nvertices++;

	e = malloc(sizeof(edgeNode));
	if(!e)
		return -1;

	e->y = v;
	e->wt = w;
	e->next = g->edges[u];
	g->edges[u] = e;

	if(!directed)
		return add_edge(g, v, u, w, true);
	else
		g->nedges++;

	return 0;
}

void print_graph(graph *g) {
	int i = 0;
	edgeNode *e;

	for(i = 1; i < g->nvertices; i++) {
		e = g->edges[i];
		for(; e; e = e->next) {
			if(e->y > i) /* Avoid printing backedges */
				/* BUG: Here we assume nodes are in topological order
				 * wrt breadth first but may not be the case */
				printf("%d -> %d (wt=%d)\n", i, e->y, e->wt);
		}
	}
}
