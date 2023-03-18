#ifndef MYQUEMU_PARSER_H
#define MYQUEMU_PARSER_H

#include "instructions.h"

typedef struct {
    instruction_t const *instruction;
    char *params;
} parsed_instruction_t;

// 12
typedef struct {
    char *name;
    int address;
} parsed_label_t;

// 16
typedef struct {
    parsed_instruction_t *instructions;
    parsed_label_t *labels;
} parsed_file_t;

char *read_file(char const *path);
parsed_file_t parse_file(char *str);
char **split_parameters(char *parameters);
bool verify_instructions(parsed_instruction_t const *instructions);

#endif //MYQUEMU_PARSER_H
