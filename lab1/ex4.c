#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define NUM_PER_LINE 5
typedef int32_t integer;

/// @brief Check if the integer's digits are in
/// non-decreasing order.
/// @param n The number to be checked.
/// @return Boolean result of the condition.
bool digits_non_decreasing(integer n);

/// @brief Check if the integer is prime.
/// @param n Integer to be checked.
/// @return Boolean result of the condition.
bool is_prime(integer n);

int main(void) {
    integer n = 0;

    printf("Enter the upper bound: ");

    // This shows the implementation that we're using and
    // assumes that int has width 4 on this machine. How
    // to fix: Macros and each case considered?
    scanf("%d", &n);

    unsigned counter = 0;
    for (integer i = 2; i < n; ++i) {
        if (digits_non_decreasing(i) && is_prime(i)) {
            ++counter;
            printf("%d\t", i);
        }
        
        if (counter == NUM_PER_LINE) {
            counter = 0;
            printf("\n");
        }
    }

    return 0;
}

bool digits_non_decreasing(integer n) {
    int digit = n % 10, next_digit = 0;
    n /= 10;

    while (n > 0) {
        next_digit = n % 10;

        if (next_digit > digit) {
            return false;
        }

        n /= 10;
        digit = next_digit;
    }

    return true;
}

bool is_prime(integer n) {
    if (n == 2) {
        return true;
    }

    if (n < 0 || n % 2 == 0) {
        return false;
    }

    for (integer i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}