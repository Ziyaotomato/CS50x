#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string message = get_string("Message: ");
    for (int i = 0; i < strlen(message); i++)
    {
        int value = (int)message[i];
        int bulbs[8];
        for (int j = 7; j >= 0; j--)
        {
            if (value >= pow(2, j))
            {
                bulbs[7 - j] = 1;
                print_bulb(1);
                value = value - pow(2, j);
            }
            else
            {
                bulbs[7 - j] = 0;
                print_bulb(0);
            }
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
