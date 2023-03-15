#include <stdlib.h>
#include "../../include/parser.h"

void execute_instruction(cpu_t *cpu, parsed_instruction_t const *instruction)
{
    char **parameters = split_parameters(instruction->params);

    instruction->instruction->func(cpu, (const char **)parameters);
    free(parameters);
}
