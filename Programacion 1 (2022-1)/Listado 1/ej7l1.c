#include <stdio.h>    //solo
#include <stdlib.h>

int main() {
  int n1,n2,n3,n4;
  printf("Escribe cuatro numeros\n");
  scanf("%d %d %d %d",&n1,&n2,&n3,&n4);
  if(n1<n2 && n2<n3 && n3<n4){
    printf("En orden de menor a mayor seria %d %d %d %d\n",n1,n2,n3,n4);
  }
  else if(n1<n3 && n3<n2 && n2<n4){
    printf("En orden de menor a mayor seria %d %d %d %d\n",n1,n3,n2,n4);
  }
  else if(n1<n3 && n3<n4 && n4<n2){
    printf("En orden de menor a mayor seria %d %d %d %d\n",n1,n3,n4,n2);
  }
  else if(n1<n4 && n4<n3 && n3<n2){
    printf("En orden de menor a mayor seria %d %d %d %d\n",n1,n4,n3,n2);
  }
  else if(n1<n2 && n2<n4 && n4<n3){
    printf("En orden de menor a mayor seria %d %d %d %d\n",n1,n2,n4,n3);
  }
  else if(n1<n4 && n4<n2 && n2<n3){
    printf("En orden de menor a mayor seria %d %d %d %d\n",n1,n4,n2,n3);
  }
  else if(n2<n1 && n1<n3 && n3<n4){
    printf("En orden de menor a mayor seria %d %d %d %d\n",n2,n1,n3,n4);
  }
  else if(n2<n1 && n1<n4 && n4<n3){
    printf("En orden de menor a mayor seria %d %d %d %d\n",n2,n1,n4,n3);
  }
  else if(n2<n3 && n3<n1 && n1<n4){
    printf("En orden de menor a mayor seria %d %d %d %d\n",n2,n3,n1,n4);
  }
  else if(n2<n3 && n3<n4 && n4<n1){
    printf("En orden de menor a mayor seria %d %d %d %d\n",n2,n3,n4,n1);
  }
  else if(n2<n4 && n4<n1 && n1<n3){
    printf("En orden de menor a mayor seria %d %d %d %d\n",n2,n4,n1,n3);
  }
  else if(n2<n4 && n4<n3 && n3<n1){
    printf("En orden de menor a mayor seria %d %d %d %d\n",n2,n4,n3,n1);
  }
  else if(n3<n1 && n1<n2 && n2<n4){
    printf("En orden de menor a mayor seria %d %d %d %d\n",n3,n1,n2,n4);
  }
  else if(n3<n1 && n1<n4 && n4<n2){
    printf("En orden de menor a mayor seria %d %d %d %d\n",n3,n1,n4,n2);
  }
  else if(n3<n2 && n2<n1 && n1<n4){
    printf("En orden de menor a mayor seria %d %d %d %d\n",n3,n2,n1,n4);
  }
  else if(n3<n2 && n2<n4 && n4<n1){
    printf("En orden de menor a mayor seria %d %d %d %d\n",n3,n2,n4,n1);
  }
  else if(n3<n4 && n4<n1 && n1<n2){
    printf("En orden de menor a mayor seria %d %d %d %d\n",n3,n4,n1,n2);
  }
  else if(n3<n4 && n4<n2 && n2<n1){
    printf("En orden de menor a mayor seria %d %d %d %d\n",n3,n4,n2,n1);
  }
  else if(n4<n1 && n1<n2 && n2<n3){
    printf("En orden de menor a mayor seria %d %d %d %d\n",n4,n1,n2,n3);
  }
  else if(n4<n1 && n1<n3 && n3<n2){
    printf("En orden de menor a mayor seria %d %d %d %d\n",n4,n1,n3,n2);
  }
  else if(n4<n2 && n2<n1 && n1<n3){
    printf("En orden de menor a mayor seria %d %d %d %d\n",n4,n2,n1,n3);
  }
  else if(n4<n2 && n2<n3 && n3<n1){
    printf("En orden de menor a mayor seria %d %d %d %d\n",n4,n2,n3,n1);
  }
  else if(n4<n3 && n3<n1 && n1<n2){
    printf("En orden de menor a mayor seria %d %d %d %d\n",n4,n3,n1,n2);
  }
  else if(n4<n3 && n3<n2 && n2<n1){
    printf("En orden de menor a mayor seria %d %d %d %d\n",n4,n3,n2,n1);
  }
    
    return 0;
}