#ifndef MYFILEFUNCTIONS_H
#define MYFILEFUNCTIONS_H

#include <stdio.h>

/* Count the lines, words, and characters in file. */
int wordCount(FILE *file, int *lines, int *words, int *chars);

/* Store copies of lines containing search_str in matches. */
int mygrep(FILE *fp, const char *search_str, char ***matches);

#endif

