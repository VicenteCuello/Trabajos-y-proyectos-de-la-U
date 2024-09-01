#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Secuencia de Fibonacci optimizada
long long int fibonacci_optimizado(long long int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;

    long long int a = 0, b = 1, c, d;
    n -= 2;  // Para ajustar el índice y evitar las primeras dos iteraciones

    // Loop unrolling con 4 operaciones por ciclo y paralelismo de 4 vías
    while (n >= 4) {
        c = a + b;
        d = b + c;
        a = c + d;
        b = d + a;
        n -= 4;
    }

    // Iteraciones restantes
    while (n > 0) {
        c = a + b;
        a = b;
        b = c;
        n--;
    }

    return b;
}

int main() {
    long long int n = 40; // Prueba buscando el número 40 de la secuencia de Fibonacci

    clock_t start, end;

    // Medir tiempo de CPU en ciclos de reloj
    start = clock();
    long long int result = fibonacci_optimizado(n);
    end = clock();

    // Calcular el tiempo en ciclos de reloj
    long long int clock_cycles = end - start;

    printf("Resultado para n=%lld: %lld\n", n, result);
    printf("Tiempo de CPU en ciclos de reloj: %lld\n", clock_cycles);

    return 0;
}

