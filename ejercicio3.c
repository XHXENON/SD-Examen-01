#include <stdio.h>
#include <stdlib.h>  // Para rand() y srand()
#include <time.h>    // Para time() y clock()

int main() {
    int arr[1000][1000]; // Matriz de 1000x1000
    int i, j;
    int iteracion = 0;

    for(iteracion=0; iteracion<5; iteracion++){
        // Se inicializa la semilla para la generación de números aleatorios
        srand(time(NULL));
        // Llenar la matriz con números aleatorios entre 0 y 99
        for(i = 0; i < 1000; i++) {
            for(j = 0; j < 1000; j++) {
                arr[i][j] = rand() % 100;
            }
        }
        // Se toma el tiempo de inicio
        clock_t inicio = clock();
        // Se recorre la matriz sin imprimir los valores
        for(i = 0; i < 1000; i++) {
            for(j = 0; j < 1000; j++) {
                volatile int temp = arr[i][j]; // Evita optimización del compilador
            }
        }
        // Se toma el tiempo de finalización
        clock_t fin = clock();
        // Se calcula el tiempo de ejecución
        double tiempo_ejecucion = (double)(fin - inicio) / CLOCKS_PER_SEC;
        // Se imprime el tiempo de ejecución
        printf("Tiempo de ejecucion de la iteracion %d: %.15f segundos\n", iteracion+1, tiempo_ejecucion);
    }
    return 0;
}

