#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    char *letter;
    uint8_t length;
    bool status;
} Words;

void countWord (char array[]);

#endif