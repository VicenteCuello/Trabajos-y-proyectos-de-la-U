#include <stdio.h>     //solo
#include <stdlib.h>

int main() {
  char n;
  printf("Escriba SOLO UN caracter:\n");
  scanf("%c",&n);
  if(65<=n && n<=90){
    printf("Es mayuscula\n");
  }
  else if(97<=n && n<=122){
    printf("Es minuscula\n");
  }
  else if(48<=n && n<=57){
    printf("Es un numero\n");
  }
  else{
    printf("Otro\n");
  }
  return 0;
}