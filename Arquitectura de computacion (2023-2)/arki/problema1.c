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
    long int limit = length - 3;  // Ajustar el limite del loop unrolling

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

int main() {
    // Crear un vector de ejemplo
    long int size = 10;
    vec_rec v;
    v.len = size;
    v.data = (data_t *)malloc(size * sizeof(data_t));

    // Inicializar el vector con datos de ejemplo
    for (long int i = 0; i < size; i++) {
        v.data[i] = i + 1;
    }

    // Llamar a la función combine1
    data_t result_combine1;
    combine1(&v, &result_combine1);
    printf("Resultado combine1: %f\n", result_combine1);

    // Llamar a la función combine5
    data_t result_combine5;
    combine5(&v, &result_combine5);
    printf("Resultado combine5: %f\n", result_combine5);

    // Liberar la memoria del vector
    free(v.data);

    return 0;
}


