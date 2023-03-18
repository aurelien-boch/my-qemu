#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/parser.h"
#include "include/execution.h"

parsed_label_t *labels = NULL;

static void free_all(parsed_file_t result, char *content)
{
    for (int i = 0; result.instructions[i].instruction != NULL; i++)
        free(result.instructions[i].params);
    free(result.instructions);
    for (int i = 0; result.labels[i].name != NULL; i++)
        free(result.labels[i].name);
    free(result.labels);
    free(content);
}

int main(int ac, char **av) {
    parsed_file_t result;
    cpu_t cpu = {
        .registers = {0},
        .instruction_pointer = 0,
        .flags = 0,
        .cycles = 0
    };
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
    result = parse_file(content);
    if (errno != 0)
        free_all(result, content);
    if (!verify_instructions(result.instructions))
        free_all(result, content);
    labels = result.labels;
    for (; result.instructions[cpu.instruction_pointer].instruction != NULL; cpu.instruction_pointer++)
        execute_instruction(&cpu, &(result.instructions[cpu.instruction_pointer]));
    free_all(result, content);
    return 0;
}
