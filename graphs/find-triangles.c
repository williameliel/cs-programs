#include<stdio.h>
#include<stdbool.h>
#include "dfs-tri.h"

bool discovered[VMAX+1];
bool processed[VMAX+1];
int parent[VMAX+1];

int main()
{
	int i;
        graph *g;

        g = init_graph(true, 4);

        add_edge(g, 1, 2, 3, false);

        add_edge(g, 1, 3, 3, false);
        add_edge(g, 2, 3, 3, false);

        add_edge(g, 1, 4, 3, false);
        add_edge(g, 2, 4, 3, false);
        add_edge(g, 3, 4, 3, false);

        add_edge(g, 1, 5, 3, false);
        add_edge(g, 2, 5, 3, false);
        add_edge(g, 3, 5, 3, false);
        add_edge(g, 4, 5, 3, false);



	dfs_tri(g, 1, -1);

	printf("number of triangles = %d\n", tri);
}

