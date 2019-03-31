int Add(int x, int y);

long long int BoothMult(int multiplicand, int multiplier)
{
    int res = 0;

    while (multiplier > 0)
    {
        if (multiplier & 1)
            res = Add(res, multiplicand);

        multiplicand = multiplicand << 1;
        multiplier = multiplier >> 1;
    }
    return res;
}