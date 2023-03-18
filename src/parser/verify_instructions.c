#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include "../../include/parser.h"

bool verify_instructions(parsed_instruction_t const *instructions) {
    for (int i = 0; instructions[i].params != NULL; i++) {
        if (!instructions[i].instruction->lexer(instructions[i].params)) {
            fprintf(
                stderr,
                "Error: Invalid parameters (%s) for instruction %s (parser.c)\n",
                instructions[i].params,
                instructions[i].instruction->name
            );
            return false;
        }
    }
    return true;
}
