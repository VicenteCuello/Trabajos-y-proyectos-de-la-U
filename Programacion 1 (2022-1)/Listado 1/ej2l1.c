#include <stdio.h>
#include <stdlib.h>      //solo

int main(){
  int v1, v2,v12,v22;
  printf("Ingrese dos numeros enteros\n");
  scanf("%d %d",&v1,&v2);
  if(v1<v2){
    v12=v1*2;
    printf("%d es el doble de %d\n",v12,v1);
  }
  else{
    if(v2<v1){
      v22=v2*2;
      printf("%d es el doble de %d\n",v22,v2);
    }
    else{
      printf("Error\n");
    }
    }
  return 0;
  }
