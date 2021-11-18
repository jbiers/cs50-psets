#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// Get key as command line argument (only one, not less and not more) --OK
// Validate key (26 letters, all alphabetic, no repetition)
// Get plaintext from user
// Map cypher to text, attention to the case
// Return cyphertext

int validateKey(string key)
{
    // Check if it has 26 characters
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Check for only alphabetic characters, and avoiding repetition. Any upper case will be converted to lower case.
    for (int i = 0; i < 26; i++)
    {
        if (isalpha(key[i]) != 0)
        {
            key[i] = tolower(key[i]);
            for (int j = i + 1; j < 26; j++)
            {
                if (key[i] == key[j] || key[i] == tolower(key[j]) || key[i] == toupper(key[j]))
                {
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }
            }
        }

        else
        {
            printf("Key must contain only alphabetic characters.\n");
            return 1;
        }
    }

    return 0;
}

string applyCypher(string plaintext, string key)
{
    string cyphertext = plaintext;

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            cyphertext[i] = toupper(key[plaintext[i] - 65]);
        }

        else if (islower(plaintext[i]))
        {
            cyphertext[i] = key[plaintext[i] - 97];
        }
    }

    return cyphertext;
}

// To get command line arguments, you pass argc (an integer) and argv (an array of strings) to the main function
int main(int argc, string argv[])
{
    // Check if only one key argument was provided
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    if (validateKey(key) != 0)
    {
        return 1;
    }

    // Get plaintext from user
    string plaintext = get_string("plaintext: ");

    string cyphertext = applyCypher(plaintext, key);
    printf("ciphertext: %s\n", cyphertext);

    return 0;
}