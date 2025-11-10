#include <stdio.h>
#define INF 9999
#define V 5

void dijkstra(int G[V][V], int start) {
    int cost[V][V], distance[V], pred[V];
    int visited[V], count, mindistance, nextnode, i, j;

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            cost[i][j] = (G[i][j] == 0) ? INF : G[i][j];

    for (i = 0; i < V; i++) {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    while (count < V - 1) {
        mindistance = INF;
        for (i = 0; i < V; i++)
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }

        visited[nextnode] = 1;
        for (i = 0; i < V; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }

    for (i = 0; i < V; i++)
        if (i != start)
            printf("\nDistance from %d -> %d = %d", start, i, distance[i]);
}

int main() {
    int G[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };
    dijkstra(G, 0);
    return 0;
}
