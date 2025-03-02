#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para ordenar el arreglo (Bubble Sort)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Función de búsqueda binaria
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Elemento no encontrado
}

int main() {
    const int SIZE = 1000; // Tamaño del arreglo
    int arr[SIZE];

    // Inicializar semilla para números aleatorios
    srand(time(NULL));

    // Llenar el arreglo con números aleatorios
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000; // Números entre 0 y 999
    }

    // Ordenar el arreglo
    bubbleSort(arr, SIZE);

    // Número a buscar (tomamos uno que existe en el arreglo)
    int target = arr[rand() % SIZE];
    printf("Buscando el número: %d\n", target);

    // Tomar tiempo de inicio
    clock_t inicio = clock();

    // Realizar búsqueda binaria
    int result = binarySearch(arr, SIZE, target);

    // Tomar tiempo de finalización
    clock_t fin = clock();

    // Calcular tiempo de ejecución
    double tiempo_ejecucion = (double)(fin - inicio) / CLOCKS_PER_SEC;

    // Mostrar resultado de la búsqueda (solo para verificación)
    if (result != -1) {
        printf("Elemento encontrado en índice: %d\n", result);
    } else {
        printf("Elemento no encontrado\n");
    }

    // Mostrar solo el tiempo de ejecución como solicitaste
    printf("Tiempo de ejecución: %f segundos\n", tiempo_ejecucion);

    return 0;
}