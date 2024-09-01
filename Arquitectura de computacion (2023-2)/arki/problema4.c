#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Secuencia de Fibonacci otorgada
long long int fibonacci(long long int *n) {
    if (*n == 1) return 0;
    if (*n == 2) return 1;

    long long int m = *n - 1;
    long long int p = *n - 2;

    return fibonacci(&m) + fibonacci(&p);
}

// Main para probar el tiempo de la función
int main() {
    long long int n = 40; // Prueba buscando el número 40 de la secuencia de Fibonacci

    clock_t start, end;

    // Medir tiempo de CPU en ciclos de reloj
    start = clock();
    long long int result = fibonacci(&n);
    end = clock();

    // Calcular el tiempo en ciclos de reloj
    long long int clock_cycles = end - start;

    printf("Resultado para n=%lld: %lld\n", n, result);
    printf("Tiempo de CPU en ciclos de reloj: %lld\n", clock_cycles);

    return 0;
}

