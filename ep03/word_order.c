#include <stdio.h>

static const char *say(const char *word)
{
    fputs(word, stdout);
    return "";
}

int main(void)
{
    printf("%s%s\n", say("Black"), say("Jack"));
}
