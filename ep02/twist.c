#include <stdio.h>
#include <math.h>
int main()
{
    double x = NAN;
    printf("x == x     : %d\n", x == x);
    printf("x == x + 1 : %d\n", x == x + 1);
    return 0;
}
