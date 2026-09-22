#include "myfilefunctions.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int wordCount(FILE *file, int *lines, int *words, int *chars)
{
    int character;
    int inside_word = 0;

    if (file == NULL || lines == NULL || words == NULL || chars == NULL) {
        return -1;
    }

    *lines = 0;
    *words = 0;
    *chars = 0;

    while ((character = fgetc(file)) != EOF) {
        (*chars)++;

        if (character == '\n') {
            (*lines)++;
        }

        if (isspace((unsigned char)character)) {
            inside_word = 0;
        } else if (!inside_word) {
            (*words)++;
            inside_word = 1;
        }
    }

    return ferror(file) ? -1 : 0;
}

int mygrep(FILE *fp, const char *search_str, char ***matches)
{
    char *line = NULL;
    size_t capacity = 0;
    ssize_t length;
    int count = 0;

    if (fp == NULL || search_str == NULL || matches == NULL) {
        return -1;
    }

    *matches = NULL;

    while ((length = getline(&line, &capacity, fp)) != -1) {
        char **expanded;

        (void)length;
        if (strstr(line, search_str) == NULL) {
            continue;
        }

        expanded = realloc(*matches, (size_t)(count + 1) * sizeof(**matches));
        if (expanded == NULL) {
            int index;

            for (index = 0; index < count; index++) {
                free((*matches)[index]);
            }
            free(*matches);
            free(line);
            *matches = NULL;
            return -1;
        }

        *matches = expanded;
        (*matches)[count] = strdup(line);
        if ((*matches)[count] == NULL) {
            int index;

            for (index = 0; index < count; index++) {
                free((*matches)[index]);
            }
            free(*matches);
            free(line);
            *matches = NULL;
            return -1;
        }
        count++;
    }

    free(line);
    return ferror(fp) ? -1 : count;
}

