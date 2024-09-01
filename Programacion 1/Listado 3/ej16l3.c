#include <stdio.h>     //solo, nombre de timus Vicente Cuello
#include <stdlib.h>
#include <math.h>     //se uso math.h para poder usar sqrt y asi poder sacar la raiz cuadrada

int main(){
 int n,m;
 long long sum;
 scanf("%d",&n);
 for(int i=0;i<n;i++){
  scanf("%d",&m);
  sum=(long long)sqrt((unsigned int)(m-1)*2);
    if(sum*(sum+1)/2+1==m){
      printf("1 ");
    }
    else{ 
      printf("0 ");
    }
  }
  
  return(0);
}