#include <stdio.h>
#include <stdlib.h>
#include "lib/string_utils.h"

int main() 
{
    char *input = "Hello, my name is Carlo and i'm a software developer!";
    char *output = str_replace(input, "Carlo", "Yami-no-karuro");

    printf("Input: %s\n", input);
    printf("Output: %s\n", output);
    free(output);

    return 0;
}
