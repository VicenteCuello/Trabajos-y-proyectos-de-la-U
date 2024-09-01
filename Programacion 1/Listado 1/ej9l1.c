#include <stdio.h>    //solo
#include <stdlib.h>

int main() {
   int x1,x2,x3,y1,y2,y3;
  printf("Digame 3 coordenadas en x,y (escribe primero el x de la primera coordenada,despues su y, despues el x de la segunda coordenada y asi como sigue)\n");
  scanf("%d %d %d %d %d %d)",&x1,&y1,&x2,&y2,&x3,&y3);
  if(x1<=x3 && x3<=x2 && y1<=y3 && y3<=y2){
    printf("Contenido\n");
  }
  else if(x2<=x3 && x3<=x1 && y1<=y3 && y3<=y2){
    printf("Contenido\n");
  }
  else if(x1<=x3 && x3<=x2 && y2<=y3 && y3<=y1){
    printf("Contenido\n");
  }
  else if(x2<=x3 && x3<=x1 && y2<=y3 && y3<=y1){
    printf("Contenido\n");
  }
  else{
    printf("No contenido\n");
  }

 

  return 0;
}
  