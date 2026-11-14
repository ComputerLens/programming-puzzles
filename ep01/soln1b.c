#include <stdio.h>

#define x (2 | 0)

int main(void)
{
    if (x == x + 1)
        printf("TRUE\n");
    else
        printf("FALSE\n");

    return 0;
}
