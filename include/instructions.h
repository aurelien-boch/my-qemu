#ifndef MYQUEMU_TABLE_H
#define MYQUEMU_TABLE_H

#include <stdbool.h>

typedef struct {
    char registers[10];
} cpu_t;

typedef void (instruction_impl_t)(cpu_t *, char const **params);

typedef struct {
    /*
     * This is the name of the instruction.
     */
    char *name;

    /*
     * This is the opcode of the instruction.
     */
    int opcode;

    /*
     * This is the number of cycles that the instruction takes to execute.
     */
    int cycles;

    /*
     * This function is used to execute the instruction.
     */
    instruction_impl_t *func;

    /*
     * This function is used to parse the parameters of the instruction and ensure that they are valid.
     */
    bool (*lexer)(char const *);
} instruction_t;

#endif //MYQUEMU_TABLE_H
