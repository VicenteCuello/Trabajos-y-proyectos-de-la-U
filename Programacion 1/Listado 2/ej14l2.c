#include <stdlib.h>         //solo, nombre en Timus es Vicente Cuello
#include <stdio.h>

int main(){
  int n,k;
  do{
	scanf("%d %d",&n,&k);
  }while(n<1 || 10000<k);
  int var[n];
  int b,d;
  b=0;
  d=0;
  for (int i=0;i<n;i++){
	scanf("%d",&var[n]);
	if((k-var[n])<0){
		b=b+(var[n]-k);
	}
        if(0<(k-var[n])){
		d=d+(k-var[n]);
	}
  }
  printf("%d %d",b,d);
  return 0;
}