#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "myfilefunctions.h"
#include "mystrfunctions.h"

static int report_result(const char *test_name, int passed)
{
    printf("%-28s %s\n", test_name, passed ? "PASS" : "FAIL");
    return passed ? 0 : 1;
}

int main(void)
{
    char copied[64];
    char partial[64];
    char joined[64] = "Operating ";
    FILE *sample_file;
    char **matches = NULL;
    int lines;
    int words;
    int chars;
    int match_count;
    int failures = 0;
    int index;

    printf("--- Testing String Functions ---\n");
    failures += report_result("mystrlen", mystrlen("Operating Systems") == 17);
    failures += report_result(
        "mystrcpy",
        mystrcpy(copied, "Linux") == 5 && strcmp(copied, "Linux") == 0
    );
    failures += report_result(
        "mystrncpy",
        mystrncpy(partial, "kernel", 3) == 3 && strcmp(partial, "ker") == 0
    );
    failures += report_result(
        "mystrcat",
        mystrcat(joined, "Systems") == 17 && strcmp(joined, "Operating Systems") == 0
    );

    printf("\n--- Testing File Functions ---\n");
    sample_file = tmpfile();
    if (sample_file == NULL) {
        perror("tmpfile");
        return EXIT_FAILURE;
    }

    fputs("Linux is useful.\nC works well on Linux.\nMake automates builds.\n", sample_file);
    rewind(sample_file);
    failures += report_result(
        "wordCount",
        wordCount(sample_file, &lines, &words, &chars) == 0
            && lines == 3
            && words == 11
            && chars == 63
    );

    rewind(sample_file);
    match_count = mygrep(sample_file, "Linux", &matches);
    failures += report_result(
        "mygrep",
        match_count == 2
            && strstr(matches[0], "Linux is useful.") != NULL
            && strstr(matches[1], "C works well on Linux.") != NULL
    );

    if (match_count > 0) {
        printf("Matched lines:\n");
        for (index = 0; index < match_count; index++) {
            printf("  %s", matches[index]);
            free(matches[index]);
        }
    }
    free(matches);
    fclose(sample_file);

    printf("\nResult: %s\n", failures == 0 ? "all tests passed" : "tests failed");
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
