#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Procedimiento no optimizado para invertir una cadena de caracteres
void invertir(char *s) {
    int longitud = strlen(s);
    int i, j;
    char temp;

    for (i = 0, j = longitud - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

// Función para medir el tiempo de ejecución del procedimiento invertir
clock_t medir_tiempo_ciclos(char *cadena) {
    clock_t inicio, fin;

    // Crear una copia de la cadena original
    char *copia_cadena = strdup(cadena);

    inicio = clock();
    invertir(copia_cadena);
    fin = clock();

    // Liberar la memoria de la copia
    free(copia_cadena);

    return fin - inicio;
}


int main() {
    // Pruebas con diferentes tamaños de cadenas
    char cadena1[] = "Scuderia Ferrari";
    char *copia_cadena1 = strdup(cadena1);
    invertir(copia_cadena1);
    char cadena2[] = "Alexis Sanchez";
    char *copia_cadena2 = strdup(cadena2);
    invertir(copia_cadena2);
    char cadena3[] = "The Finals el mejor juego";
    char *copia_cadena3 = strdup(cadena3);
    invertir(copia_cadena3);
    char cadena4[1000]; // Cadena de tamaño 1000
    char cadena5[10000]; // Cadena de tamaño 10000
    char cadena6[100000]; // Cadena de tamaño 100000

    // Generar cadenas aleatorias para las pruebas
    srand(time(NULL));
    for (int i = 0; i < sizeof(cadena4) - 1; i++) {
        cadena4[i] = 'A' + rand() % 26; // Letras mayúsculas aleatorias
    }
    cadena4[sizeof(cadena4) - 1] = '\0';

    for (int i = 0; i < sizeof(cadena5) - 1; i++) {
        cadena5[i] = 'A' + rand() % 26; // Letras mayúsculas aleatorias
    }
    cadena5[sizeof(cadena5) - 1] = '\0';
     for (int i = 0; i < sizeof(cadena6) - 1; i++) {
        cadena6[i] = 'A' + rand() % 26; // Letras mayúsculas aleatorias
    }
    cadena6[sizeof(cadena6) - 1] = '\0';


    printf("\nPrueba con cadena1:\n");
    printf("Cadena original: %s\n", cadena1);
    printf("Cadena invertida: %s\n", copia_cadena1);
    clock_t ciclos_cadena1 = medir_tiempo_ciclos(cadena1);
    printf("Ciclos de reloj: %ld\n", ciclos_cadena1);

    printf("\nPrueba con cadena2:\n");
    printf("Cadena original: %s\n", cadena2);
    printf("Cadena invertida: %s\n", copia_cadena2);
    clock_t ciclos_cadena2 = medir_tiempo_ciclos(cadena2);
    printf("Ciclos de reloj: %ld\n", ciclos_cadena2);

    printf("\nPrueba con cadena3:\n");
    printf("Cadena original: %s\n", cadena3);
    printf("Cadena invertida: %s\n", copia_cadena3);
    clock_t ciclos_cadena3 = medir_tiempo_ciclos(cadena3);
    printf("Ciclos de reloj: %ld\n", ciclos_cadena3);

    printf("\nPrueba con cadena4:\n");
    clock_t ciclos_cadena4 = medir_tiempo_ciclos(cadena4);
    printf("Ciclos de reloj: %ld\n", ciclos_cadena4);

    printf("\nPrueba con cadena5:\n");
    clock_t ciclos_cadena5 = medir_tiempo_ciclos(cadena5);
    printf("Ciclos de reloj: %ld\n", ciclos_cadena5);

    printf("\nPrueba con cadena6:\n");
    clock_t ciclos_cadena6 = medir_tiempo_ciclos(cadena6);
    printf("Ciclos de reloj: %ld\n", ciclos_cadena6);

    return 0;
}



