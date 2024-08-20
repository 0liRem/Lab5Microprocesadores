#include <stdio.h>
#include <omp.h>

int main() {
    int variable1 = 0;
    int variable2;
    int n = 10;  // Definimos el tamaño del ciclo

    // Usando OpenMP para paralelizar el ciclo for
    #pragma omp parallel for shared(variable1) private(variable2)
    for (int i = 0; i < n; i++) {
        variable2 = i * 2;  // Cada hilo tiene su propia copia de variable2
        variable1 += variable2;  // variable1 es compartida entre hilos
        printf("Hilo %d: variable1 = %d, variable2 = %d\n", omp_get_thread_num(), variable1, variable2);
    }

    printf("Resultado final: variable1 = %d\n", variable1);

    return 0;
}

//Shared puede dar diferencias con cada ejecución ya que pueden colisionar al utilizar la misma variable para las operaciones
//private crea las copias lo que permite evitar colisiones y manejar de mejor manera los resultados