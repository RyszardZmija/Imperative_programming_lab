#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef long long integer;

bool is_perfect(integer n) {
    integer sum = 1;

    for (int i = 2; (integer) i * i <= n; ++i) {
        if (n % i == 0) {
            sum += i;
            
            if ((integer) i * i != n) {
                sum += n / i;
            }
        }
    }

    return n == 1 ? 0 : sum == n;
}

int main(void) {
    for (integer i = 0; i <= LLONG_MAX; ++i) {
        if (is_perfect(i)) {
            printf("%lld\n", i);
        }
    }

    return 0;
}