# C - String Utils

## A small set of string manipulation tools

### - str_contains()

Scans the given subject string to determine whether the specified search string is present within it.

```c
/**
 * Scans the given subject string to determine whether the specified search string is present within it.
 *
 * @param subject - The original string to search within.
 * @param search - The substring to look for.
 * @return - 1 if the substring is found, 0 otherwise.
 */
int str_contains(const char *subject, const char *search);
```

### - str_count()

Counts the number of non-overlapping occurrences of a substring within a string.

```c
/**
 * Counts the number of non-overlapping occurrences of a substring within a string.
 *
 * @param subject - The original string to search within.
 * @param search - The substring to look for.
 * @return - The number of times the substring appears in the subject string.
 */
int str_count(const char *subject, const char *search);
```

### - str_split()

Splits a string into tokens based on a specified delimiter.
The caller is responsible for freeing the returned array.

```c
/**
 * Splits a string into tokens based on a specified delimiter.
 *
 * @param subject - The original string to split.
 * @param delimiter - The character used as the delimiter to split the string.
 * @return - A NULL-terminated array of strings (tokens).
 */
char **str_split(const char *subject, char delimiter);

// ====
// The caller is responsible for freeing the returned array.
// Here's an example of a dedicated free function implementation.
// ====
void str_split_free(char **tokens)
{
    for (char **p = tokens; *p; p++)
        free(*p);

    free(tokens);
}
```

### - str_join()

Joins an array of strings into a single string using the specified delimiter.

```c
/**
 * Joins an array of strings into a single string using the specified delimiter.
 *
 * @param strings - A NULL-terminated array of strings to join.
 * @param delimiter - The string to insert between each pair of strings.
 * @return - A newly allocated string containing the joined result.
 */
char *str_join(char **strings, const char *delimiter)
```

### - str_trim()

Removes leading and trailing whitespace characters from a string.
The caller is responsible for freeing the returned string.

```c
/**
 * Removes leading and trailing whitespace characters from a string.
 *
 * @param subject - The original string to trim.
 * @return - The resulting string.
 */
char *str_trim(const char *subject);
```

### - str_replace()

Replaces the first occurrence of a substring within a string with another substring.
If the 'search' substring is not found, NULL is returned.
The caller is responsible for freeing the returned string.

```c
/**
 * Replaces the first occurrence of a substring within a string with another substring.
 *
 * @param subject - The original string in which the replacement is performed.
 * @param search - The substring to be replaced.
 * @param replace - The substring to replace the search string.
 * @return - The resulting string.
 */
char *str_replace(const char *subject, const char *search, const char *replace);
```

### - str_replace_all()

Replaces all occurrences of a substring within a string with another substring.
The caller is responsible for freeing the returned string.

```c
/**
 * Replaces all occurrences of a substring within a string with another substring.
 *
 * @param subject - The original string in which the replacements are performed.
 * @param search - The substring to be replaced.
 * @param replace - The substring to replace the search string.
 * @return - The resulting string with all occurrences replaced.
 */
char *str_replace_all(const char *subject, const char *search, const char *replace);
```
