#include <stdio.h>        //con ayuda de Maximiliano López, nombre timus Vicente Cuello
#include <stdlib.h>
#include <string.h>       //se hizo el uso de la biblioteca string.h para poder usar strlen

int main(){
 char nombre[20];    
 int n, g, gt;
 g=200;             //se le asigna 200 a g porque si o si la pareja que se casa va a pagar su cena
 gt=0;              //valor inicial del gasto total
 scanf("%d", &n);
 for(int i=0;i<n;i++){
    scanf("%s", nombre);
    if(nombre[strlen(nombre)-4]=='+'){  //se usa strlen para devolver la longitud de una cadena de caracteres, asi en este caso te detecta que haya un + y despues de ese + otros tres cararcteres (osea para cuando escribas +one, haciendo un total de cuatro caracteres)
        g=g+200;                        //si detecta esto, a g se le sumara 200 cada ves que esto ocurra            
    }
    else{                                  
        g=g+100;                        //si es solo el nombre sin el +one, vera que viene solo una persona y se le sumara solo 100
    }
  }
 gt=gt+g;                               //gt adquiere el valor total de g
 if(gt==1300){                          //en el caso de que gt=1300 (que significa que hay 13 persona contando a los novios) se le sumara 100 
    gt=gt+100;
  }
  printf("%d",gt);
  
  return (0);
}   