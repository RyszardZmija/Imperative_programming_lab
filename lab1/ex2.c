#include <stdio.h>
#include <stdbool.h>

/// @brief Calculate the n-th fibonacci number.
/// @param n Index of the number to be calculated
/// @return n-th fibonacci number
int fib(int n);

/// @brief Check if the number is a factor of
/// two consecutive fibonacci numbers.
/// @param n The number to be checked.
/// @param a Pointer to a variable that will hold the
/// first number.
/// @param b Pointers to a variable that will hold the
/// second number.
/// @return Boolean value that indicates if the
/// condition is correct.
bool factor_of_two_consec_fib_num(int n, int *a, int *b);

int main(void) {
    int n = 0, first_num = 0, second_num = 0;

    printf("Enter the number to be checked: ");
    scanf("%d", &n);

    if (factor_of_two_consec_fib_num(n, &first_num, &second_num)) {
        printf("Yes, it is a factor of fibonacci numbers %d and %d.\n",
            first_num, second_num);
    }
    else {
        printf("No, there are no such fibonacci numbers that meet this criteria.\n");
    }

    return 0;
}

int fib(int n) {
    if (n <= 1) {
        return n;
    }
    
    int a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        int temp = b;
        b += a;
        a = temp;
    }

    return b;
}

bool factor_of_two_consec_fib_num(int n, int *a, int *b) {
    *a = 0;
    *b = 1;

    while (*a * *b < n) {
        int temp = *b;
        *b += *a;
        *a = temp;
    }

    if (*a * *b == n) {
        return true;
    }
    else {
        *a = *b = 0;
        return false;
    }
}