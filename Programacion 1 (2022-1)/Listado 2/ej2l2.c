#include <stdio.h>     //solo
#include <stdlib.h>

int m1=0;
int m2=1;
int res=2;


int potencia(){
  m1=m2;
  m2=res;
  res=m1*m2;
  return res;
}
int main(){
  int n;
  int cont=0;
  do{
    switch(cont){
      default :printf("Por favor ");
      break;
    }
    printf("escriba un numero mayor a 0:\n");
    scanf("%d",&n);
    cont++;
  }while(n<=0);
  printf("1\n");
  for(int i=1;i<n;i++){
    printf("%d\n",potencia());
  }
  return 0;
  
}