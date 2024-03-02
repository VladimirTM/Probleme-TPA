#include <stdio.h>
#include <stdint.h>

#define SIZE 126 // (1000 / 8) + 1

void setBit(uint8_t *array, uint16_t number)
{
    uint8_t index = 0, position = 0;
    index = number / 8;
    position = number % 8;
    array[index] = array[index] | (1 << position);
}

void printArray(uint8_t *array)
{
    uint8_t index, position;
    uint16_t number;
    for (index = 0; index < SIZE; index++)
    {
        for (position = 0; position < 8; position++)
        {
            if ((array[index] & (1 << position)) != 0)
            {
                number = 8 * index + position;
                printf("%hd ", number);
            }
        }
    }
    printf("\n");
}

int main(void)
{
    uint8_t array[SIZE] = {0};
    uint16_t number;
    while (scanf("%hd", &number) == 1)
    {
        setBit(array, number);
    }
    printArray(array);
    return 0;
}