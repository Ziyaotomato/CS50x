#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]) % 26;
    string plaintext = get_string("plaintext: ");
    int length = strlen(plaintext);
    int ciphertext[length];
    for (int i = 0; i < length; i++)
    {
        if ((int)plaintext[i] >= 65 && (int)plaintext[i] <= 90)
        {
            if (((int)plaintext[i] + key) <= 90)
            {
                ciphertext[i] = (char)((int)plaintext[i] + key);
            }
            else
            {
                ciphertext[i] = (char)((int)plaintext[i] - 90 + 64 + key);
            }
        }
        else if ((int)plaintext[i] >= 97 && (int)plaintext[i] <= 122)
        {
            if (((int)plaintext[i] + key) <= 122)
            {
                ciphertext[i] = (char)((int)plaintext[i] + key);
            }
            else
            {
                ciphertext[i] = (char)((int)plaintext[i] - 122 + 96 + key);
            }
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    printf("ciphertext: ");
    for (int k = 0; k < length; k++)
    {
    printf("%c", ciphertext[k]);
    }
    printf("\n");

}
