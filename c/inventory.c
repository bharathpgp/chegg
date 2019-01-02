#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct inventory
{
    char treeName[10];
    int qty, retail, cost, value;
} INVENTORY;

//print inventory details
void inventory(INVENTORY items[], int cnt)
{
    int i;
    printf("Inventory and Quantity\n");
    printf("----------------------\n");
    for (i = 0; i < cnt; i++)
        printf("%-15s %d\n", items[i].treeName, items[i].qty);
}

// inventory value computation
void inventory_value(INVENTORY items[], int cnt)
{
    int i;
    for (i = 0; i < cnt; i++)
        items[i].value = items[i].qty * items[i].retail;
}

void user_inventory(INVENTORY items[], int cnt)
{
    char treeName[15];
    int i;
    printf("Enter item name: ");
    scanf(" %s", treeName);
    for (i = 0; i < cnt; i++)
        if (0 == strcmp(items[i].treeName, treeName))
        {
            printf("%-15s Qty = %d, value = %d\n", items[i].treeName, items[i].qty, items[i].value);
            break;
        }
}

int main()
{
    INVENTORY items[5];
    int i = 0;
    FILE *fp = fopen("inventory.txt", "r");
    if (NULL == fp) {
        printf("File Error");
        exit(1);
    }

while (EOF != fscanf(fp, "%s %d %d %d", &items[i].treeName, &items[i].qty, &items[i].retail, &items[i].cost))
    i++;

    inventory(items, i);
    inventory_value(items, i);
    user_inventory(items, i);

    return 0;
}