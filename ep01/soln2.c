#include <stdio.h>

int main(void)
{
    double x = 1e100;

    if (x == x + 1)
        printf("TRUE\n");
    else
        printf("FALSE\n");

    return 0;
}
