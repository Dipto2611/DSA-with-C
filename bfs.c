#include <stdio.h>

int main() {
    int graph[4][4] = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };

    int visited[4] = {0}; // Initialize all nodes as not visited
    int queue[4];
    int front = 0, rear = -1;

    // Enqueue the starting node (0)
    queue[++rear] = 0;
    visited[0] = 1;

    while (front <= rear) {
        int current_node = queue[front++];

        printf("%d ", current_node);

        for (int i = 0; i < 4; i++) {
            if (graph[current_node][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }

    return 0;
}

/*Here’s the BFS algorithm broken into 7 points:

1. **Initialize Data Structures**:
   - Create a `visited[]` array to track visited nodes, initialized to 0.
   - Create a `queue[]` for BFS traversal.
   - Set `front = 0` and `rear = -1` for queue management.

2. **Enqueue the Starting Node**:
   - Enqueue the starting node (0) and mark it as visited (`visited[0] = 1`).

3. **While Queue is Not Empty**:
   - Check if `front <= rear` to continue the BFS loop.

4. **Dequeue a Node**:
   - Dequeue the front node from the queue and assign it to `current_node`.

5. **Print the Current Node**:
   - Print the `current_node` (the node that was dequeued).

6. **Explore Adjacent Nodes**:
   - For each node `i`, if it is adjacent (`graph[current_node][i] == 1`) and not visited, enqueue it and mark it as visited.

7. **End the BFS**:
   - Repeat steps 4 to 6 until all reachable nodes are visited.*/