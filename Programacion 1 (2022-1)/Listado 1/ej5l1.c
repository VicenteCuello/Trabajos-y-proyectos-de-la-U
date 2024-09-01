#include <stdio.h>     //solo
#include <stdlib.h>

int main() {
  int n1,n2,n3;
  printf("Escriba tres numeros\n");
  scanf("%d %d %d",&n1,&n2,&n3);
  if(n1<0){
    if((n2>0) && (n3>0)){
      printf("Al menos uno\n");
    }
    if((n2<0) && (n3>0)){
      printf("Al menos dos\n");
    }
    if((n2>0) && (n3<0)){
      printf("Al menos dos\n");
    }

  }
  if(n2<0){
    if((n1>0) && (n3>0)){
      printf("Al menos uno\n");
    }
    if((n1>0) && (n3<0)){
      printf("Al menos dos\n");
    }

  }
  if(n3<0){
    if((n2>0) && (n1>0)){
      printf("Al menos uno\n");
    }

  }
  if((n1<0)&&(n2<0)&&(n3<0)){
    printf("Todos\n");
  }
  if((n1>0)&&(n2>0)&&(n3>0)){
    printf("Ninguno\n");
  }


  return 0;

}