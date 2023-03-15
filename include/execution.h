#ifndef MYQUEMU_EXECUTION_H
#define MYQUEMU_EXECUTION_H

#include "parser.h"

void execute_instruction(cpu_t *cpu, parsed_instruction_t const *instruction);

#endif //MYQUEMU_EXECUTION_H
