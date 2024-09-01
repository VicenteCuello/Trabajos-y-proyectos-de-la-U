#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Versión optimizada 1: Uso de punteros para iterar y realizar intercambio
void invertir_optimizado_1(char *s) {
    int longitud = strlen(s);
    char *inicio = s;
    char *fin = s + longitud - 1;

    while (inicio < fin) {
        // Intercambiar los caracteres apuntados por inicio y fin
        char temp = *inicio;
        *inicio = *fin;
        *fin = temp;

        // Mover los punteros hacia el centro
        inicio++;
        fin--;
    }
}

// Versión optimizada 2: Utilizando XOR para el intercambio de caracteres
void invertir_optimizado_2(char *s) {
    int longitud = strlen(s);

    for (int i = 0, j = longitud - 1; i < j; i++, j--) {
        s[i] = s[i] + s[j] - (s[j] = s[i]);
    }
}

// Versión optimizada 3: Invertir utilizando punteros y un bucle con loop unrolling
void invertir_optimizado_3(char *s) {
    char *inicio = s;
    char *fin = s + strlen(s) - 1;

    while (inicio < fin) {
        *inicio = *inicio + *fin - (*fin = *inicio);
        inicio++;
        fin--;
    }
}

// Función para medir el tiempo de ejecución de un procedimiento invertir en ciclos de reloj
void medir_tiempo_ciclos(void (*invertir_func)(char *), const char *cadena) {
    // Crear una copia de la cadena original
    char *copia_cadena = strdup(cadena);

    clock_t inicio, fin;

    inicio = clock();
    invertir_func(copia_cadena);
    fin = clock();

    printf("Cadena original: %s\n", cadena);
    printf("Cadena invertida: %s\n", copia_cadena);
    printf("Ciclos de reloj: %ld\n", fin - inicio);

    // Liberar la memoria de la copia
    free(copia_cadena);
}

// Se crea otra funcion de medir tiempo (es igual a la anterior) para que asi no imprima las cadenas originales y invertidas que son demasiado grandes
void medir_tiempo_ciclos2(void (*invertir_func)(char *), const char *cadena) {
    // Crear una copia de la cadena original
    char *copia_cadena = strdup(cadena);

    clock_t inicio, fin;

    inicio = clock();
    invertir_func(copia_cadena);
    fin = clock();

    printf("Ciclos de reloj: %ld\n", fin - inicio);

    // Liberar la memoria de la copia
    free(copia_cadena);
}

int main() {
    char cadena[100000]; // Cadena de tamaño 100000
    srand(time(NULL));
    for (int i = 0; i < sizeof(cadena) - 1; i++) {
        cadena[i] = 'A' + rand() % 26; // Letras mayúsculas aleatorias
    }
    cadena[sizeof(cadena) - 1] = '\0';
    char cadena2[] = "Alexis Sanchez";

    printf("Prueba con invertir_optimizado_1:\n");
    medir_tiempo_ciclos(invertir_optimizado_1, cadena2);

    printf("\nPrueba con invertir_optimizado_2:\n");
    medir_tiempo_ciclos(invertir_optimizado_2, cadena2);

    printf("\nPrueba con invertir_optimizado_3:\n");
    medir_tiempo_ciclos(invertir_optimizado_3, cadena2);



    printf("\nPrueba con invertir_optimizado_1:\n");
    medir_tiempo_ciclos2(invertir_optimizado_1, cadena);

    printf("\nPrueba con invertir_optimizado_2:\n");
    medir_tiempo_ciclos2(invertir_optimizado_2, cadena);

    printf("\nPrueba con invertir_optimizado_3:\n");
    medir_tiempo_ciclos2(invertir_optimizado_3, cadena);

    return 0;
}

