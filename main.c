#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/parser.h"

int main(int ac, char **av) {
    parsed_instruction_t *instructions = NULL;
    cpu_t *cpu = NULL;
    char *content = NULL;

    if (ac < 2) {
        fprintf(stderr, "Usage: %s <file>\n", av[0]);
        return 1;
    }
    content = read_file(av[1]);

    if (content == NULL) {
        fprintf(stderr, "Error: Could not read file (main.c)\n");
        return 1;
    }
    instructions = parse_file(content);

    for (int i = 0; instructions[i].instruction != NULL; i++) {
        char **parameters = split_parameters(instructions[i].params);
        instructions[i].instruction->func(cpu, (const char **)parameters);
        free(parameters);
    }
    free(instructions);
    free(content);
    return 0;
}