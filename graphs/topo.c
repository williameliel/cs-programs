#include<stdio.h>
#include "../dsc/graphs.h"

bool discovered[VMAX+1];
bool processed[VMAX+1];
int parent[VMAX+1];

int sorted[VMAX];
int cur;

void process_edge(int v, int y) {
	printf("processing edge %d -> %d\n", v, y);
}

void dfs(graph *g, int s)
{
	int y;
	edgeNode *e;

	discovered[s] = true;

	e = g->edges[s];
	for(; e; e = e->next) {
		y = e->y;

		if(discovered[y] && !processed[y] && g->directed)
			printf("Cycle found.. backedge %d -> %d\n", s, y);

		if((!processed[y] && y != parent[s]) || g->directed)
			process_edge(s, y);

		if(!discovered[y]) {
			parent[e->y] = s;
			dfs(g, e->y);
		}
	}
	processed[s] = true;
	printf("processed %d\n", s);
	sorted[cur++] = s;
}
	

int main() {
	int i;
        graph *g;

#if 0
        g = init_graph(false);
        add_edge(g, 1, 2, 3, false);
        add_edge(g, 1, 3, 8, false);
        add_edge(g, 1, 4, 5, false);
        add_edge(g, 2, 4, 7, false);
        add_edge(g, 3, 4, 9, false);
#else
        g = init_graph(true, 5);

        add_edge(g, 1, 2, 3, true);
        add_edge(g, 1, 3, 8, true);
        add_edge(g, 1, 5, 8, true);
	add_edge(g, 2, 3, 8, true);
        add_edge(g, 3, 4, 9, true);
        add_edge(g, 3, 5, 9, true);
        add_edge(g, 5, 4, 5, true);
#endif

/* init dfs */
	for(i = 0; i < g->nvertices; i++) {
		discovered[i] = false;
		processed[i] = false;
		parent[i] = -1;
	}

	cur = 0;
	dfs(g, 1);

/* print tree 
	for(i = 1; i <= g->nvertices; i++)
		printf("%d -> %d\n", parent[i], i);
*/

/* print topo sorted */
	for(i = cur-1; i >= 0; i--)
		printf("%d\n", sorted[i]);
}
