#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <fstream>


#define READ_MODE "r+"
#define WRITE_MODE "w+"

FILE *openFile(const char *filename, const char *mode);

bool isNull(void *argument);

bool isNotNull(void *argument);