#include<stdio.h>
#include<stdlib.h>
#define INFINITY 9999

struct Edge {
    int u;  // src
    int v;  // destination
    int w;  // weight
};

struct Graph {
    int V;
    int E;
    struct Edge *edge;
};

void bellman_ford(struct Graph *g, int src);
void display(int arr[], int size);

int main () {
    
    struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));

    g->E = 5;
    g->V = 4;

    g->edge = (struct Edge *)malloc(g->E*sizeof(struct Edge));

    //edge 0 --> 1
    g->edge[0].u = 0;
    g->edge[0].v = 1;
    g->edge[0].w = 5;

    //edge 0 --> 2
    g->edge[1].u = 0;
    g->edge[1].v = 2;
    g->edge[1].w = 4;

    //edge 1 --> 3
    g->edge[2].u = 1;
    g->edge[2].v = 3;
    g->edge[2].w = 3;

    //edge 2 --> 1
    g->edge[3].u = 2;
    g->edge[3].v = 1;
    g->edge[3].w = 6;

    //edge 3 --> 2
    g->edge[4].u = 3;
    g->edge[4].v = 2;
    g->edge[4].w = 2;

    bellman_ford(g,0);

}

void bellman_ford(struct Graph *g, int src) {

    int e = g->E;
    int v = g->V;

    int distance[v];

    for(int i=0;i<v;i++) {
        distance[i] = INFINITY;
    }

    distance[src] = 0;

    for(int i=1;i<=v-1;i++) {
        for(int j=0;j<e;j++) {

            int u = g->edge[j].u;
            int v = g->edge[j].v;
            int w = g->edge[j].w;

            if(distance[j]!=INFINITY && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;

            }
        }
    }

    for(int j=0;j<e;j++) {

            int u = g->edge[j].u;
            int v = g->edge[j].v;
            int w = g->edge[j].w;

            if(distance[j]!=INFINITY && distance[u] + w < distance[v]) {
                printf("Negative weight cycle detected!\n");
                return;
            }
        }

        printf("distance is %d",distance[3]);

}


