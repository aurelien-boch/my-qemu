#include <stdio.h>
#include "../../include/instructions.h"
#include "../../include/parser.h"

extern parsed_label_t *labels;

void default_behavior(cpu_t *cpu, char const **params)
{
    printf("%s\n", labels->name);

    for (int i = 0; params[i] != NULL; i++)
        printf("Param %s\n", params[i]);
}

bool default_lexer(char const *params)
{
    return true;
}
