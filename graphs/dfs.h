#include<stdio.h>
#include "../dsc/graphs.h"

bool discovered[VMAX+1];
bool processed[VMAX+1];
int parent[VMAX+1];
int entry_time[VMAX+1];
int time;
typedef enum { FORWARD, BACK, CROSS } edge_class;

edge_class edge_classification(int x, int y) {
	if(discovered[y] && !processed[y])
		return BACK;
	if(processed[y] && entry_time[y] > entry_time[x])
		return FORWARD;
	if(processed[y] && entry_time[y] < entry_time[x])
		return CROSS;
}

void process_edge(int, int);
void process_vertex_early(int);
void process_vertex_late(int);

void dfs(graph *g, int s)
{
	int y;
	edgeNode *e;

	time++;
	entry_time[s] = time;

	discovered[s] = true;

	process_vertex_early(s);

	e = g->edges[s];
	for(; e; e = e->next) {
		y = e->y;
		if(y != parent[s])
			process_edge(s, y);

		if(!discovered[y]) {
			parent[e->y] = s;
			dfs(g, e->y);
		}
	}
	process_vertex_late(s);
	processed[s] = true;
}
