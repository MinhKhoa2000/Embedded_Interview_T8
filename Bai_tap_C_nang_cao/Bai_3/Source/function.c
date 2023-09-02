#include <function.h>

void reverse_String (char string[])
{
    // find amount of word in string
    uint8_t flag = 0;

    uint8_t size = 1;

    while (string[flag] != '\0')
    {
        if (string[flag] == ' ')
        {
            size++;
        }

        flag++;
    }

    flag = 0;

    // find *position of first character* and *size* of each word
    uint8_t index = 0;

    uint8_t count = 0;

    Word *Word_Info = (Word *)malloc(size * sizeof(Word));

    Word_Info[index].position = string;

    while (string[flag] != '\0')
    {
        if (string[flag] == ' ')
        {
            Word_Info[index].size = count;

            Word_Info[++index].position = string + flag + 1;

            count = 0;

            flag++;

            continue;
        }
        
        count++;

        flag++;
    }

    Word_Info[index].size = count;

    // print word from bottom to top
    printf("\n- Reverse string:\n");

    for (int8_t i = index; i >= 0; i--)
    {
        for (uint8_t j = 0; j < Word_Info[i].size; j++)
        {
            printf("%c", Word_Info[i].position[j]);
        }
        
        printf(" ");
    }
    
    printf("\n\n");
}