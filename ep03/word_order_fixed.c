#include <stdio.h>

static const char *say(const char *word)
{
    fputs(word, stdout);
    return "";
}

int main(void)
{
    const char *first = say("Black");
    const char *second = say("Jack");
    printf("%s%s\n", first, second);
}
