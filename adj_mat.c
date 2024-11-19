#include <stdio.h>

#define MAX 10

void main() {
    int i, j, k, c, ver;
    int adj[MAX][MAX] = {0};

    printf("Enter the number of vertices: ");
    scanf("%d", &ver);

    printf("Enter the number of connections: ");
    scanf("%d", &c);

    for (k = 0; k < c; k++) {
        printf("Enter source and destination vertex: ");
        scanf("%d %d", &i, &j);

        adj[i - 1][j - 1] = 1;
        adj[j - 1][i - 1] = 1;
    }

    printf("The Adjacency Matrix is: \n");
    for (i = 0; i < ver; i++) {
        for (j = 0; j < ver; j++) {
            printf("%d\t", adj[i][j]);
        }
        printf("\n");
    }
}

/*
Enter the number of vertices: 4
Enter the number of connections: 3
Enter source and destination vertex: 1 2
Enter source and destination vertex: 2 3
Enter source and destination vertex: 3 4
The Adjacency Matrix is: 
0	1	0	0	
1	0	1	0	
0	1	0	1	
0	0	1	0	
*/