#include <stdio.h>
#include <stdint.h>

#define CHECK_IF(vat_pham) \
    if (vat_pham & item)\
    {\
        if (vat_pham & bag) printf("- %s :da co\n", #vat_pham);\
        else printf("- %s :chua co\n", #vat_pham);\
    }


uint8_t bag = 0;    // 0000 0000


typedef enum {
    AO          = 1 << 0,   // 0000 0001
    QUAN        = 1 << 1,   // 0000 0010
    VAY         = 1 << 2,   // 0000 0100
    GIAY        = 1 << 3,   // 0000 1000
    NON         = 1 << 4,   // 0001 0000
    DONG_HO     = 1 << 5,   // 0010 0000
    VONG_TAY    = 1 << 6,   // 0100 0000
    DAY_CHUYEN  = 1 << 7    // 1000 0000
} item;



void add_item (uint8_t *bag, item item){
    *bag |= item;
}


void check_item (uint8_t bag, item item){
    printf("\nDanh sach san pham duoc kiem tra:\n");

    CHECK_IF(AO)
    CHECK_IF(QUAN)
    CHECK_IF(VAY)
    CHECK_IF(GIAY)
    CHECK_IF(NON)
    CHECK_IF(DONG_HO)
    CHECK_IF(VONG_TAY)
    CHECK_IF(DAY_CHUYEN)
}


void show_item (uint8_t bag){
    printf("\nDanh sach vat pham co trong tui do:\n");

    for (int i = 0; i < 8; i++)
    {
        switch (bag & (1 << i))
        {
        case AO:
            printf("- AO\n");
            break;
        case QUAN:
            printf("- QUAN\n");
            break;
        case VAY:
            printf("- VAY\n");
            break;
        case GIAY:
            printf("- GIAY\n");
            break;
        case NON:
            printf("- NON\n");
            break;
        case DONG_HO:
            printf("- DONG HO\n");
            break;
        case VONG_TAY:
            printf("- VONG TAY\n");
            break;
        case DAY_CHUYEN:
            printf("- DAY CHUYEN\n");
            break;
        default:
            break;
        }
    }
    
    printf("\n");
}

int main(int argc, char const *argv[])
{
    add_item(&bag, AO|QUAN|DONG_HO|NON|DAY_CHUYEN|GIAY);

    check_item(bag, DONG_HO|NON|VAY|VONG_TAY);

    show_item(bag);

    return 0;
}
