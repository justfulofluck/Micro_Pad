// For library and functionality testing

// test

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int bit = 0x00000101;
    bit |= (1<<5);
    printf("%x\n", bit);

    return 0;
}

// 00000000
// 00100000
// 0020,0000
//    2,0=20 