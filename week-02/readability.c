#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get int input from user
    int height = get_int("Height: ");

    // Test if less than 1 or more than 8
    while (height < 1 || height > 8)
    {
        height = get_int("Height: ");
    }

    int l, c1, c2;
    int ws, bs;

    // External loop for number of lines
    for (l = 0; l < height; l++)
    {
        ws = height - l - 1;
        bs = height - ws;

        // Internal loop for left columns
        for (c1 = 0; c1 < height; c1++)
        {
            if (c1 < ws)
            {
                printf(" ");
            }

            if (c1 >= ws)
            {
                printf("#");
            }
        }

        printf("  ");

        // Internal loop for right columns
        for (c2 = 0; c2 < height; c2++)
        {
            if (c2 < bs)
            {
                printf("#");
            }

        }

        printf("\n");
    }
}