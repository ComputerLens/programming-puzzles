#include <stdio.h>

static int score = 10;

static int reset(void) { return score = 3; }
static int double_score(void) { return score *= 2; }

int main(void)
{
    printf("%d\n", reset() + double_score());
}
