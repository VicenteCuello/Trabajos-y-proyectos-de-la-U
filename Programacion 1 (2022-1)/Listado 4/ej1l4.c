#include <stdio.h>     //solo
#include <stdlib.h>
  

double operacion(char op,double v1, double v2){
  double res;
  if(op=='+'){
    res=v1+v2;
  }
  else if(op=='-'){
    res=v1-v2;
  }
  else if(op=='*'){
    res=v1*v2;
  }
  else if(op=='/'){
    res=v1/v2;
  }
  return res;
}

int main() {
  char op;
  double v1,v2;
  printf("Escriba una operacion entre dos numeros (escribalo por separado, ejemplo: 1 + 2):\n");
  scanf("%lf %s %lf",&v1,&op,&v2);
  printf("%lf",operacion(op,v1,v2));
  return 0;
}
  