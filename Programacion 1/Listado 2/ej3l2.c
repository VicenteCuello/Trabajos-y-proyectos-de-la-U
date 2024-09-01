#include <stdio.h>     //ayuda para sacar el numero mayor y menor del siguiente video https://www.youtube.com/watch?v=sKT01ryXqlc
#include <stdlib.h>    //voy a explicar el codigo entero igual aunque solo me ayude en la suma por si acaso

int main(){
  int n;
  int cont=0; 
  do{                       //se verifica que n es un valor mayor que 0
    switch(cont){
      default : printf("Por favor, escriba un numero entero mayor a 0:\n");  
      break;
    }
    scanf("%d",&n);
    cont++;
  }while(n<=0);
  int var[n];            
    for(int i=0;i<n;i++){                                  
      printf("Ahora escriba %d numeros enteros:\n",n);
      scanf("%d",&var[i]);                                  //se crea un arreglo que tome n valores que despues tu escribas en la entrada
    }
    int may,men;
    may=var[0];
    men=may;                        //men y may toman el primer valor del arreglo
    for(int i=0;i<n;i++){
      if(may<var[i]){              
        may=var[i];                 //si en el arreglo hay un numero mayor que el primero del arreglo, ese sera el nuevo valor de may
      }
      else if(var[i]<men){
        men=var[i];                //si en el arreglo hay un numero menor al primer valor del arreglo, ese sera el nuevo valor de men
      }
    }
    int prom,promf;
    prom=0;                  
    for(int i=0;i<n;i++){
      prom=prom+var[i];       //prom va adquiriendo el valor de todos los elementos sumados    
    }
    promf=prom/n;             //prom al ya tener todos los valores del arreglo sumados, se divide por la cantidad de arreglos que habia para sacar promf(promedio final)
  int m;
  if(n%2==0){                      
    m=var[((n/2)+(n/2+1))/n];   //si n es numero par, en la zona del medio va haber 2 numeros, se suman y se dividen por 2, dando un numero no entero que automaticamente se aproxima a uno del arreglo
  }
  else{
    m=var[n/2];             //al n ser impar, solo se toma el valor de la mitad de var[n]
  }
    printf("%d es el numero menor,%d el mayor,%d es el promedio y %d es la mediana\n",men,may,promf,m);

  return 0;

}
