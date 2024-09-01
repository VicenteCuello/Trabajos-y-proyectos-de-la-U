#include <stdio.h>     //solo
#include <stdlib.h>

int main() {
  int n1,n2,n3;
  printf("Escriba tres numeros\n");
  scanf("%d %d %d",&n1,&n2,&n3);
  if(((n1%2)==0) && ((n2%2)==0) && ((n3%2)==0)){
    printf("Uniforme\n");
  }
  else if(((n1%2)!=0) && ((n2%2)!=0) && ((n3%2)!=0)){
    printf("Uniforme\n");
  }
  else{
    printf("Variadito\n");
  }
    
    return 0;
}
  