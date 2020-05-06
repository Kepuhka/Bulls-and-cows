#include <stdio.h>
#include <stdlib.h>
#include "Function.h"

int buffer_string(char *buffer, int n)
{
    FILE *file;

    file = fopen("Library.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    fgets(buffer, n, file);
    fclose(file);
    return 0;
}
