#include <stdio.h>

static int score = 10;

static int reset(void) { return score = 3; }
static int double_score(void) { return score *= 2; }
static int add(int a, int b) { return a + b; }

int main(void)
{
    printf("%d\n", add(reset(), double_score()));
}
