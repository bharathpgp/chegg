#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    unsigned int first;
    unsigned int second;
} edge;

void connected_components_recursive(const edge *edges, unsigned int n,
                                    int *components, unsigned int order, unsigned int vertex,
                                    unsigned int component)
{
    unsigned int i;
    /* Put this vertex in the current component */
    components[vertex] = component;
    for (i = 0; i < n; i++)
    {
        if (edges[i].first == vertex || edges[i].second == vertex)
        {
            /* Adjacent */
            const unsigned int neighbour = edges[i].first == vertex ? edges[i].second : edges[i].first;
            if (components[neighbour] == -1)
            {
                /* Not yet visited */
                connected_components_recursive(edges, n, components, order, neighbour, component);
            }
        }
    }
}

unsigned int connected_components(const edge *edges, unsigned int n, unsigned int order,
                                  int **components)
{
    unsigned int i;
    unsigned int component = 0;
    *components = malloc(order * sizeof(int));
    if (components == NULL)
    {
        return 0;
    }
    for (i = 0; i < order; i++)
    {
        (*components)[i] = -1;
    }

    for (i = 0; i < order; i++)
    {
        if ((*components)[i] == -1)
        {
            connected_components_recursive(edges, n, *components, order, i, component);
            component++;
        }
    }
    return component;
}

static void print_components(int *components, unsigned int order)
{
    unsigned int i;
    for (i = 0; i < order; i++)
    {
        printf("Vertex %u is in component %d\n", i, components[i]);
    }
}

int main(void)
{
    const unsigned int order = 9; /* Vertices */
    const unsigned int n = 8;     /* Edges */
    edge *edges;
    int *components;
    unsigned int c;

    edges = malloc(n * sizeof(edge));
    if (edges == NULL)
    {
        return 1;
    }

    /* Square */
    edges[0].first = 0;
    edges[0].second = 1;
    edges[1].first = 1;
    edges[1].second = 2;
    edges[2].first = 2;
    edges[2].second = 3;
    edges[3].first = 3;
    edges[3].second = 0;

    /* Triangle */
    edges[4].first = 4;
    edges[4].second = 5;
    edges[5].first = 5;
    edges[5].second = 6;
    edges[6].first = 6;
    edges[6].second = 4;

    /* Line */
    edges[7].first = 7;
    edges[7].second = 8;

    c = connected_components(edges, n, order, &components);
    if (components == NULL)
    {
        free(edges);
        return 1;
    }
    printf("There are %u components:\n", c);
    print_components(components, order);
    free(edges);
    free(components);

    return 0;
}