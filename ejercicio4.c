#include <stdio.h>
#include <stdlib.h>  // Para rand() y srand()
#include <time.h>    // Para time() y clock()

//se tuvo que bajar la cantidad por el consumo de datos.
int main() {
    // Declaración del arreglo 3D de 1000x1000x1000
    int arr[100][100][100];
    int i, j, k;
    int iteracion = 0;
    for(iteracion=0; iteracion<5; iteracion++){
        // Inicializa la semilla para números aleatorios
        srand(time(NULL));
        // Llenar el arreglo 3D con números aleatorios entre 0 y 99
        for(i = 0; i < 100; i++) {
            for(j = 0; j < 100; j++) {
                for(k = 0; k < 100; k++) {
                    arr[i][j][k] = rand() % 100;
                }
            }
        }
        // Tomar tiempo de inicio
        clock_t inicio = clock();
        // Recorrer el arreglo 3D sin imprimir valores
        for(i = 0; i < 100; i++) {
            for(j = 0; j < 100; j++) {
                for(k = 0; k < 100; k++) {
                    volatile int temp = arr[i][j][k]; // Evita optimización del compilador
                }
            }
        }
        // Tomar tiempo de finalización
        clock_t fin = clock();
        // Calcular tiempo de ejecución
        double tiempo_ejecucion = (double)(fin - inicio) / CLOCKS_PER_SEC;
        // Imprimir resultado
        printf("Tiempo de ejecución de la ietarcion %d: %.15f segundos\n", iteracion+1, tiempo_ejecucion);
    }
    return 0;
}

