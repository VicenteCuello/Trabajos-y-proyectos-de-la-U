#include <stdlib.h>
#include <stdio.h>

int main(){
  int n,m;
  do{
	scanf("%d", &n);
  }while(n<1 || 100<n);           
  int var[n][n];
  m=n-1;
  for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		scanf("%d",&var[i][j]);
	}
  }
  for(int i=0;i<n;i++){
	for(int j=0;j<=i;j++){
		printf("%d ",var[i-j][j]);
	}
  }
  int cont=0;
  for(int i=n-1;i>= 0;i--){
	for(int j=1;j<=i;j++){
		printf("%d ", var[n-j][cont+j]);
	}	
	cont++;
  }
  return 0;
}