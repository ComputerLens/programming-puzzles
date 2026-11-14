#include <stdio.h>

int main(void)
{
    struct Empty {} items[2], *x = items;

    if (x == x + 1)
        printf("TRUE\n");
    else
        printf("FALSE\n");

    return 0;
}
