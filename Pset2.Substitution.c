#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int position(char text);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        if (strlen(argv[1]) == 26)
        {
            for (int i = 0; i < 26; i++)
            {
                if ((!islower(argv[1][i] )) && !isupper(argv[1][i] ))
                {
                    return 1;
                }
            }

            string plaintext = get_string("plaintext: ");
            int n = strlen(plaintext);
            int series[n];
            char ciphertext[n];
            for (int i = 0; i < n; i++)
            {
                if (islower(plaintext[i]))
                {
                    series[i] = position(plaintext[i]);
                    if (islower(argv[1][series[i]]))
                    {
                        ciphertext[i] = argv[1][series[i]];
                    }
                    else
                    {
                        ciphertext[i] = tolower(argv[1][series[i]]);
                    }
                }
                else if (isupper(plaintext[i]))
                {
                    series[i] = position(plaintext[i]);
                    if (isupper(argv[1][series[i]]))
                    {
                        ciphertext[i] = argv[1][series[i]];
                    }
                    else
                    {
                        ciphertext[i] = toupper(argv[1][series[i]]);
                    }
                }
                else
                {
                    ciphertext[i] = plaintext[i];
                }
            }
            printf("ciphertext: %s\n", ciphertext);
        }

        else
        {
            printf("Key must contain 26 characters.");
            return 1;
        }
    }

    else
    {
        printf("Usage: ./substitution key");
        return 1;
    }
}

int position(char text)
{
    char lowercase[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char uppercase[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    for (int i = 0; i < 26; i++)
    {
        if ((text == lowercase[i])||(text == uppercase[i]))
        {
            return i;
        }
    }
    return -1;
}
