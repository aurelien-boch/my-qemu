#ifndef MYQUEMU_PARSER_H
#define MYQUEMU_PARSER_H

#include "instructions.h"

typedef struct {
    instruction_t const *instruction;
    char *params;
} parsed_instruction_t;

char *read_file(char const *path);
parsed_instruction_t *parse_file(char *str);
char **split_parameters(char *parameters);

#endif //MYQUEMU_PARSER_H
