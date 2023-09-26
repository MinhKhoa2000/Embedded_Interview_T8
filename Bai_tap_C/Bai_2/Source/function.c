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

    printf("- Find: %s\n- Replace: %s\n", s_Find, s_Replace);

    uint8_t replace_time = 0;

    //tim doan can replace co trong string khong?
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
        printf("!Tim thay chuoi can thay the!\n");

        for (uint8_t i = 0; i < sizeString; i++)
        {
            for (uint8_t j = 0; j < sizeFind; j++)
            {
                if (string[i + j] != s_Find[j]) break;

                else if (j == sizeFind - 1)
                {
                    if (sizeReplace < sizeFind)
                    {
                        //gan replace vao string
                        for (uint8_t k = 0; k < sizeReplace; k++)
                        {
                            string[i + k] = s_Replace[k];
                        }
                        
                        //rut ngan string
                        for (uint8_t k = i + sizeFind; k < sizeString; k++)
                        {
                            string[k - sizeFind + sizeReplace] = string[k];

                            if (k == sizeString - 1)
                            {
                                string[k - sizeFind + sizeReplace + 1] = '\0';
                            }
                        }

                        //tro i vao vi tri sau doan dc replace
                        i += sizeReplace - 1;

                        //thay doi do dai string
                        sizeString -= sizeFind - sizeReplace;
                    }
                    
                    else if (sizeReplace > sizeFind)
                    {
                        //keo dai string
                        for (uint8_t k = sizeString; k > i + sizeFind - 1; k--)
                        {
                            string[k + sizeReplace - sizeFind] = string[k];
                        }

                        //gan replace vao string
                        for (uint8_t k = 0; k < sizeReplace; k++)
                        {
                            string[i + k] = s_Replace[k];
                        }

                        //tro i vao vi tri sau doan dc replace
                        i += sizeReplace - 1;

                        //thay doi do dai string
                        sizeString += sizeReplace - sizeFind;
                    }
                    
                    else
                    {
                        //gan replace vao string
                        for (uint8_t k = 0; k < sizeReplace; k++)
                        {
                            string[i + k] = s_Replace[k];
                        }

                        //tro i vao vi tri sau doan dc replace
                        i += sizeReplace - 1;
                    }
                }
            }
        }

        printf("%s", string);
    }
    
    else printf("!Khong tim thay chuoi can thay the!");
    
    printf("\n\n");
}