#include "function.h"

void display(uint8_t week_Code)
{
    switch (week_Code)
    {
    case SATURDAY:
        printf("Saturday\n\n");
        break;

    case SUNDAY:
        printf("Sunday\n\n");
        break;

    case MONDAY:
        printf("Monday\n\n");
        break;

    case TUESDAY:
        printf("Tuesday\n\n");
        break;

    case WEDNESDAY:
        printf("Wednesday\n\n");
        break;

    case THURSDAY:
        printf("Thursday\n\n");
        break;

    case FRIDAY:
        printf("Friday\n\n");
        break;
    
    default:
        break;
    }
}

uint8_t find_Year_Code (uint32_t year)
{
    uint8_t a;

    switch (((year / 100) + 1) % 4)
    {
    case 0:
        a = 1;
        break;
    case 1:
        a = 0;
        break;
    case 2:
        a = 5;
        break;
    case 3:
        a = 3;
        break;
    default:
        break;
    }

    uint8_t b = (year % 100) % 7;

    uint8_t c = (year % 100) /4;

    return (a + b + c -1) % 7;
}

uint8_t find_Month_Code (uint8_t month)
{
    switch (month)
    {
    case 4:
    case 7:
        return 0;
    
    case 1:
    case 10:
        return 1;

    case 5:
        return 2;

    case 8:
        return 3;

    case 2:
    case 3:
    case 11:
        return 4;

    case 6:
        return 5;

    case 9:
    case 12:
        return 6;
    
    default:
        break;
    }
}

void find_Day_Of_Week (uint8_t day, uint8_t month, uint32_t year)
{
    uint8_t month_Code = find_Month_Code(month);

    uint8_t year_Code = find_Year_Code(year);

    uint8_t week_Code = (day + month_Code + year_Code) % 7;

    if ((year % 4) == 0 && (month == 1 || month == 2))
    {
        if (week_Code == SATURDAY)
        {
            display(FRIDAY);
        }
        
        else
        {
            display(week_Code - 1);
        }
    }

    else
    {
        display(week_Code);
    }
}