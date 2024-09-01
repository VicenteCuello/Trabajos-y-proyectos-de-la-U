#include <stdio.h>       //con ayuda de Nicolas Jarpa
#include <stdlib.h>

int main(){
  unsigned int n;
  unsigned char c1,c2,c3,c4,n1,n2,n3,n4;
  printf("Ingrese un numer0:\n");     
  scanf("%d", &n);
  n1=n;             //el primero almacenara hasta el numero 255 (que es lo que cabe) en un byte, cuando se pase de 255 se reinicia
  n2=(n>>8);        //el primero al pasarse de 255 empezara a almacenar de a poco en el segundo valor, y cuando este pase 255 empezara a almacenar en el siguiente y se reiniciara
  n3=(n>>16);       //el segundo al pasarse de 255 empezara a almacenar de a poco en el tercer valor, y cuando este pase 255 empezara a almacenar en el siguiente y se reiniciara
  n4=(n>>24);       //el segundo al pasarse de 255 empezara a almacenar de a poco en el tercer valor, y como era de 4 bytes solo hasta aqui llegamos
  c1=n1;            //c1 adquira el valor final de n1, y c1 al ser char despues al imprimirlo lo imprimira como su valor en la tabla ASCII
  c2=n2;            //c2 adquira el valor final de n2, y c2 al ser char despues al imprimirlo lo imprimira como su valor en la tabla ASCII
  c3=n3;            //c3 adquira el valor final de n3, y c3 al ser char despues al imprimirlo lo imprimira como su valor en la tabla ASCII
  c4=n4;            //c4 adquira el valor final de n4, y c4 al ser char despues al imprimirlo lo imprimira como su valor en la tabla ASCII
  printf("Valor primer byte: %d \n",n1);
  printf("Valor segundo byte: %d \n",n2);
  printf("Valor tercer byte: %d \n",n3);
  printf("Valor cuarto byte: %d \n",n4);
  printf("Valor primer caracter: %c\n",c1);
  printf("Valor segundo caracter: %c\n",c2);
  printf("Valor tercer caracter: %c\n",c3);
  printf("Valor cuarto caracter: %c\n",c4);
    
  return 0;
}