#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct
{
    char *character;

    uint8_t length;
} word_Type;

void sort_String (char array[])
{
    uint8_t i = 0;

    uint8_t word_Amount = 1;

    while (array[i] != '\0')
    {
        if (array[i] == ' ')
        {
            word_Amount++;
        }

        i++;
    }
    
    word_Type *word = malloc(word_Amount * sizeof(word_Type));

    uint8_t index = 0;

    word[index].character = array;

    i = 0;

    uint8_t length = 0;

    while (array[i] != '\0')
    {
        if (array[i] == ' ')
        {
            word[index].length = length;
            length = 0;
            word[++index].character = array + i + 1;
        }

        else
        {
            length++;
        }

        i++;
    }

    word[index].length = length;

    word_Type temp;

    index = 0;
    
    for (i = 0; i < word_Amount; i++)
    {
        temp = word[i];

        index = i;

        for (uint8_t j = i + 1; j < word_Amount; j++)
        {
            uint8_t check = 0;

            for (uint8_t k = 0; k < temp.length; k++)
            {
                if (temp.character[k] > word[j].character[k])
                {
                    temp = word[j];

                    index = j;

                    break;
                }

                else if (temp.character[k] < word[j].character[k])
                {
                    break;
                }
            }
        }
            
        if (index != i)
        {
            word[index] = word[i];
            
            word[i] = temp;
        }
    }
    
    for (i = 0; i < word_Amount; i++)
    {
        for (uint8_t j = 0; j < word[i].length; j++)
        {
            printf("%c", word[i].character[j]);
        }
        
        printf(" ");
    }

    free(word);
}

int main(int argc, char const *argv[])
{
    char string[] = "an anh hoang nam hoang hoa anh yen an nam yen hoa hoang";

    printf("\n");

    sort_String(string);

    printf("\n\n");
    
    return 0;
}
