#include<stdio.h>
#include "../graphs/dfs.h"

void process_edge(int a, int b) {}
void process_vertex_early(int a) {}
void process_vertex_late(int a) {}

int tri;

void process_edge_tri(graph *g, int s, int p, int y)
{
	edgeNode *e;

	if(p == -1)
		return;

	if(discovered[y] == true) {
		e = g->edges[y];
		// check for triangle by checking edge p-y
		while(e) {
			if(e->y == p) {
				tri++;
				break;
			}
			e = e->next;
		}
	}
}

void dfs_tri(graph *g, int s, int prev)
{
	int y;
	edgeNode *e;

	discovered[s] = true;

	e = g->edges[s];
	for(; e; e = e->next) {
		y = e->y;
		if(y != parent[s])
			process_edge_tri(g, s, prev, y);

		if(!discovered[y]) {
			parent[e->y] = s;
			dfs_tri(g, e->y, s);
		}
	}
}
