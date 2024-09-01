#include <stdio.h>     //solo, nombre en Timus es Vicente Cuello
#include <stdlib.h>

int main(){
  int n;
  do{
    scanf("%d",&n);
  }while(n<3 || 1000<n);
  int var[n];
  for(int i=0;i<n;i++){
    scanf("%d",&var[i]);
  }
  int s=var[0]+var[1]+var[2];
  int m=2;
  for(int i=1;i+3<n+1;i++){
    if(var[i]+var[i+1]+var[i+2]>s){
	    s=var[i]+var[i+1]+var[i+2];
	    m=i+2;
    }
   }
  printf("%d %d",s,m);

  return 0;

}