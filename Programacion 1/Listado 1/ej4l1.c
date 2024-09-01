#include <stdio.h>     //ayudado por la guia subida a canvas
#include <stdlib.h>

int main() {
  int var1,var2,var3;
  printf("Ingrese dos numeros\n");    
  scanf("%d %d",&var1,&var2);        //se ingresan los dos valores que adquiriran var1 y var2
  if(var1<0 && var2<0){          //se refiere a que solo sucedera si var1 y var2 son negativos
    var3=var1;            //var3 toma el valor de var1
    var1=var2;            //var1 toma el valor de var2 para hacer el cambio de valor
    var2=var3;            //var2 toma el valor de var3 que era el valor original de var1 para asi concluir el cambio de variable
    printf("Variante 1 es igual a %d y variante 2 es igual %d\n",var1,var2);      //ahora el valor de var1 mostrara el ingresado en var2 y viceversa
  }
  else{
    printf("Variante 1 es igual a %d y variante 2 es igual a %d\n",var1,var2);     //aqui se sigue el camino si ambos no fueran negativos, siendo var1 y var2 sus valores predeterminados
  }

  
  return 0;
}