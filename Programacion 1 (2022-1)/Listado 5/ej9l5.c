#include <stdio.h>
#include <stdlib.h> //con ayuda de Pedro Gajardo

int busquedaBinaria(int *v, int elem, int limInferior, int limSuperior){
    int aux = -1;                       //tomamos un aux que tenga valor -1
    if (limInferior <= limSuperior){    //para que se cumpla lo que buscamos, limInferior tiene que ser menor o igual a limSuperio
        if (v[limInferior] == elem)                       
            return limInferior;         //si limInferior es igual al elemento, entonces se imprime la posicion limInferior                   
        aux = busquedaBinaria(v, elem, limInferior + 1, limSuperior); //aux va ir buscando el elem aumentando poco a poco
                                                                      //el valor de limInferior hasta encontrarlo
    }
    else                
        return aux;  //se imprimer el valor de aux
}