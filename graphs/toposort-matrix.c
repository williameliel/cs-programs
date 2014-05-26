#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define V 5

int findMin(int inedges[V], bool added[V])
{
	int min = INT_MAX, i, min_i;
	for(i = 0; i < V; i++) {
		if(inedges[i] < min && !added[i]) {
			min = inedges[i];
			min_i = i;
		}
	}
	return min_i;
}

void printTopo(int g[V][V]) {
	bool added[V];
	int inedges[V];
	int i, j, u, v, c;

	for(i = 0; i < V; i++) {
		c = 0;
		for(j = 0; j < V; j++) {
			if(g[j][i])
				c++;
		}
		inedges[i] = c;
		added[i] = false;
	}

	for(i = 0; i < V; i++) {
		u = findMin(inedges, added);
		added[u] = true;
		printf("%d ", u);
		for(j = 0; j < V; j++) {
			if(g[u][j] && !added[j])
				inedges[j]--;
		}
	}
}

int main()
{

   int graph[V][V] = {{0, 1, 1, 0, 1},
                      {0, 0, 1, 0, 0},
                      {0, 0, 0, 1, 1},
                      {0, 0, 0, 0, 0},
                      {0, 0, 0, 1, 0},
                     };
  printTopo(graph);
}
