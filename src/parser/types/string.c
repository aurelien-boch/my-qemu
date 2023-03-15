#include <malloc.h>
#include <string.h>
#include <errno.h>

char *parse_string(char const *str) {
    char *res = malloc(sizeof(char) * (strlen(str) + 1));
    if (res == NULL) {
        errno = ENOMEM;
        return NULL;
    }
    strcpy(res, str);
    return res;
}
