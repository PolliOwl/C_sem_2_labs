#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define ERROR_INPUT 1

#define ODD_MASK 0xAAAAAAAAu
#define EVEN_MASK 0x55555555u

int main(void)
{
    uint32_t a;
    uint32_t result;

    printf("Введите целое беззнаковое число: ");
    if (scanf("%" SCNu32, &a) != 1)
    {
        printf("Error: ожидалось одно число");
        return ERROR_INPUT;
    }

    result = ((a & ODD_MASK) >> 1) | ((a & EVEN_MASK) << 1);

    printf("Result: ");
    for (int i = 31; i >= 0; i--)
    {
        printf("%u", (result >> i) & 1);
    }

    return 0;
}
