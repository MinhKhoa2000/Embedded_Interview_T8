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

            wordInfo[index].status = true;
        
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
        int8_t count = 0;

        if (wordInfo[i].length > 0 && wordInfo[i].status != false)
        {

            for (uint8_t j = i; j < size; j++)
            {
                uint8_t check = 0;

                if (wordInfo[i].length == wordInfo[j].length)
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
                }
            }

            for (int k = 0; k < wordInfo[i].length; k++)
            {
                printf("%c", wordInfo[i].letter[k]);
            }

            printf("\t- So lan lap lai: %d\n", count);
        }

    }

    free(wordInfo);
}