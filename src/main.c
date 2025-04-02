#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Replaces the first occurrence of a substring within a string with another substring.
 *
 * @param subject - The original string in which the replacement is performed.
 * @param search - The substring to be replaced.
 * @param replace - The substring to replace the search string.
 * @return - The resulting string. 
 */
char *str_replace(const char *subject, const char *search, const char *replace)
{
    char *offset = strstr(subject, search);
    if (offset == NULL)
        return NULL;

    int offset_index = offset - subject;
    int search_length = strlen(search);
    int replace_length = strlen(replace);
    int result_length = strlen(subject) - search_length + replace_length;

    char *result = (char *)malloc((result_length + 1) * sizeof(char));
    if (!result)
        return NULL;

    strncpy(result, subject, offset_index);
    strcpy(result + offset_index, replace);
    strcpy(result + offset_index + replace_length, subject + offset_index + search_length);

    return result;
}

int main() 
{
    char *input = "Hello, my name is Carletto and i'm a software developer!";
    char *output = str_replace(input, "Carletto", "Yami-no-karuro");

    printf("Input: %s\n", input);
    printf("Output: %s\n", output);
    free(output);

    return 0;
}
