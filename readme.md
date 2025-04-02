# C - String Utils

## A set of string manipulation tools for C

### API

```c
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
```

```c
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
```

```c
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
```
