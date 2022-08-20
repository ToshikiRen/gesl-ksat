#include "utils.h"

FILE *openFile(const char *filename, const char *mode)
{
    FILE *file = fopen(filename, mode);
    if (file == NULL)
    {
        printf("The file %s could not be oppened!", filename);
        printf("Program EXIT_FAILURE!");
        exit(EXIT_FAILURE);
    }
    return file;
}

bool isNull(void *argument)
{
    return argument == NULL;
}

bool isNotNull(void *argument) {
    return !isNull(argument);
}