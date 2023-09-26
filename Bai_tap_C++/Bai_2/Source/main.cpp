#include <iostream>
#include "func.h"

int main(int argc, char const *argv[])
{
    list<dish> databaseDishOnMenu;

    list<table> databaseTable;
    
    option(databaseDishOnMenu, databaseTable);
    
    return 0;
}