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

void getAndPrintVertices(char **vertices, int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        vertices[i] = (char *)malloc(20 * sizeof(char));
        fscanf(stdin, "%s", vertices[i]);
        printf("%d-%s\n", i, vertices[i]);
    }
}

unsigned int findIndexByName(const char *name, char **vertices, int N)
{
    int i;
    printf("name = %s ", name);
    for (i = 0; i < N; i++)
        if (0 == strcmp(name, vertices[i]))
        {
            printf("%d\n", i);
            return i;
        }
}

void getAndMapEdges(char **vertices, int N)
{
    int matrix[10][10], i, j, x, y;
    char name1[20], name2[20];

    while (EOF != fscanf(stdin, "%s %s", &name1, &name2))
    {
        printf("%s %s", name1, name2);
        if (0 != strcmp(name1, "-1") && 0 != strcmp(name2, "-1"))
        {
            x = findIndexByName(name1, vertices, N);
            y = findIndexByName(name2, vertices, N);

            matrix[x][y] = 1;
        }
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, int *argv[])
{
    char ch;
    int N;
    char **vertices;
    fscanf(stdin, "%d", &N);
    printf("N = %d\n", N);
    vertices = (char *)malloc(sizeof(N));
    if (NULL == vertices)
    {
        exit(1);
    }
    getAndPrintVertices(vertices, N);
    getAndMapEdges(vertices, N);
    return 0;
}