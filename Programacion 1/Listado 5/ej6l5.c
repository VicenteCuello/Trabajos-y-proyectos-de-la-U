#include <stdio.h>
#include <stdlib.h>  //con ayuda de Pedro Gajardo

int cuentaRepeticiones(char *palabra, int tam, char c){
    int cont = 0;      //creamos un contador
    if(tam - 1 >= 0){                 //como la cadena es un tipo de arreglo, empieza desde el 0 hasta su valor maximo menos uno
        if(palabra[tam - 1] == c)   //si se detecta el caracter en la cadena, el contador aumentara su valor
            cont++;  
        cont = cuentaRepeticiones(palabra,tam -1,c) + cont;   //iremos bajando posiciones en la cadena para seguir buscando en donde el caracter
                                                              //se repite y asi aumentara el valor del contador
    }
    return cont;  //regresamos el valor final que adquiere el contandor
}