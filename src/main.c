#include <stdio.h>
#include <stdlib.h>
#include "lib/string_utils.h"

int main() 
{
    const char *input = "   Hello, my name is Carlo. Carlo is a developer.   ";
    printf("Input: '%s'\n", input);

    char *trimmed = str_trim(input);
    printf("Trimmed: '%s'\n", trimmed);

    if (str_contains(trimmed, "Carlo"))
        printf("The substring 'Carlo' is present in the string.\n");

    int count = str_count(trimmed, "Carlo");
    printf("The substring 'Carlo' appears %d times in the string.\n", count);

    char *replaced_once = str_replace(trimmed, "Carlo", "Yami-no-karuro");
    if (replaced_once)
        printf("Replaced once: '%s'\n", replaced_once);

    char *replaced_all = str_replace_all(trimmed, "Carlo", "Yami-no-karuro");
    if (replaced_all)
        printf("Replaced all: '%s'\n", replaced_all);

    free(trimmed);
    free(replaced_once);
    free(replaced_all);

    return 0;
}
