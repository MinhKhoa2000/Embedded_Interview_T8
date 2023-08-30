#include "function.h"

void capitalString (char string[])
{
    uint8_t flag = 0;

    printf("\n");

    while (string[flag] != '\0')
    {
        if (string[flag] == 46)
        {
            printf("%c", string[flag]);
            
            flag++;

            break;
        }
        
        printf("%c", string[flag]);

        flag++;
    }

    while (string[flag] != '\0')
    {
        if (string[flag] > 96 && string[flag] < 123) printf("%c", string[flag] - 32);

        else printf("%c", string[flag]);

        flag++;
    }

    printf("\n\n");
}

void findString (char string[], char input[])
{
    uint8_t sizeString = 0;

    while (string[sizeString] != '\0') sizeString++;

    uint8_t sizeInput = 0;

    printf("\nFind Text: ");

    while (input[sizeInput] != '\0') 
    {
        printf("%c", input[sizeInput]);

        sizeInput++;
    }

    printf("\n");

    bool check = 0;
    
    for (uint8_t i = 0; i < sizeString; i++)
    {
        for (uint8_t j = 0; j < sizeInput; j++)
        {
            if (string[i + j] != input[j]) break;

            else if (j == sizeInput - 1)
            {
                printf("Co!\n");

                check = 1;
            }
        }
        
        if (check)
        {
            printf("Vi tri: %d\n", i);

            break;
        }

        if (i == sizeString -1)
        {
            printf("Khong co!\n");
        }
    }

    printf("\n");
}

void find_replaceString (char string[], char s_Find[], char s_Replace[])
{
    uint8_t sizeString = 0;

    while (string[sizeString] != '\0') sizeString++;

    uint8_t sizeFind = 0;

    while (s_Find[sizeFind] != '\0') sizeFind++;

    uint8_t sizeReplace = 0;

    while (s_Replace[sizeReplace] != '\0') sizeReplace++;

    printf("\n");

    printf("Find: %s\nReplace: %s\n", s_Find, s_Replace);

    uint8_t replace_time = 0;

    for (uint8_t i = 0; i < sizeString; i++)
    {
        for (uint8_t j = 0; j < sizeFind; j++)
        {
            if (string[i + j] != s_Find[j]) break;

            else if (j == sizeFind - 1) replace_time++;
        }
    }

    if (replace_time != 0)
    {
        printf("Tim thay chuoi can thay the!\n");

        for (uint8_t i = 0; i < sizeString; i++)
        {
            for (uint8_t j = 0; j < sizeFind; j++)
            {
                if (string[i + j] != s_Find[j])
                {
                    printf("%c", string[i]);

                    break;
                }

                else if (j == sizeFind - 1)
                {
                    printf("%s", s_Replace);

                    i += sizeFind - 1;
                }
            }
        }
    }
    
    else printf("Khong tim thay chuoi can thay the!");
    
    printf("\n\n");
}