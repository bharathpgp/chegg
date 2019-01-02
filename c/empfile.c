#include <stdio.h>
#include <stdlib.h>

typedef struct employee
{
    int empid;
    char name[16];
    int grade, year;
} EMPLOYEE;

void analyzeFile(char *fileName)
{
    int i, n;
    FILE *fp = fopen(fileName, "r");
    EMPLOYEE employees[20];
    char data[20];
    if (NULL == fp)
    {
        printf("Could not open input file, exiting\n");
        exit(1);
    }
    for (n = 0;; n++)
    {
        // if (fscanf(fp, "%d", &employees[i].empid))
        //     printf("%d\n", employees[i].empid);
        // else
        //     break;

        // fgets(data, 15, fp);

        // if (NULL == fgets(employees[i].name, 50, fp))
        //     break;
        // else
        //     printf("%s", employees[i].name);

        // if (fscanf(fp, "%d %d", &employees[i].grade, &employees[i].year))
        //     printf("%d %d\n", employees[i].grade, employees[i].year);
        // else
        //     break;

        // fgets(data, 15, fp);

        if (!fscanf(fp, "%d", &employees[n].empid))
            break;
        else
            printf("hai\n");

        //printf("fgets1 = %s\n", fgets(data, 5, fp));
        while ('\n' == getc(fp))
            break;

        if (NULL == fgets(employees[n].name, 15, fp))
            break;
        else
            printf("hai1\n");

        while ('\n' == getc(fp))
            break;

        if (!fscanf(fp, "%d %d", &employees[n].grade, &employees[n].year))
            break;
        else
            printf("hai2\n");

        while ('\n' == getc(fp))
            break;
    }

    printf("n = %d\n", n);

    for (i = 0; i < n; i++)
    {
        printf("%d\n", employees[i].empid);
         printf("%d %d\n", employees[i].grade, employees[i].year);
    }
}

int main()
{
    char fileName[20];
    printf("Enter file name: ");
    scanf("%s", fileName);
    analyzeFile(fileName);
    return 0;
}