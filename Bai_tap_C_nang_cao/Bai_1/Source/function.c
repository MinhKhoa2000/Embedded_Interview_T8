#include "function.h"

void countWord (char array[])
{
    uint8_t size = 1;

    uint8_t flag = 0;

    while (array[flag] != '\0')
    {
        if (array[flag] == ' ' || array[flag] == ',')
        {
            size++;
        }
        
        flag++;
    }

    flag = 0;

    Words *wordInfo = (Words *)malloc(size * sizeof(Words));

    uint8_t index = 0;

    wordInfo[index].letter = array;

    uint8_t count = 0;

    while (array[flag] != '\0')
    {
        if (array[flag] == ' ' || array[flag] == ',')
        {
            wordInfo[index].length = count;
        
            wordInfo[++index].letter = array + flag + 1;

            count = 0;

            flag++;

            continue;
        }

        count++;

        flag++;
    }

    wordInfo[index].length = count;

    printf("\n");

    for (uint8_t i = 0; i < size; i++)
    {
        uint8_t count = 1;

        if (wordInfo[i].length != 0 && wordInfo[i].status != false)
        {
            uint8_t check = 0;
            
            for (uint8_t j = i + 1; j < size; j++)
            {
                while (wordInfo[i].letter[check] == wordInfo[j].letter[check])
                {
                    check++;

                    if (check == wordInfo[i].length)
                    {
                        count++;

                        wordInfo[j].status = false;

                        break;
                    }
                }

                check = 0;
            }

            for (int k = 0; k < wordInfo[i].length; k++)
            {
                printf("%c", wordInfo[i].letter[k]);
            }

            printf("\t- So lan lap lai: %d\n", count);

            count = 1;
        }
    }

    free(wordInfo);
}