#include <stdio.h>
#include <stdbool.h>

typedef long long custom_integer;

/// @brief Check if the computed factorial is correct.
/// @param n Value to be checked.
/// @param i Magnitude of the factorial.
/// @return Boolean value indicating whether overflow occurred.
bool check_overflow(custom_integer n, int i);

/// @brief Calculate a factorial.
/// @param n Magnitude of the factorial.
/// @return 
custom_integer factorial(int n);

int main(void) {
    for (int i = 1; ; ++i) {
        custom_integer result = factorial(i);
        printf("%d\t%lld\n", i, result);

        if (check_overflow(result, i)) {
            break;
        }
    }

    return 0;
}

custom_integer factorial(int n) {
    custom_integer result = 1;

    while (n > 1) {
        result *= n--;
    }

    return result;
}

bool check_overflow(custom_integer n, int i) {
    while (i > 1) {
        if (n % i != 0) {
            return true;
        }
        --i;
    }

    return false;
}