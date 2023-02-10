#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_mario(int height);

int main(void)
{
    int height = get_height();
    print_mario(height);
}

int get_height(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height<1 || height>8);
    return height;
}

void print_mario(int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int k = 1; k < height - i; k++)
        {
            printf(" ");
        }
        for (int j = 0; j < i+1; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j < i+1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
