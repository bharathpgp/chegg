
#include <stdio.h>
// to display given character in the place of 1 in binary and space for 0
void displayBitsAsCharacter(unsigned int value, char fillCharacter)
{
    char binary[33];
    int i, j;

    for (i = 31; i >= 0; i--) {
        j = value >> i;
        binary[31 - i] = j & 1 ? 'X' : ' ';
    }
    binary[32] = '\0';
    printf("%s\n", binary);
}

int main()
{
    unsigned int art[] = {130150655, 207820806, 207820812, 132249624, 
                            6297648, 207820896, 130150655};

    size_t nr_of_rows = sizeof(art) / sizeof(art[0]);
    size_t i;

    for (i = 0; i < nr_of_rows; i++) {
        displayBitsAsCharacter(art[i], 'X');
    }
    return 0;
}