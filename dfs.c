#include <stdio.h>
#include <stdlib.h>

int visited[4] = {0, 0, 0, 0};  // Tracking visited nodes
int arr[4][4] = {               // Corrected 4x4 adjacency matrix
    {0, 1, 0, 1},  // Vertex 0 is connected to 1 and 3
    {1, 0, 1, 0},  // Vertex 1 is connected to 0 and 2
    {0, 1, 0, 0},  // Vertex 2 is connected to 1
    {1, 0, 0, 0}   // Vertex 3 is connected to 0
};

void dfs(int i) {
    int j;

    printf("Visited node: %d\n", i);
    visited[i] = 1;

    for (j = 0; j < 4; j++) {
        if (arr[i][j] == 1 && !visited[j]) {
            dfs(j);
        }
    }
}

int main() {
    dfs(0);  // Start DFS from vertex 0
    return 0;
}

/*DFS Algorithm:
Initialize:

-Create a visited[] array to track visited vertices.
-Define the adjacency matrix arr[4][4] representing the graph.

DFS Function (dfs(int i)):

-Mark vertex i as visited: visited[i] = 1.
-Print "Visited node: i".
-For each vertex j (from 0 to 3):
-If arr[i][j] == 1 (edge exists) and visited[j] == 0, recursively call dfs(j).

Main Function:

-Call dfs(0) to start DFS traversal from vertex 0.*/