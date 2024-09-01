#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef double data_t;

typedef struct {
    long int len;
    data_t *data;
} vec_rec, *vec_ptr;

#define vec_length(v) ((v).len)
#define get_vec_element(v, index, dest) (*(dest) = (v).data[(index)])

// Versión no optimizada de combine1
void combine1(vec_ptr v, data_t *dest) {
    long int i;
    *dest = 0;
    for (i = 0; i < vec_length(*v); i++) {
        data_t val;
        get_vec_element(*v, i, &val);
        *dest = *dest + val;
    }
}

// Versión optimizada combine5 con loop unrolling y 4 operaciones por ciclo
void combine5(vec_ptr v, data_t *dest) {
    long int i;
    long int length = vec_length(*v);
    long int limit = length - 3;  // Ajustar el límite del loop unrolling

    *dest = 0;

    // Desenrollado del bucle con 4 operaciones por ciclo
    for (i = 0; i < limit; i += 4) {
        data_t val0, val1, val2, val3;
        get_vec_element(*v, i, &val0);
        get_vec_element(*v, i + 1, &val1);
        get_vec_element(*v, i + 2, &val2);
        get_vec_element(*v, i + 3, &val3);

        *dest = *dest + val0 + val1 + val2 + val3;
    }

    // Sumar los elementos restantes (si el tamaño no es múltiplo de 4)
    for (; i < length; i++) {
        data_t val;
        get_vec_element(*v, i, &val);
        *dest = *dest + val;
    }
}

// Función para realizar pruebas y comparaciones
void run_tests(long int size) {
    vec_rec v;
    v.len = size;
    v.data = (data_t *)malloc(size * sizeof(data_t));
    for (long int i = 0; i < size; i++) {
        v.data[i] = rand() % 100;
    }

    clock_t start, end;
    unsigned long long cycles_combine1, cycles_combine5;
    data_t resultado_combine1, resultado_combine5;

    // Medición del tiempo para la versión combine1
    start = clock();
    combine1(&v, &resultado_combine1);
    end = clock();
    cycles_combine1 = end - start;
    printf("Resultado (combine1): %f\n", resultado_combine1);
    printf("Ciclos de reloj (combine1): %llu\n", cycles_combine1);

    // Medición del tiempo para la versión combine5
    start = clock();
    combine5(&v, &resultado_combine5);
    end = clock();
    cycles_combine5 = end - start;
    printf("Resultado (combine5): %f\n", resultado_combine5);
    printf("Ciclos de reloj (combine5): %llu\n", cycles_combine5);

    // Comparación de ciclos de reloj
    if (cycles_combine1 < cycles_combine5) {
        printf("combine1 es más rápido que combine5.\n");
    } else if (cycles_combine1 > cycles_combine5) {
        printf("combine5 es más rápido que combine1.\n");
    } else {
        printf("combine1 y combine5 tienen tiempos de ejecución similares.\n");
    }

    // Liberar memoria
    free(v.data);
}

int main() {
    // Realizar pruebas con diferentes tamaños de vector
    long int size1 = 100000;
    long int size2 = 500000;
    long int size3 = 1000000;

    printf("Pruebas con size = %ld:\n", size1);
    run_tests(size1);

    printf("\nPruebas con size = %ld:\n", size2);
    run_tests(size2);

    printf("\nPruebas con size = %ld:\n", size3);
    run_tests(size3);

    return 0;
}

