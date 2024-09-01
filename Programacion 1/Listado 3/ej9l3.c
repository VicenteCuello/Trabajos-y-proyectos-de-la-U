#include <stdlib.h>        //con ayuda de Nicolas Jarpa
#include <stdio.h>
#include <math.h>     //se uso math.h para asi poder usar modf y asi poder separar el entero del numero de la parte decimal

int main(){    
 double n,entera,decimal;
 int aux=0;
 printf("Ingrese un numero decimal\n");
 scanf("%lf",&n);
 decimal=modf(n,&entera); // se separa la parte entera y la parte decimal
 aux=decimal*1000000;
  if(aux<500000){
    printf("El numero aproximado es %f\n",entera);        //si la parte decimal es menor a 0.5 entonces la parte entera se queda igual
  }
  if(500000<=aux){
    printf("El numero aproximado es %f\n",entera+1);      //si la parte decimal es mayor o igual a 0.5, entonces el valor del entero sera la sucesion del entero original
  }

return 0;


}