#include <stdio.h>
#include "../../include/instructions.h"

void default_behavior(cpu_t *cpu, char const **params)
{
    printf("Get the satellite if you wanna see me\n");

    for (int i = 0; params[i] != NULL; i++)
        printf("Param %s\n", params[i]);
}

bool default_lexer(char const *params)
{
    return true;
}
