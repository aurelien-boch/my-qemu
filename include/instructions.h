#ifndef MYQUEMU_TABLE_H
#define MYQUEMU_TABLE_H

#include <stdbool.h>

//flags
#define CARRY_FLAG 0x0001
#define ZERO_FLAG 0x0040
#define OVERFLOW_FLAG 0x0800

#define SET_FLAG(cpu, flag) (cpu->flags |= flag)
#define TOGGLE_FLAG(cpu, flag) (cpu->flags ^= flag)

//registers
#define REGISTER_NUMBER 10

#define RAX 0
#define RBX 1
#define RCX 2
#define RDX 3
#define RSI 4
#define RDI 5
#define RBP 6
#define RSP 7
#define R8 8
#define R9 9

#define REGISTER_NAME(register) #register

typedef struct {
    char registers[REGISTER_NUMBER];
    int instruction_pointer;
    int flags;
    int cycles;
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
