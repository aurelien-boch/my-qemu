#include <stdlib.h>
#include "../../../include/instructions.h"
#include "../../../include/parser.h"

extern parsed_label_t *labels;

void add(cpu_t *cpu, char const **params)
{
    long param1 = strtol(params[0], NULL, 10);
    long param2 = strtol(params[1], NULL, 10);
}

void add_lexer(char const *params)
{

}
