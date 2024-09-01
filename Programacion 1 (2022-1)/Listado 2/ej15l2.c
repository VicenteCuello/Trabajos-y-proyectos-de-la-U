#include <stdio.h>        //solo, nombre en Timus es Vicente Cuello
#include <stdlib.h>

int main(){
  int n1,n2,n3;
  int var1[4000],var2[4000],var3[4000];
  scanf("%d",&n1);
  for(int i=0;i<n1;++i){
    scanf("%d",&var1[i]); 
  }  
  scanf("%d",&n2);
  for(int i=0;i<n2;++i){
    scanf("%d",&var2[i]);
  }
  scanf("%d",&n3);
  for(int i=0;i<n3;++i){
    scanf("%d",&var3[i]);
  }
  int cont=0;
  int j,m;
  j=0;
  m=0;
  for(int i=0;i<n1;++i){
      while((j<n2) && (var2[j]<var1[i])) 
          ++j;
      while((m<n3) && (var3[m]<var1[i])) 
          ++m;
        
      if((var2[j]==var1[i]) && (var3[m]==var1[i])){
          cont++;
      }
  }   
  printf("%d\n",cont);
  return(0);
}