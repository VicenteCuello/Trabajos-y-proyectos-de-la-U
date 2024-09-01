#include <stdio.h>      //solo
#include <stdlib.h>

int main() {
  int n;
  int cont=0;
  do{
    switch(cont){
      case 0: printf("Escriba un numero entero:\n");
      break;
      default: printf("Por favor,asegurese que el numero ingresado sea mayor a 1:\n");
    }
    scanf("%d",&n);
    cont++;
  }while(n<=1);
  if((n%2==0 && n!=2) || (n%3==0 && n!=3) || (n%5==0 && n!=5) || (n%7==0 && n!=7)){
    printf("compuesto\n");
  }
  else{
    printf("primo\n");
  }
  
  return 0;
}
