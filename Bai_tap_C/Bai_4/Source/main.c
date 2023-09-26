#include <stdio.h>
#include "function.h"


int main(int argc, char const *argv[])
{
    Date date;

    printf("\n");

    printf("Input Day: ");
    scanf("%d", &(date.day));

    printf("Input Month: ");
    scanf("%d", &(date.month));

    printf("Input Year: ");
    scanf("%d", &(date.year));
    
    printf("\n%d/%d/%d --> ", date.day, date.month, date.year);

    find_Day_Of_Week(date.day, date.month, date.year);

    return 0;
}
