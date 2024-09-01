#include <stdlib.h>     //con ayuda de Nicolas Jarpa
#include <stdio.h>
#include <string.h>     //se uso string.h para poder usar strcmp que es para comparar cadenas

int main(){
  char cad[1000];
  char mat[100][100];
  int i,j,aux;
  aux=0;
  printf("Escriba los numeros de las cadenas (recuerde escribirlo como 2xN1 3xN2 tomando N1 y N2 lo que usted quiera):\n");
  fgets(cad,1000,stdin);
  for(i=0;i<=(strlen(cad));i++){
    if(cad[i]== ' ' || cad[i]== '\0' || cad[i] =='x' ){       //si el valor en la cadena es nada,x o el ultimo valor de la cadena, en columna 0 de la matriz, aumentara el numero de filas, haciendo referencia al numero de caracteres
      mat[aux][j]='\0';
      aux++;  
      j=0;    
    }
    else{
      mat[aux][j]=cad[i];                                   //para los demas valores, cada columna ir tomando un valor de cad[i]
      j++;
    }
  }
 
  if(strcmp(mat[1],mat[3])>0){    //si el valor que esta en 3xN2 es menor al de 2xN1, imprimira este
    printf("%s es el menor\n", mat[3]);
  }
  if(strcmp(mat[1],mat[3])<0){    //si el valor que esta en 2xN1 es menor al de 3xN2, imprimira este
    printf("%s es el menor\n",mat[1]);
  }

  return 0;
} 