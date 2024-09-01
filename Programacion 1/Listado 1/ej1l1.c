#include <stdio.h>
#include <stdlib.h>       //solo

int main(){
  int n;
  printf("Ingrese un numero\n");
  scanf("%d",&n);
  if ((n%2)==0){
    printf("%d es divisible por 2\n",n);
  }
  if ((n%3)==0){
    printf("%d es divisible por 3\n",n);
  }
  if ((n%4)==0){
    printf("%d es divisible por 4\n",n);
  }
  if ((n%5)==0){
    printf("%d es divisible por 5\n",n);
  }
  if ((n%6)==0){
    printf("%d es divisible por 6\n",n);
  }
  if ((n%7)==0){
    printf("%d es divisible por 7\n",n);
  }
  if ((n%8)==0){
    printf("%d es divisible por 8\n",n);
  }
  if ((n%9)==0){
    printf("%d es divisible por 9\n",n);
  }
  if ((n%10)==0){
    printf("%d es divisible por 10\n",n);
  }
  return 0;
}
