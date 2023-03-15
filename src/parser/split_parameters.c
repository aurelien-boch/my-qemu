#include <stdlib.h>
#include <string.h>

#define PARAMETERS_DELIMITER_AS_CHAR ','
#define PARAMETERS_DELIMITER_AS_STRING ","

static int count_delimiters(char const *str) {
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == PARAMETERS_DELIMITER_AS_CHAR)
            count++;
    return count;
}

char **split_parameters(char *parameters) {
    const int parameters_count = count_delimiters(parameters) + 1;
    char **res = calloc(parameters_count + 1, sizeof(char *));

    for (int i = 0; i < parameters_count; i++) {
        res[i] = strtok(parameters, PARAMETERS_DELIMITER_AS_STRING);
        parameters = NULL;
    }
    return res;
}
