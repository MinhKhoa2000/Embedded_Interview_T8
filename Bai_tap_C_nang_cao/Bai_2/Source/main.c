#include <stdio.h>
#include "function.h"


int main(int argc, char const *argv[])
{
    char string[] = "the question isn't who is going to let me. it's who is going to stop me";

    capitalString(string);

    findString(string, "to let me");

    findString(string, "who will let me");

    find_replaceString(string, "is going to", "will");

    find_replaceString(string, "hit", "will");

    return 0;
}
