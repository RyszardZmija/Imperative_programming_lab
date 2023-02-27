#include <stdio.h>
#include <math.h>

#define PI 3.14159265
#define STEP (PI / 6)
#define VAL_NUM 12
#define EPSILON 10e-6

double my_cos(double x);

void print_table(double a, double b, double change);

double my_sqrt(double x);

double my_pow(double x, int exp);

double my_abs(double x);

int main(void) {
    double a = 0.0, b = 0.0, delta = 0.0;

    printf("Enter the interval ([a, b]): ");
    scanf(" [ %lf , %lf ]", &a, &b);

    printf("Enter the change of the variable: ");
    scanf("%lf", &delta);

    print_table(a, b, delta);

    return 0;
}

double my_cos(double x) {
    // Values for cosine from 0 to 11pi/6 with step = pi/6
    const double cos_vals[VAL_NUM] = {1, my_sqrt(3) / 2, 1.0 / 2,
        0, -1.0 / 2, -my_sqrt(3) / 2, -1, -my_sqrt(3) / 2, -1.0 / 2, 0,
        1.0 / 2, my_sqrt(3) / 2};
    
    // The same for sine.
    const double sin_vals[VAL_NUM] = {0, 1.0 / 2, my_sqrt(3) / 2, 1, sqrt(3) / 2,
        1.0 / 2, 0, -1.0 / 2, -sqrt(3) / 2, -1, -sqrt(3) / 2, -1.0 / 2};
    
    // what multiple of STEP
    int i = 0;

    if (x >= 0) {
        double start = 0.0;

        while (start < x) {
            ++i;
            start += STEP;
        }
    }
    else {
        double start = 0.0;

        while (start > x) {
            ++i;
            start -= STEP;
        }
    }

    double cosine_val = cos_vals[i % VAL_NUM];
    double sine_val = sin_vals[i % VAL_NUM];

    if (x < 0) {
        sine_val = -sine_val;
        i = -i;
    }

    double x0 = i * STEP;
    // first part
    double result = cosine_val - sine_val * (x - x0);

    // second part
    result = result - cosine_val * my_pow(x - x0, 2) / 2;
    result = result + sine_val * my_pow(x - x0, 3) / 6;
    result = result + cosine_val * my_pow(x - x0, 4) / 24;

    return result;
}

double my_sqrt(double x) {
    double guess = x / 2;

    double prev_result = 0.5 * (guess + (x / guess));
    double result = 0.5 * (prev_result + (x / prev_result));

    while (my_abs(result - prev_result) >= EPSILON) {
        prev_result = result;
        result = 0.5 * (prev_result + (x / prev_result));
    }

    return result;
}

double my_abs(double x) {
    return x < 0 ? -x : x;
}

double my_pow(double x, int exp) {
    double result = 1.0;

    while (exp-- > 0) {
        result *= x;
    }

    return result;
}

void print_table(double a, double b, double change) {
    double dist = b - a;
    // Number of steps before b.
    int steps = (int) (dist / change);

    const char *str1 = "x";
    const char *str2 = "cos(x)";
    const char *str3 = "my_cos(x)";

    printf("%8s%12s%11s\n", str1, str2, str3);
    
    // For the reason for using prev_x see the note below.
    double prev_x = 0;
    for (int i = 0; i <= steps + 1; ++i) {
        double x = a + i * change;

        // We do this like this because it difficult
        // to reliably write a different condition for
        // this case because of precision errors.
        // e.g. (steps - dist / change) is sometimes
        // non-zero even when it should be zero
        if (i == steps + 1) {
            x = b;
        }

        if (x != prev_x) {
            printf("%9lf  %9lf  %9lf\n", x,
            cos(x), my_cos(x));
        }

        prev_x = x;
    }
}