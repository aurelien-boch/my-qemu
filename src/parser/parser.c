#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../include/instructions.h"
#include "../../include/instructions_table.h"
#include "../../include/parser.h"

#define INSTRUCTION_DELIMITER "\n"
#define INSTRUCTION_PARAM_DELIMITER " "

static instruction_t const *get_instruction_from_name(char *name) {
    for (unsigned long i = 0; i < sizeof(instructions) / sizeof(instructions[0]); i++)
        if (strcmp(instructions[i].name, name) == 0)
            return &(instructions[i]);
    return NULL;
}

/*static instruction_t const *get_instruction_from_opcode(int opcode) {
    for (unsigned long i = 0; i < sizeof(instructions) / sizeof(instructions[0]); i++)
        if (instructions[i].opcode == opcode)
            return &(instructions[i]);
    return NULL;
}*/

static int count_number_of_instructions(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            count++;
    return count;
}

parsed_instruction_t *parse_file(char *str)
{
    int number_of_instructions = count_number_of_instructions(str);
    parsed_instruction_t *parsed_instructions = calloc(number_of_instructions + 1, sizeof(parsed_instruction_t));

    for (int i = 0; i < number_of_instructions; i++) {
        char *instruction_line = strtok(str, INSTRUCTION_DELIMITER);
        char *instruction_name = NULL;
        char *instruction_params = NULL;
        instruction_t const *instruction = NULL;
        sscanf(instruction_line, "%ms" INSTRUCTION_PARAM_DELIMITER "%ms", &instruction_name, &instruction_params);

        instruction = get_instruction_from_name(instruction_name);
        parsed_instructions[i].instruction = instruction;
        parsed_instructions[i].params = instruction_params;
        if (!instruction->lexer(instruction_params)) {
            fprintf(stderr, "Error: Invalid parameters (%s) for instruction %s (parser.c)\n", instruction_params, instruction_name);
            free(instruction_name);
            free(parsed_instructions);
            return NULL;
        }
        free(instruction_name);
        str = NULL;
    }
    return parsed_instructions;
}
