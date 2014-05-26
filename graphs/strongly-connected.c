#include "dfs.h"
#include "../dsc/stack.h"

int sc[VMAX+1];
int low[VMAX+1];
int sc_counter;

stack *st;

void main() {
	int i;
	graph *g;

	g = init_graph(true, 12);

	for(i = 1; i <= g->nvertices; i++) {
		discovered[i] = false;
		processed[i] = false;
		parent[i] = -1;
		entry_time[i] = 0;

		low[i] = i;
		sc[i] = 0;
	}
	sc_counter = 0;
	time = 0;

	st = create_stack(g->nvertices);

	add_edge(g, 1, 12, 0, true);
	add_edge(g, 1, 2, 0, true);
	add_edge(g, 2, 3, 0, true);
	add_edge(g, 3, 4, 0, true);
	add_edge(g, 4, 8, 0, true);
	add_edge(g, 8, 1, 0, true);
	add_edge(g, 1, 5, 0, true);
	add_edge(g, 5, 6, 0, true);
	add_edge(g, 5, 7, 0, true);
	add_edge(g, 6, 8, 0, true);
	add_edge(g, 7, 8, 0, true);
	add_edge(g, 1, 9, 0, true);
	add_edge(g, 4, 9, 0, true);
	add_edge(g, 9, 10, 0, true);
	add_edge(g, 10, 11, 0, true);
	add_edge(g, 11, 9, 0, true);


	for(i = 1; i <= g->nvertices; i++) {
		if(!discovered[i])
			dfs(g, 1);
	}

	for(i = 1; i <= g->nvertices; i++) {
		printf("%d -> %d\n", i, sc[i]);
	}
}

void process_edge(int u, int v)
{
	printf("processing edge %d -> %d\n", u, v);
	edge_class class = edge_classification(u, v);
	if(class == BACK) {
		printf("Its back\n");
		if(entry_time[low[v]] < entry_time[low[u]]) {
			printf("Setting %d's low to %d\n", u, low[v]);
			low[u] = low[v];
		}
	}
	else if(class == CROSS) {
		printf("Its cross\n");
		/* Don't add nodes that are already in SCs */
		if(!sc[v]) {
			if(entry_time[low[v]] < entry_time[low[u]]) {
				printf("Setting %d's low to %d\n", u, low[v]);
				low[u] = low[v];
			}
		}
	}
}

void process_vertex_early(int s) {
	if(push(st, s) < 0)
		printf("couldn't push\n");
}

void process_vertex_late(int s) {
	int r;

	if(low[s] == s) {
		sc_counter++;
		printf("popping all under %d\n", s);
		/* Need to pop all the elements on stack and set their SC */
		while(pop(st, &r) != -1) {
			sc[r] = sc_counter;
			if(r == s)
				break;
		}
	} else {
		if(entry_time[low[s]] < entry_time[low[parent[s]]])
			low[parent[s]] = low[s];
	}
}












