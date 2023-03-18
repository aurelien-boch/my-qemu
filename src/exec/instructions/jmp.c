#include <string.h>
#include "../../../include/instructions.h"
#include "../../../include/parser.h"

extern parsed_label_t *labels;

void jmp(cpu_t *cpu, char const **params)
{
    for (int i = 0; labels[i].name != NULL; i++) {
        if (strcmp(labels[i].name, params[0]) == 0) {
            cpu->instruction_pointer = labels[i].address;
            break;
        }
    }
}

bool jmp_lexer(char const *params)
{
    for (int i = 0; labels[i].name != NULL; i++) {
        if (strcmp(labels[i].name, params) == 0)
            return true;
    }
    return strlen(params) > 0;
}
