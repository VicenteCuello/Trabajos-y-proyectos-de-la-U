#include <stdio.h>      //solo
#include <stdlib.h>

int main(){
  int n1,n2,n3;
  printf("Ingrese tres numeros\n");
  scanf("%d %d %d",&n1,&n2,&n3);
  if(n1+n2<(n3/n1)*(n3/n1)){
    printf("Cumple invariante\n");
  }
  else{
    printf("No cumple invariante\n");
  }
  return 0;
}
