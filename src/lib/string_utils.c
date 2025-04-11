#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string_utils.h"

/**
 * Checks if a substring is contained within a string.
 *
 * @param subject - The original string to search within.
 * @param search - The substring to look for.
 * @return - 1 if the substring is found, 0 otherwise.
 */
int str_contains(const char *subject, const char *search)
{
    return strstr(subject, search) != NULL;
}

/**
 * Removes leading and trailing whitespace characters from a string.
 *
 * @param subject - The original string to trim.
 * @return - The resulting string.
 */
char *str_trim(const char *subject)
{
    const char *start = subject;
    while (*start && isspace((unsigned char)*start))
        start++;

    const char *end = subject + strlen(subject) - 1;
    while (end > start && isspace((unsigned char)*end))
        end--;

    size_t trimmed_len = end - start + 1;
    char *result = (char *)malloc(trimmed_len + 1);
    if (!result)
        return NULL;

    strncpy(result, start, trimmed_len);
    result[trimmed_len] = '\0';

    return result;
}

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

/**
 * Replaces all occurrences of a substring within a string with another substring.
 *
 * @param subject - The original string in which the replacements are performed.
 * @param search - The substring to be replaced.
 * @param replace - The substring to replace the search string.
 * @return - The resulting string with all occurrences replaced.
 */
char *str_replace_all(const char *subject, const char *search, const char *replace)
{
    char *result = str_replace(subject, search, replace);
    if (!result)
        return NULL;
    
    char *next_result;
    while ((next_result = str_replace(result, search, replace)) != NULL) {
        free(result);
        result = next_result;
    }

    return result;
}
