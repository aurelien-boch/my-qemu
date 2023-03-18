#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "../../include/instructions.h"
#include "../../include/instructions_table.h"
#include "../../include/parser.h"

#define INSTRUCTION_DELIMITER "\n"
#define INSTRUCTION_PARAM_DELIMITER " "
#define LABEL_MARKER_CHAR ':'
#define LABEL_MARKER_STRING ":"

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

static int count_number_of_labels(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == LABEL_MARKER_CHAR)
            count++;
    return count;
}

static int count_number_of_instructions(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n' && str[i - 1] != LABEL_MARKER_CHAR)
            count++;
    return count;
}

static int get_line_length(char const *str)
{
    int i = 0;

    while (str[i] != '\0' && str[i] != '\n')
        i++;
    return i;
}

parsed_file_t parse_file(char *str)
{
    int number_of_instructions = count_number_of_instructions(str);
    int number_of_labels = count_number_of_labels(str);
    char *instructions_copy = str;

    parsed_file_t result = {
        .instructions = calloc(number_of_instructions + 1, sizeof(parsed_instruction_t)),
        .labels = calloc(number_of_labels + 1, sizeof(parsed_label_t))
    };

    for (int i = 0; *instructions_copy != '\0'; instructions_copy += get_line_length(instructions_copy) + 1) {
        if (instructions_copy[get_line_length(instructions_copy) - 1] == LABEL_MARKER_CHAR)
            continue;
        char *instruction_name = NULL;
        char *instruction_params = NULL;
        instruction_t const *instruction = NULL;
        sscanf(instructions_copy, "%ms" INSTRUCTION_PARAM_DELIMITER "%ms", &instruction_name, &instruction_params);
        instruction = get_instruction_from_name(instruction_name);
        if (instruction == NULL) {
            free(instruction_name);
            free(instruction_params);
            errno = EINVAL;
            return result;
        }
        result.instructions[i].instruction = instruction;
        result.instructions[i++].params = instruction_params;
        free(instruction_name);
        instruction_name = NULL;
    }
    for (int instruction_index = 0, label_index = 0; *str != '\0'; str += get_line_length(str) + 1) {
        if (str[get_line_length(str) - 1] == LABEL_MARKER_CHAR) {
            char *label_name = NULL;

            sscanf(str, "%ms" LABEL_MARKER_STRING, &label_name);
            label_name[strlen(label_name) - 1] = '\0';
            result.labels[label_index].name = label_name;
            result.labels[label_index++].address = instruction_index - 1;
        } else
            instruction_index++;
    }
    return result;
}
