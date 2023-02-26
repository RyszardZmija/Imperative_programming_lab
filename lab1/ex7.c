#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void initialize_generator(void);

double func(double x);

void populate(int size, double *arr, double a, double b);

double random_double(double a, double b);

int main(void) {
    double a = 0.0, b = 0.0, integral_sum = 0.0;
    int n = 0;

    initialize_generator();
    printf("Enter the interval of integration ([a, b]): ");
    scanf(" [ %lf , %lf ]", &a, &b);

    printf("Enter the number of points to be used during "
        "the approximation: ");
    scanf("%d", &n);

    // Allocate a block of memory to store the data points.
    double *points = (double *) malloc(n * sizeof(double));

    if (points == NULL) {
        printf("Error: malloc() failed in main\n");
        exit(EXIT_FAILURE);
    }

    populate(n, points, a, b);

    for (int i = 0; i < n; ++i) {
        // This will produce the desired result
        // if and only if the result of func()
        // in the interval [a, b] is always
        // non-negative.
        // Possible modifications: absolute value
        // (will this work?)
        integral_sum += func(points[i]);
    }

    double result = (b - a) / n * integral_sum;

    printf("%.4lf\n", result);

    // Free the memory used by points
    free(points);
    
    return 0;
}

void initialize_generator(void) {
    srand((unsigned) time(NULL));
}

double func(double x) {
    return sin(x);
}

void populate(int size, double *arr, double a, double b) {
    for (double *p = arr; p < arr + size; ++p) {
        *p = random_double(a, b);
    }
}

double random_double(double a, double b) {
    double dist = b - a;
    double random = dist * ((double) rand() / RAND_MAX);

    return random + a;
}