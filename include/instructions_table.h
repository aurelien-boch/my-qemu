#ifndef MYQUEMU_INSTRUCTIONS_TABLE_H
#define MYQUEMU_INSTRUCTIONS_TABLE_H

#include "instructions.h"

void default_behavior(cpu_t *cpu, char const **params);
bool default_lexer(char const *params);

static const instruction_t instructions[] = {
    {
        .name = "ADD",
        .opcode = 0x01,
        .cycles = 2,
        .func = &default_behavior,
        .lexer = &default_lexer
    },
    {
        .name = "MOV",
        .opcode = 0x02,
        .cycles = 2,
        .func = &default_behavior,
        .lexer = &default_lexer
    },
};

#endif //MYQUEMU_INSTRUCTIONS_TABLE_H
