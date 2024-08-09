#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
* Programa que ejecuta un ciclo for con un número máximo de iteraciones.
* El valor máximo se pasa como parámetro en la línea de comando.
* Ejemplo: ./registerEXE 10000000000
* es decir 1 x 10^10, un uno seguido de 10 ceros.
* argv[0] es el nombre del programa.
* argv[1] es el número de iteraciones.
*/
int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Forma de uso: %s ValorLong \n", argv[0]);
        return -1;
    }

    // Se usa atoll() para manejar valores grandes, ya que atol() no es suficiente para números muy grandes y se me desbordaba.
    // atoll() convierte el argumento de la línea de comando a long long int
    long long max = atoll(argv[1]);

    // Calcula el tiempo de ejecución
    clock_t t = clock();
    printf("Inicio\n");

    // Se quita la línea original que usaba 'int' porque 'int' puede desbordar al usar grandes números.
    // int n = 0; // La variable 'n' se define aquí como 'int', que no maneja bien números grandes.

    // Se usa register long long para manejar el contador de iteraciones, que puede ser muy grande.
    // 'register' sugiere al compilador que intente usar un registro para la variable, mejorando el rendimiento en algunos casos.

    // long long n = 0;
    register long long n = 0;

    for (n = 0; n < max; n++) {
        // Se añade un mensaje de progreso para monitorear la ejecución cada 1,000,000,000 iteraciones y poder ir probando el funcionamiento.

       /* if (n % 1000000000 == 0 && n != 0) {
            printf("Iteración %lld\n", n);
        } */
    }

    printf("Fin\n");

    // Calcula el tiempo  de ejecución
    t = clock() - t;

    double tiempo = ((double)t) / CLOCKS_PER_SEC; // Calcula el tiempo transcurrido

    printf("Tiempo transcurrido %f segundos\n", tiempo);

    return 0;
}



