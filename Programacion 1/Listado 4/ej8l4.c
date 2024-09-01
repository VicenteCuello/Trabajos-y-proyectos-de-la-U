#include <stdlib.h>     //con ayuda de Maximiliano Lopez
#include <stdio.h>
#include <string.h>

char palindromo(char* cadena1){       //se crea la funcion que pide el ejercicio
int l=strlen(cadena1);              //se calcula el numero de caracteres de la cadena
if (l<=1){                   //se ve el caso en el que solo se introduzca una letra
    printf("1");
    }
int palo=0;
int i=0, f=l-1;
    while((cadena1[i]==cadena1[f])&&(cadena1[i]!='/0')){        //se crea para el para el cual se se vi la cadena es igual al revez
        if(i>=f){
            palo=1;
        }
        i++;
        f--;
    }
    
    if(palo==1){                                    //si es igual al revez, se imprime 1
        printf("1");
    }else{
        printf("0");                              //si no, entonces 0
    }

}
int main(){
char cadena1[50];                            //se crea la cadena
printf("Escriba una frase o texto:");       //se pide los valores de la cadena
scanf("%s",&cadena1);
char palito=palindromo(&cadena1);          //se aplica la funcion de antes a la cadena
    return(0);
}
  