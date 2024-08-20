#include <stdio.h>
#include <omp.h>

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 3, 9, 3}; // Ejemplo de datos
    int n = 10; // Tamaño del vector
    int key = 3; // Valor a buscar
    int count = 0;

    // Paralelización con OpenMP
    #pragma omp parallel for reduction(+:count)
    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            count++;
        }
    }

    printf("El valor %d aparece %d veces en el vector.\n", key, count);

    return 0;
}
