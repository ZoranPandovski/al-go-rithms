#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge
{
    int startVertex;
    int endVertex;
    int weight;
};

struct Graph
{
    int totalVertex;
    int totalEdges;
    struct Edge *edge;
};

/** Function Prototypes. **/
void bellmanford(struct Graph *graph, int source);
void display(int arr[], int size);

int main(void)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->totalVertex = 5;
    graph->totalEdges = 7;

    graph->edge = (struct Edge *)malloc(graph->totalEdges * sizeof(struct Edge));

    graph->edge[0].startVertex = 0;
    graph->edge[0].endVertex = 1;
    graph->edge[0].weight = 6;

    //edge from 0 to 2
    graph->edge[1].startVertex = 0;
    graph->edge[1].endVertex = 2;
    graph->edge[1].weight = 5;

    //edge from 1 to 3
    graph->edge[2].startVertex = 1;
    graph->edge[2].endVertex = 3;
    graph->edge[2].weight = -1;

    //edge from 2 to 1
    graph->edge[3].startVertex = 2;
    graph->edge[3].endVertex = 1;
    graph->edge[3].weight = -2;

    //edge from 2 to 4
    graph->edge[4].startVertex = 2;
    graph->edge[4].endVertex = 4;
    graph->edge[4].weight = 3;

    //edge from 2 to 3
    graph->edge[5].startVertex = 2;
    graph->edge[5].endVertex = 3;
    graph->edge[5].weight = 4;

    //edge from 3 to 4
    graph->edge[6].startVertex = 3;
    graph->edge[6].endVertex = 4;
    graph->edge[6].weight = 3;

    // starting node is 0
    bellmanford(graph, 0);

    return 0;
}

void bellmanford(struct Graph *graph, int source)
{
    int i, j, startVertex, endVertex, weight;
    int TotalVertices = graph->totalVertex;
    int TotalEdges = graph->totalEdges;
    int distance[TotalVertices];
    int PredecessorArray[TotalVertices];

    for (i = 0; i < TotalVertices; i++)
    {
        distance[i] = INT_MAX;
        PredecessorArray[i] = 0;
    }

    distance[source] = 0;
    for (i = 1; i <= TotalVertices - 1; i++)
    {
        for (j = 0; j < TotalEdges; j++)
        {
            //get the edge data
            startVertex = graph->edge[j].startVertex;
            endVertex = graph->edge[j].endVertex;
            weight = graph->edge[j].weight;

            if (distance[startVertex] != INT_MAX && distance[endVertex] > distance[startVertex] + weight)
            {
                distance[endVertex] = distance[startVertex] + weight;
                PredecessorArray[endVertex] = startVertex;
            }
        }
    }

    for (i = 0; i < TotalEdges; i++)
    {
        startVertex = graph->edge[i].startVertex;
        endVertex = graph->edge[i].endVertex;
        weight = graph->edge[i].weight;
        if (distance[startVertex] != INT_MAX && distance[endVertex] > distance[startVertex] + weight)
        {
            printf("Negative weight cycle detected!\n");
            return;
        }
    }

    printf("Distance array: ");
    display(distance, TotalVertices);
}

void display(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
