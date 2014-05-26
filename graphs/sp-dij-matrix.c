// A C / C++ program for Prim's Minimum Spanning Tree (DST) algorithm. 
// The program is for adjacency matrix representation of the graph
 
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
 
// Number of vertices in the graph
#define V 5
 
// A utility function to find the vertex with minimum key value, from
// the set of vertices not yet included in DST
int minKey(int key[], bool dstSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < V; v++)
     if (dstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;
 
   return min_index;
}
 
// A utility function to print the constructed DST stored in parent[]
int printDST(int parent[], int n, int graph[V][V])
{
   printf("Edge   Weight\n");
   for (int i = 0; i < V; i++)
	if(parent[i] != -1)
	      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}
 
// Function to construct and print DST for a graph represented using adjacency
// matrix representation
void primDST(int graph[V][V])
{
     int parent[V]; // Array to store constructed DST
     int key[V];   // Key values used to pick minimum weight edge in cut
     bool dstSet[V];  // To represent set of vertices not yet included in DST
 
     // Initialize all keys as INFINITE
     for (int i = 0; i < V; i++)
        key[i] = INT_MAX, dstSet[i] = false;
 
     // Always include first 1st vertex in DST.
     key[1] = 0;     // Make key 0 so that this vertex is picked as first vertex
     parent[1] = -1; // First node is always root of DST 
 
     // The DST will have V vertices
     for (int count = 0; count < V-1; count++)
     {
        // Pick thd minimum key vertex from the set of vertices
        // not yet included in DST
        int u = minKey(key, dstSet);
 
        // Add the picked vertex to the DST Set
        dstSet[u] = true;
 
        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in DST
        for (int v = 0; v < V; v++)
 
           // graph[u][v] is non zero only for adjacent vertices of m
           // dstSet[v] is false for vertices not yet included in DST
           // Update the key only if graph[u][v] is smaller than key[v]
          if (graph[u][v] && dstSet[v] == false && graph[u][v] + key[u] < key[v])
             parent[v]  = u, key[v] = graph[u][v] + key[u];
     }
 
     // print the constructed DST
     printDST(parent, V, graph);
}
 
 
// driver program to test above function
int main()
{
   /* Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */
   int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 1},
                      {6, 8, 0, 0, 9},
                      {0, 5, 1, 9, 0},
                     };

    // Print the solution
    primDST(graph);
 
    return 0;
}
