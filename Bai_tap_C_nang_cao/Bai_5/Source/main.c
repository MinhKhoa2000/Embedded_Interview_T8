#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    char *digit;

    uint8_t length;

    uint8_t place_Valua;    // 1: tram, 2: nghin, 3: trieu, 4: ty
} number_Unit;

void display (char digit)
{
    switch (digit)
    {
    case '0':
        printf("Khong ");
        break;

    case '1':
        printf("Mot.j ");
        break;

    case '2':
        printf("Hai ");
        break;

    case '3':
        printf("Ba ");
        break;

    case '4':
        printf("Bon ");
        break;

    case '5':
        printf("Nam ");
        break;

    case '6':
        printf("Sau ");
        break;

    case '7':
        printf("Bay ");
        break;

    case '8':
        printf("Tam ");
        break;
        
    case '9':
        printf("Chin ");
        break;
    
    default:
        break;
    }
}

void read_Number (char *number, uint8_t size)
{
    uint8_t check_Zero = 0;

    while (number[check_Zero] == '0')
    {
        check_Zero++;

        if (check_Zero == size - 1)
        {
            printf("Khong ");

            break;
        }
    }

    uint8_t end = check_Zero;

    uint8_t index = 0;

    if ((size - end - 1) % 3 == 0)
    {
        index = (size - 1) / 3;
    }

    else index = ((size - end - 1) / 3) + 1;

    number_Unit *digit = malloc(index * sizeof(number_Unit));
    
    for (uint8_t i = 0; i < index; i++)
    {
        digit[i].length = 0;

        digit[i].place_Valua = i;
    }

    for (uint8_t i = size - 1; i > end; i--)
    {
        digit[(size - i - 1) / 3].length += 1;

        if ((size - i - 1) % 3 == 0)
        {
            digit[(size - i - 1) / 3].digit = &number[i - 1];

            digit[(size - i - 1) / 3].place_Valua += 1;
        }
    }

    for (uint8_t i = index; i > 0; i--)
    {
        switch (digit[i - 1].length)
        {
        case 3:
            if (digit[i - 1].place_Valua > 1)
            {
                display(*(digit[i - 1].digit - 2));

                printf("Tram ");
            }

            else if (*(digit[i - 1].digit - 2) != '0')
            {
                display(*(digit[i - 1].digit - 2));

                printf("Tram ");
            }
            
            else if (*(digit[i - 1].digit - 1) != '0' || *digit[i - 1].digit != '0')
            {
                display(*(digit[i - 1].digit - 2));

                printf("Tram ");
            }
            

            if (*(digit[i - 1].digit - 1) == '0' && *digit[i - 1].digit == '0')
            {
                break;
            }

        case 2:
            if (*(digit[i - 1].digit - 1) != '0' && *(digit[i - 1].digit - 1) != '1')
            {
                display(*(digit[i - 1].digit - 1));

                printf("Muoi ");
            }

            else if (*(digit[i - 1].digit - 1) == '0')
            {
                printf("Le ");
            }
            
            else if (*(digit[i - 1].digit - 1) == '1')
            {
                printf("Muoi.f ");
            }

        case 1:
            if (*digit[i - 1].digit != '0')
            {
                display(*digit[i - 1].digit);

                break;
            }

            if (*(digit[i - 1].digit - 1) != '0')
            {
                if (digit[i - 1].length > 1)
                {
                    if (*digit[i - 1].digit == '5')
                    {
                        printf("Lam ");

                        break;
                    }
                    
                    if (*(digit[i - 1].digit - 1) != '1')
                    {
                        if (*digit[i - 1].digit == '1')
                        {
                            printf("Mot.s ");
                            
                            break;
                        }
                    
                        else if (*digit[i - 1].digit == '4')
                        {
                            printf("Tu ");
                            
                            break;
                        }
                    }
                }
            }
            
            
        default:
            break;
        }

        if (digit[i - 1].place_Valua == 4)
        {
            printf("Ty ");
        }
        else if (digit[i - 1].place_Valua == 3)
        {
            printf("Trieu ");
        }
        else if (digit[i - 1].place_Valua == 2)
        {
            printf("Nghin ");
        }
            
    }

    free(digit);

    printf("\n");
}

int main(int argc, char const *argv[])
{
    char number[] = "10101101101";

    printf("\nInput Number: %s\n", number);

    printf("\n");

    printf("Read: ");

    read_Number(number, sizeof(number));

    printf("\n");

    return 0;
}
