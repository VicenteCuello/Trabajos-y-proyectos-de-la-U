#include <stdlib.h>         //solo, nombre en Timus es Vicente Cuello
#include <stdio.h>

int main(){
  int k,n;
  do{
	scanf("%d %d",&k,&n);              
  }while(k<1 || 100<k || n<1 || 100<n);       
  int var[n];
  for(int i=0;i<n;i++){
	scanf("%d",&var[i]);
  }
  int m;
  for(int i=0;i<n-1;i++){
        if(var[i]-k>0){
	  m=var[i]-k;
	  var[i+1]=var[i+1]+m;
	}
  }
  int res;
  res=var[n-1]-k;
  if(res<=0){
  printf("0");
  }
  else{
    printf("%d",res);
  }
  return 0;
}