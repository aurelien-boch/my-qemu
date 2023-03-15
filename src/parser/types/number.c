#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int parse_int_decimal(char const *str) {
    char *end_pointer = NULL;
    long res = strtol(str, &end_pointer, 10);

    if (end_pointer == str || res > INT_MAX || res < INT_MIN) {
        errno = EINVAL;
        return 0;
    }
    return res;
}

int parse_int_hex(char const *str) {
    char *end_pointer = NULL;
    long res = strtol(str, &end_pointer, 16);

    if (end_pointer == str || res > INT_MAX || res < INT_MIN) {
        errno = EINVAL;
        return 0;
    }
    return res;
}

int parse_int_octal(char const *str) {
    char *end_pointer = NULL;
    long res = strtol(str, &end_pointer, 8);

    if (end_pointer == str || res > INT_MAX || res < INT_MIN) {
        errno = EINVAL;
        return 0;
    }
    return res;
}

int parse_int_binary(char const *str) {
    char *end_pointer = NULL;
    long res = strtol(str, &end_pointer, 2);

    if (end_pointer == str || res > INT_MAX || res < INT_MIN) {
        errno = EINVAL;
        return 0;
    }
    return res;
}

float parse_float_decimal(char const *str) {
    char *end_pointer = NULL;
    float res = strtof(str, &end_pointer);

    if (end_pointer == str) {
        errno = EINVAL;
        return 0;
    }
    return res;
}
