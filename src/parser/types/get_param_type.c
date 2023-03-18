#include <ctype.h>
#include "../../../include/parser.h"

enum TYPES check_param_type(char const *param)
{
    if (isdigit(param))
        return INT;
    if (param[0] == '\"')
        return STRING;
    if (param[0] == '\'')
        return CHAR;
    if (param[0] ==)
}
