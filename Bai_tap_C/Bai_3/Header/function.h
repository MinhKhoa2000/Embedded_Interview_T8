#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct
{
    char *position;
    uint8_t size;
} Word;

void reverse_String (char string[]);

#endif