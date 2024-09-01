#include <stdio.h>     //solo
#include <stdlib.h>


long long mcd(long long n1, long long n2){
  long long cond;
  cond=(n1<n2? n1:n2);
  long long div=1;
  int i;
  for(i=2;i<=cond;i++){
    if(n1%i==0 && n2%i==0){
      div=i;
    }
  }
  return div;
}

int main(){
  long long n1,n2;
  printf("Ingrese dos numeros:\n");
  scanf("%lld %lld",&n1,&n2);
  long long d = mcd(n1,n2);
  printf("Su MCD es %lld",d);
  return 0;
}