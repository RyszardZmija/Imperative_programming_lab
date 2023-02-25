#include <stdio.h>
#include <ctype.h>

#define NUM_LETTERS 26
#define BUFFER_SIZE 256

/// @brief Encrypt a string using Caesar's cipher.
/// @param ciphertext Buffer that will hold the cipher_text.
/// Must be at least as large as plaintext. Otherwise this
/// function results in undefined behaviour.
/// @param plaintext Plain text that is to be encrypted.
/// @param shift Shift that will be used during encryption.
/// @return Pointer to the first element of the array holding the ciphertext.
char *encrypt(char *ciphertext, const char *plaintext, int shift);

/// @brief Reads a sequence of characters storing it in the passed
/// character array. Terminates the input with a null.
/// This function does not skip whitespace characters, reads until
/// the first newline character (not stored) is encountered and discards the
/// rest of the line if it doesn't fit into the buffer.
/// @param str Character array in which we'll store the input.
/// @param size Maximum number of characters to be read (without the null!).
/// @return Number of characters stored.
int read_line(char *str, int size);

// Test encrypt() function using a custom string
// reading function.
int main(void) {
    char plaintext[BUFFER_SIZE] = {0}, ciphertext[BUFFER_SIZE] = {0};
    int shift = 0;
    printf("Enter the plaintext: ");
    (void) read_line(plaintext, BUFFER_SIZE - 1);
    printf("Enter the shift: ");
    scanf("%d", &shift);

    (void) encrypt(ciphertext, plaintext, shift);

    printf("%s\n", ciphertext);

    return 0;
}

char *encrypt(char *ciphertext, const char *plaintext, int shift) {
    char *start_ptr = ciphertext;

    while (*plaintext) {
        if (isalpha(*plaintext)) {
            // Use the properties of the underlying character set i.e. ASCII
            if (isupper(*plaintext)) {
                *ciphertext = ((*plaintext - 'A') + shift) % NUM_LETTERS + 'A';
            }
            else {
                *ciphertext = ((*plaintext - 'a') + shift) % NUM_LETTERS + 'a';
            }
        }
        else {
            *ciphertext = *plaintext;
        }
        // plaintext and ciphertext point to arrays so pointers arithmetic is allowed
        ++plaintext;
        ++ciphertext;
    }

    // Terminate ciphertext string with a null character.
    *ciphertext = '\0';

    return start_ptr;
}

int read_line(char *str, int size) {
    int c = 0, counter = 0;

    while ((c = getchar()) != '\n') {
        if (counter < size) {
            str[counter++] = c;
        }
    }

    // Terminate the string
    str[counter] = '\0';

    return counter;
}