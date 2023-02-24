#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h>
#include <time.h>

#define START_LOWER_BOUND 0
#define START_UPPER_BOUND 100

/// @brief Side effects: seed the random number generator. 
void initialize_generator(void);

/// @brief Return a pseudo-random integer from the left-inclusive
/// range [a, b) (STL convention used).
/// @param a Left end of the range
/// @param b Right end of the range (similar to off the end pointer)
int rand_range(int a, int b);

/// @brief Prompts the user for input. Just for fun
/// to modularize and document the code, unnecessary.
/// @param message beginning of the message
/// @param lower lower bound for values
/// @param upper upper bound for values
void prompt(const char *message, int lower, int upper);

/// @brief Encapsulates code that reads data from the user.
/// May clash with UNIX read() function. No function overloading...
/// @return Value that is a guess.
int read(void);

int main(void) {
    initialize_generator();

    const char *message = "Enter an integer";
    int secret = rand_range(START_LOWER_BOUND,
        START_UPPER_BOUND + 1), guess = 0;

    prompt(message, START_LOWER_BOUND, START_UPPER_BOUND);
    guess = read();

    while (guess != secret) {
        int lower = guess < secret ? guess : secret;
        int upper = guess > secret ? guess : secret;

        secret = rand_range(lower, upper + 1);
        prompt(message, lower, upper);
        guess = read();

        if (guess < lower || guess > upper) {
            printf("Error: input out of range!\n");
            exit(EXIT_FAILURE);
        }
    }

    printf("Congratulations you have won the game!!!\n");

    exit(EXIT_SUCCESS);

    // Stylistic return statement.
    // Unreachable code but not a logical error.
    return 0;
}

// Define the functions called from main().
void initialize_generator(void) {
    // Use the time function to provide a reasonably
    // random seed for the random generator.
    srand((unsigned) time(NULL));
}

// [a, b) defines a left-inclusive range.
int rand_range(int a, int b) {
    return rand() % (b - a) + a;
}

// Prompt the user with a proper message.
void prompt(const char *message, int lower, int upper) {
    printf("%s between %d and %d: ", message, lower, upper);
}

// Read input from the user.
int read(void) {
    int result = 0;

    scanf("%d", &result);

    return result;
}