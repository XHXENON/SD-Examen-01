#include <stdio.h>
#include <stdlib.h>  // Para rand() y srand()
#include <time.h>    // Para time() y clock()

int main() {
    int res = 0;
    int arr[1];  // Arreglo con solo 1 elemento
    int i = 0;
    int iteracion = 0;
    for(iteracion=0; iteracion<5; iteracion++){
    	// Se hace una estampa de tiempo para la semilla de aleatoriedad
    	srand(time(NULL));
    	// Llenar el array con un número aleatorio
    	arr[0] = rand() % 100;   // Un solo número entre 0 y 99
	    // Se toma el tiempo de inicio
	    clock_t inicio = clock();
	    // Se crea un for que procesa solo un elemento
	    for(res = 0; res < 1; res++) {
	        volatile int temp = arr[res];  // Evita optimización del compilador
	    }
	    // Se toma el tiempo de finalización
	    clock_t fin = clock();
	    // Se crea una variable que guarde el tiempo de ejecución
	    double tiempo_ejecucion = (double)(fin - inicio) / CLOCKS_PER_SEC;
	    // Se imprime el tiempo de ejecución
	    printf("Tiempo de ejecucion de la iteracion %d: %.15f segundos\n", iteracion+1, tiempo_ejecucion);
	}
    return 0;
}

