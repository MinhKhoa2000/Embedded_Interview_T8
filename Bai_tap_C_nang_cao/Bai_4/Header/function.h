#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <stdint.h>

typedef struct 
{
    uint8_t day;
    uint8_t month;
    uint32_t year;
} Date;

typedef enum
{
    SATURDAY,
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY
} Day_of_Week;

void display(uint8_t week_Code);

uint8_t find_Year_Code (uint32_t year);

uint8_t find_Month_Code (uint8_t month);

void find_Day_Of_Week (uint8_t day, uint8_t month, uint32_t year);

#endif