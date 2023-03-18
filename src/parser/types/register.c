#include <string.h>
#include "../../../include/instructions.h"

static const char *registers[] = {
    [RAX]=REGISTER_NAME(RAX),
    [RBX]=REGISTER_NAME(RBX),
    [RCX]=REGISTER_NAME(RCX),
    [RDX]=REGISTER_NAME(RDX),
    [RSI]=REGISTER_NAME(RSI),
    [RDI]=REGISTER_NAME(RDI),
    [RBP]=REGISTER_NAME(RBP),
    [RSP]=REGISTER_NAME(RSP),
    [R8]=REGISTER_NAME(R8),
    [R9]=REGISTER_NAME(R9)
};

int parse_register(char const *str) {
    for (int i = 0; i < REGISTER_NUMBER; i++)
        if (strcmp(str, registers[i]) == 0)
            return i;
    return -1;
}
