#include <stdlib.h>    //con ayuda de Nicolas Jarpa
#include <stdio.h>

int main(int argc, char const *argv[]){
  char cadena[1000];
  int  cad;
  printf("Escriba una letra, palabra o lo que quiera:\n");	
  while((cad=getchar())!='\n' ){  //se crea un ciclo para ir detectando cada elemento de la cadena de caracteres
    if(cad >= 65 && cad <= 90 ){  //si el elemento esta entre el 65 y 90 de la tabla ASCII (osea en las mayusculas)
      cad = cad + 32;             //se le sumara 32 al numero del elemento para que asi este si o si entre el 97 y 122 de la tabla ASCII (osea en las minusculas)
    }
    else if(cad >= 97 && cad <= 122){    //si el elemento esta entre el 97 y 122 de la tabla ASCII (osea en las minusculas)
      cad = cad - 32;}                   //se le restara 32 al numero del elemento para que asi este si o si entre el 65 y 90 de la tabla ASCII (osea en las mayusculas)
      printf("%c", cad);                 //se imprime las cadena de carecteres con estos cambiados
    }
  return 0;
}