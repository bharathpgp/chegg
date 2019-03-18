/*
 * This C program used to determine system's byte ordering.
 */
#include <stdio.h>
int main()
{
	unsigned int integer = 0x04030201;
	char *byte = (char*) &integer;

	if (1 == byte[0] && 4 == byte[3])
		printf("Little-endian byte order");
	else
		printf("Big-endian byte order");
	return 0;
}
