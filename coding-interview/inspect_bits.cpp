/*
Implement the inspect_bits function that checks if given number contains 2 or more consecutive ones in its binary representation. If it does, the function should return 1. Otherwise, it should return 0.
For example, inspect_bits(13) should return 1 as it contains 2 consecutive ones in its binary representation (1101).
*/
#include <stdlib.h>
#include <stdio.h>

const unsigned int c_mask = 3;

int inspect_bits(unsigned int number) {
    while (2 < number) {
        if (3 == (number & c_mask))
                return 1;
        number >>= 1;
    }
    return 0;
}

#ifndef RunTests
int main ()
{
    printf("%d", inspect_bits(13));
}
#endif