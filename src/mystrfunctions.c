#include "mystrfunctions.h"

#include <stddef.h>

int mystrlen(const char *s)
{
    int length = 0;

    if (s == NULL) {
        return -1;
    }

    while (s[length] != '\0') {
        length++;
    }

    return length;
}

int mystrcpy(char *dest, const char *src)
{
    int index = 0;

    if (dest == NULL || src == NULL) {
        return -1;
    }

    while (src[index] != '\0') {
        dest[index] = src[index];
        index++;
    }
    dest[index] = '\0';

    return index;
}

int mystrncpy(char *dest, const char *src, int n)
{
    int index = 0;

    if (dest == NULL || src == NULL || n < 0) {
        return -1;
    }

    while (index < n && src[index] != '\0') {
        dest[index] = src[index];
        index++;
    }
    dest[index] = '\0';

    return index;
}

int mystrcat(char *dest, const char *src)
{
    int dest_length;
    int index = 0;

    if (dest == NULL || src == NULL) {
        return -1;
    }

    dest_length = mystrlen(dest);
    while (src[index] != '\0') {
        dest[dest_length + index] = src[index];
        index++;
    }
    dest[dest_length + index] = '\0';

    return dest_length + index;
}
