#include<stdio.h>
#include "../dsc/graphs.h"

int main() {
	graph *g;
	g = init_graph(false);

	add_edge(g, 1, 2, 3, false);
	add_edge(g, 1, 3, 8, false);
	add_edge(g, 1, 4, 5, false);
	add_edge(g, 2, 4, 7, false);
	add_edge(g, 3, 4, 9, false);

	print_graph(g);
}
