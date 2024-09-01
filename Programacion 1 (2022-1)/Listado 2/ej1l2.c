#include <stdio.h>    // con ayuda del siguiente video https://www.youtube.com/watch?v=UMy9vD0wGxo
#include <stdlib.h>

int num1;
int num2=1;
int res=0;

int secuencia() {     //se hizo un main aparte para dejar la operacion aqui y despues ponerla en el main
  num1=num2;         //n toma el valor de 1 que va ascendiendo del valor de i y los valores que num 2 adquiere despues (1,0,1,1,2...)
  num2=res;          //num2 adquiere el valor de res (que en un principio es 0) para que despes el num2 tenga un valor distinto para que se cumpla la secuencia (0,1,1,2,3,...)
  res=num1 + num2;   //num1 tiene el valor original de num2 y num2 tendra el primer valor que tiene res (primero es 0 y despues va aumentando hasta que se cumpla n veces) para darnos un nuevo valor de res que se utilizara en la salida y para el nuevo ciclo
  return res;         //vuelve a realizar la operacion las veces que pida n
}
int main(){
  int n;
  int cont=0;
  do{
    switch(cont){
      default :printf("Por favor escriba un numero mayor a 0:\n");  //se verifica la entra para que n sea mayor que 0
      break;
    }
    scanf("%d",&n);
    cont++;
  }while(n<=0);
  for(int i=0;i<n;i++){     //se crea un for para que despues se imprima la cantidad de n valores
    printf("%d\n",secuencia());   //se imprime el main de arriba que contiene la operacion tomando valores de i
  }
}
  