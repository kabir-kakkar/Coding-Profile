#include <stdio.h>
#include <stdlib.h>

struct AdjListNode
{
  int dest;
  struct AdjListNode *next;
};

struct AdjList
{
  struct AdjListNode *head;
};

struct Graph
{
  int v; // v  is the number of edges
  struct AdjList *array;
};

struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph (int v)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->v = v;
    graph->array = (struct AdjList*)malloc(v* sizeof(struct AdjList));
    int i;
    for (i = 0; i < v; i++)
    {
        graph->array[i].head = NULL;
    }
    return graph;
};

void addEdge (struct Graph* graph, int src, int dest)
{
    struct AdjListNode* newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;

    newNode = newAdjListNode (dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

void printGraph (struct Graph *graph)
{
    int v, arr[10], i, j;
    for (v = 0; v < graph->v; v++)
    {
        i = 0;
        struct AdjListNode* crawl = graph->array[v].head;
        printf ("%d", v);
        while(crawl)
        {
            arr[i++] = crawl->dest;
            crawl = crawl -> next;
        }
        --i;
        for (j = i; j >= 0; j--)
        {
            printf("-> %d", arr[j]);
        }
        printf ("\n");
    }
}

int main()
{
    int noOfTestCases, v, e, i, src, dest;

    scanf ("%d", &noOfTestCases);

   while (noOfTestCases != 0)
   {
        scanf ("%d", &v);
        scanf ("%d", &e);

        struct Graph* graph = createGraph(v);

        for (i = 0; i < e; i++)
        {
            scanf ("%d", &src);
            scanf ("%d", &dest);

            addEdge (graph, src, dest);
        }

        printGraph(graph);

        noOfTestCases--;
   }

	return 0;
}
