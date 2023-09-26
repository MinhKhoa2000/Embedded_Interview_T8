#include <stdio.h>
#include "function.h"

int main(int argc, char const *argv[])
{
    char string[] = "mot hai ba bon nam sau bay tam chin";

    printf("\n- String:\n%s\n", string);

    reverse_String(string);

    return 0;
}
