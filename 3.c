#include <stdio.h>
#include <omp.h>

void factorial(int n) {
    int i;
    unsigned long long fact = 1;
    for(i = 1; i <= n; i++) {
        fact *= i;
    }
    printf("Factorial de %d es %llu\n", n, fact);
}

void fibonacci(int n) {
    int i;
    unsigned long long t1 = 0, t2 = 1, nextTerm;
    printf("Serie Fibonacci hasta %d: ", n);
    for (i = 1; i <= n; i++) {
        printf("%llu ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");
}

void maximo(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Máximo en el arreglo es %d\n", max);
}

int main() {
    int n = 7;
    int arr[] = {1, 23, 56, 3, 89, 23, 7};

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            factorial(n);
        }
        #pragma omp section
        {
            fibonacci(n);
        }
        #pragma omp section
        {
            maximo(arr, 7);
        }
    }
    return 0;
}
