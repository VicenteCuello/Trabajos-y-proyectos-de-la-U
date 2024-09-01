#include <stdio.h>        //solo
#include <stdlib.h>

int main() {
  int n;
  scanf("%d",&n);
  if(0<=n && n<=255){
    printf("Caracter es %c\n",n);
    printf("El entero sin signo es %d\n",n);
    printf("El numero octal es %o\n",n);
    printf("El numero hexadecimal es %x\n",n);
  }
  
  
  return 0;
}
  