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

// Versión optimizada combine6 con loop unrolling y 4 operaciones por ciclo
void combine6(vec_ptr v, data_t *dest) {
    long int i;
    long int length = vec_length(*v);
    long int limit = length - 3;  // Ajustar el límite del loop unrolling

    *dest = 0;

    // Loop Unrolling con 4 operaciones por ciclo con paralelismo de 4 vías
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

// Función para realizar pruebas
void run_tests(long int size) {
    vec_rec v;
    v.len = size;
    v.data = (data_t *)malloc(size * sizeof(data_t));
    for (long int i = 0; i < size; i++) {
        v.data[i] = rand() % 100;
    }

    clock_t start, end;
    unsigned long long cycles_combine6;
    data_t resultado_combine6;

    // Medición del tiempo para la versión combine6
    start = clock();
    combine6(&v, &resultado_combine6);
    end = clock();
    cycles_combine6 = end - start;
    printf("Resultado (combine6): %f\n", resultado_combine6);
    printf("Ciclos de reloj (combine6): %llu\n", cycles_combine6);

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


