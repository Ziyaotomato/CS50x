#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters();
int count_words();
int count_sentences();

int main(void)
{
    //Get a text from users.
    string text = get_string("Text: ");

    //Calculate the numbers of letters, words, sentences respectively.
    int letter_num = count_letters(text);
    int word_num = count_words(text);
    int sentence_num = count_sentences(text);

    //Calculate L, S, and index.
    float L = 100 * letter_num / word_num;
    float S = 100 * sentence_num / word_num;
    float indexf = 0.0588 * L - 0.296 * S - 15.8;
    int idxi = 0.0588 * L - 0.296 * S - 15.8;
    int index = (indexf - idxi) < 0.5? idxi:idxi+1;

    //Print the result.
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

//A function to count letters in the text.
int count_letters(string text)
{
    int sum = 0;
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text [i] >= 'A' && text [i] <= 'Z'))
        {
            sum += 1;
        }
    }
    return sum;
}

//A function to count words in the text.
int count_words(string text)
{
    int sum = 1;
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if (text[i] == ' ')
        {
            sum += 1;
        }
    }
    return sum;
}

//A function to count sentences in the text.
int count_sentences(string text)
{
    int sum = 0;
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if ((text[i] == '.')||(text[i] == '!')||(text[i] == '?'))
        {
            sum += 1;
        }
    }
    return sum;
}
