#include <stdio.h>     //solo, nombre en Timus es Vicente Cuello
#include <stdlib.h>

int main(){
  int n,s;
  scanf("%d",&n);
  s=0;
  if(n<=0){
    s=(((n-1)*n)/2)*(-1);
    s=s+1;
  }
  else{
    s=(((n+1)*n)/2);
  }
  printf("%d",s);
  return 0;
}