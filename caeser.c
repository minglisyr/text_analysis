// Problem Set 2 for CS50 2024, Caesar practice
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform Caesar cipher encryption
// It modifies the input string directly
void caesar_cipher(const string plaintext, int key)
{
    int len = strlen(plaintext);
    
    // Iterate through each character in the plaintext
    for (int i = 0; i < len; i++) 
    {
        // Only encrypt alphabetic characters
        if (isalpha(plaintext[i])) 
        {
            // Determine the base (A for uppercase, a for lowercase)
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            
            // Apply Caesar cipher formula:
            // 1. Shift character to 0-25 range
            // 2. Add key and wrap around using modulo
            // 3. Shift back to ASCII range
            plaintext[i] = ((plaintext[i] - base + key) % 26) + base;
        }
        // Non-alphabetic characters remain unchanged
    }
}

// Function to check if a string represents a positive integer
bool is_positive_integer(string s)
{
    // Check each character in the string
    for (int i = 0; s[i] != '\0'; i++)
    {
        // If any character is not a digit, return false
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    // All characters are digits, return true
    return true;
}

int main(int argc, string argv[]) 
{
    // Check for correct number of arguments and valid key
    if (argc != 2 || !is_positive_integer(argv[1]) || atoi(argv[1]) == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert key to integer and normalize it to 0-25 range
    int key = atoi(argv[1]) % 26;
    
    // Get plaintext from user, ensuring non-NULL input
    string text;
    do {
        text = get_string("plaintext: ");
    } while (text == NULL);

    // Perform Caesar cipher encryption
    caesar_cipher(text, key);

    // Print the encrypted text
    printf("ciphertext: %s\n", text);
    return 0;
}