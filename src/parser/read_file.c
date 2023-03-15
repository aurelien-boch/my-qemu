#include <stdio.h>
#include <stdlib.h>

char *read_file(char const *path) {
    FILE *file = fopen(path, "r");
    char *content = NULL;
    long length = 0;

    if (file == NULL)
        return NULL;
    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);
    content = calloc(length + 1, sizeof(char));
    fread(content, 1, length, file);
    fclose(file);
    return content;
}
