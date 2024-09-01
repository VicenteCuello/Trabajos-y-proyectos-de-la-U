#include <stdio.h>    //solo, nombre de usuario timus es Vicente Cuello
#include <stdlib.h>  

int main() {
  int d1,d2,dif1,dif2,sum;
  scanf("%d %d",&d1,&d2);
  if((1<=d1) && (1<=d2) && (d1<=10) && (d2<=10)){
    sum=(d1+d2)-1;
    dif1=(sum-d1);
    dif2=(sum-d2);
    printf("%d %d",dif1,dif2);
  }
  return 0;
}
