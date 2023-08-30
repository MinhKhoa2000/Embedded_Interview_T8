#include <stdio.h>
#include "function.h"


int main(int argc, char const *argv[])
{
    char array[] = "mot hai ba, hai ba hai mot, ba bon hai, mot ba bon";

    printf("\n");

    printf("String: %s\n", array);

    countWord(array);

    printf("\n");

    return 0;
}
