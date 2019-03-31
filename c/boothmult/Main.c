// gcc Main.c Add.c Booth.c -o Main
#include <stdio.h>

long long int BoothMult(int multiplicand, int multiplier);

int main()
{
    int num1, num2;
    long long int res;
    printf("Enter two Numbers :\n");
    printf("NUmber-01 ? ");
    scanf("%x", &num1);
    printf("NUmber-02 ? ");
    scanf("%x", &num2);
    printf("Number-01 -> %x\nNumber-02 -> %x\n", num1, num2);
    res = BoothMult(num1, num2);
    printf("Result -> %d", res);
    return 0;
}