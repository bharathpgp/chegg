
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// state data structure
typedef struct State
{
    char name[25];
    char capital[25];
    float latitude, longtitude;
} State;

// open file containing state details and compare with user input
void searchState(const char *name, const char *capital)
{
    FILE *file = fopen("data.txt", "r");
    State state;

    if (NULL == file)
    {
        printf("File can't be open!!!\n");
        exit(1);
    }

    while (fread(&state, sizeof(State), 1, file))
    {
        if (0 == strcmp(state.name, name) && (0 == strcmp(state.capital, capital)))
        {
            printf("%s and %s are found and their longitude [%f], latitude [%f]\n", name, capital, state.longtitude, state.latitude);
            break;
        }
    }

    printf("%s/%s was not found\n", name, capital);
}

// to get user inputs to compare the state data present in a file
int main()
{
    char choice, name[25], capital[25];
    do
    {
        printf("Enter the State name: ");
        scanf(" %[^\n]s", name);
        printf("Enter the Capital name: ");
        scanf(" %[^\n]s", capital);
        searchState(name, capital);
        printf("Would like to find another state(Y for Yes and N for No): ");
        scanf(" %c", &choice);

    } while ('Y' == choice);

    printf("Thank You for using the program!!!\n");
    return 0;
}










