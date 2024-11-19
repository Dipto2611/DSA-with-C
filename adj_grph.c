#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Structure for adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the adjacency list
void addEdge(struct Node* adjList[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

// Function to display the adjacency list
void displayGraph(struct Node* adjList[], int vertices) {
    for (int i = 0; i < vertices; i++) {
        printf("Vertex %d: ", i);
        struct Node* temp = adjList[i];
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct Node* adjList[MAX_VERTICES] = {NULL};
    int vertices, edges, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (u v) format:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adjList, u, v);
    }

    displayGraph(adjList, vertices);

    return 0;
}

/*
Enter the number of vertices: 5
Enter the number of edges: 4
Enter the edges (u v) format:
0 1
0 2
1 3
2 4
Vertex 0: 2 -> 1 -> NULL
Vertex 1: 3 -> 0 -> NULL
Vertex 2: 4 -> 0 -> NULL
Vertex 3: 1 -> NULL
Vertex 4: 2 -> NULL
*/