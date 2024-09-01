#include <stdio.h>      //solo
#include <stdlib.h>


long long mcm(long long n1, long long n2){
  long long cond;
  cond=(n2<n1? n1:n2);
  long long mult;
  mult=n1*n2;
  int i;
  for(i=cond;i<=mult;i++){
    if(i%n1==0 && i%n2==0){
      return i;
    }
  }
}

int main(){
  long long n1,n2;
  printf("Ingrese dos numeros:\n");
  scanf("%lld %lld",&n1,&n2);
  long long m = mcm(n1,n2);
  printf("Su MCM es %lld",m);
  return 0;
  
}