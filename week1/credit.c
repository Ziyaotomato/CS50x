#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>


int every_other_digit(long number);
int multiplyAndSum(int last_digit);
int number_of_digits(long number);
bool check_amex(long number);
bool check_master(long number);
bool check_visa1(long number);
bool check_visa2(long number);

int main(void)
{
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number <= 0);

    int sum = every_other_digit(number);
    int size = number_of_digits(number);

    if (sum % 10 == 0)
    {
        if (size == 15)
        {
            check_amex(number);
        }
        else if (size == 16)
        {
            if (number > 5000000000000000)
            {
            check_master(number);
            }
            else
            {
            check_visa1(number);
            }
        }
        else if (size == 13)
        {
            check_visa2(number);
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}

int every_other_digit(long number)
{
   int sum = 0;
   bool isAlternative = false;

   while (number > 0)
   {
        if (isAlternative == true)
        {
            int last_digit = number % 10;
            int product = multiplyAndSum(last_digit);
            sum = sum + product;
        }
        else
        {
            int last_digit = number % 10;
            sum = sum + last_digit;
        }
        isAlternative = !isAlternative;
        number = number / 10;
   }
   return sum;
}

int multiplyAndSum(int last_digit)
{
    int multiply = last_digit * 2;
    int sum = 0;
    while (multiply > 0)
    {
        int last_digit_multiply = multiply % 10;
        sum = sum + last_digit_multiply;
        multiply = multiply / 10;
    }
    return sum;
}


int number_of_digits(long number)
{
    int count = 0;
    while (number > 0)
    {
        count = count + 1;
        number = number / 10;
    }
    return count;
}

bool check_amex(long number)
{
    int beginning_digits = number / 1e13;
    if (beginning_digits == 34 || beginning_digits ==37)
    {
        printf("AMEX\n");
        return true;
    }
    else
    {
        printf("INVALID\n");
        return false;
    }
}

bool check_master(long number)
{
    int beginning_digits = number / 1e14;
    if (beginning_digits == 51 || beginning_digits ==52 || beginning_digits ==53 || beginning_digits ==54 || beginning_digits ==55)
    {
        printf("MASTERCARD\n");
        return true;
    }
    else
    {
        printf("INVALID\n");
        return false;
    }
}

bool check_visa1(long number)
{
    int beginning_digits = number / (1e15);
    if (beginning_digits == 4)
    {
        printf("VISA\n");
        return true;
    }
    else
    {
        printf("INVALID\n");
        return false;
    }
}

bool check_visa2(long number)
{
    int beginning_digits = number / 1e12;
    if (beginning_digits == 4)
    {
        printf("VISA\n");
        return true;
    }
    else
    {
        printf("INVALID\n");
        return false;
    }
}
