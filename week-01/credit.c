// AE - 15 digits, starts with 34 or 37
// MC - 16 digits, starts with 51, 52, 53, 54, 55
// Visa - 13 or 16 digits, starts with 4

// Luhn's Algorithm
// Multiply every other digit by 2, starting with the second to last one, then add the products up.
// Add the sum of the other digits to the total
// If last number is 0, it is valid.

#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Function to determine the length of a long number
int numLength(long divNumber)
{
    int count = 0;

    while (divNumber != 0)
    {
        divNumber = divNumber / 10;
        count = count + 1;
    }

    return count;
}

// Function to apply Luhn's Algorithm
int validate(long number)
{
    int sum = 0;
    int count = 1;
    int lastDigit, twiceLast;

    while (number != 0)
    {
        lastDigit = number % 10;
        twiceLast = lastDigit * 2;

        if (count % 2 == 0)
        {
            while (twiceLast != 0)
            {
                sum = sum + (twiceLast % 10);
                twiceLast = (twiceLast / 10);
            }
        }

        if (count % 2 != 0)
        {
            sum = sum + (number % 10);
        }

        printf("%li\n", number);
        number = number / 10;
        printf("%i\n", count);
        count = count + 1;
        printf("%i\n", sum);
    }

    if (sum % 10 == 0)
    {
        return 0;
    }

    else
    {
        return 1;
    }
}

int main(void)
{
    // Get user input
    long number = get_long("Number: ");

    // Find length of number
    int length = numLength(number);

    // Test for AMEX
    if (length == 15)
    {
        if (number / 10000000000000 == 34 || number / 10000000000000 == 37)
        {
            if (validate(number) == 0)
            {
                printf("AMEX\n");
                return 0;
            }

            else
            {
                printf("INVALID\n");
                return 0;
            }
        }
    }

    // Test for VISA
    if (length == 16 || length == 13)
    {
        int firstOne = number / pow(10, length - 1);

        if (firstOne == 4)
        {
            if (validate(number) == 0)
            {
                printf("VISA\n");
                return 0;
            }

            else
            {
                printf("INVALID\n");
                return 0;
            }
        }
    }

    // Test for MASTERCARD
    if (length == 16)
    {
        int firstTwo = number / 100000000000000;
        if (firstTwo == 51 || firstTwo == 52 || firstTwo == 53 || firstTwo == 54 || firstTwo == 55)
        {
            if (validate(number) == 0)
            {
                printf("MASTERCARD\n");
                return 0;
            }

            else
            {
                printf("INVALID\n");
                return 0;
            }
        }
    }

    printf("INVALID\n");
    return 0;
}