#include <stdio.h>
#include <omp.h>

int main() {
    const int N = 1000;
    int i;
    double sum = 0.0;
    double array[N];
	
	// Array initialization
    for (i = 0; i < N; i++) {
        array[i] = i;
    }

    // Parallel vector addition
    #pragma omp parallel for reduction(+:sum)
    for (i = 0; i < N; i++) {
        sum += array[i];
    }

    printf("La suma es: %f\n", sum);

    return 0;
}