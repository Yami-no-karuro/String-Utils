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

Counts the number of non-overlapping occurrences of a substring.

```c
/**
 * Counts the number of non-overlapping occurrences of a substring within a string.
 *
 * @param subject - The original string to search within.
 * @param search - The substring to look for.
 * @return - The number of times the substring appears in the subject string.
 */
int str_count(const char *subject, const char *search)
```

### - str_trim()

Removes whitespace (such as spaces, tabs, and newlines) from the beginning and end of a string.  
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

Allocates and returns a new string where the first occurrence of 'search' in 'subject' is replaced with 'replace'.  
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

Iteratively replaces every instance of 'search' in 'subject' with 'replace', returning a newly allocated string containing all the modifications.  
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
