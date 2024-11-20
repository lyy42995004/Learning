#include <stdio.h>

#define SWAP_ODD_EVEN(x) ((((x) & 0x55555555) << 1) | (((x) & 0xaaaaaaaa) >> 1))

int main()
{
    printf("%d\n", SWAP_ODD_EVEN(1));
    return 0;
}