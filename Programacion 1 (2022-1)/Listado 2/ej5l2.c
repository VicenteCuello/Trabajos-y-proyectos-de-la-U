#include <stdlib.h>        //con ayuda de compañero Pedro Gajardo
#include <stdio.h>

int main(){
  int n,m;
  printf("Ingrese un numero entero:\n");
  scanf("%d",&n);
  int var[n];
  for(int i=0;i<n;i++){
	scanf("%d",&var[i]);      //se crea un arreglo que tome n valores que despues tu escribas en la entrada
	}
  printf("Pares ordenados de menor a mayor:\n");
  for(int i=0;i<n;i++){
	for(int j=i+1;j<n;j++){         //se crea un arreglo que sea los valores sea mayores que en var[i]
		if(var[j]<var[i]){        //al pedir que si var[i] sea mayor que var[j], haremos que var[i] se ordene de menor a mayor
			m=var[j];           //m va aquiriendo los valores de var[j]
			var[j]=var[i];      //el valor de un elemento de var[j] adquire el valor de var[i] para que siga el ciclo
			var[i]=m;          //var[i] adquiere de a poco los valores de m empezando por en el menor y terminando en el mayor
		}
	}
  }
  int par[n],imp[n];
  for(int i=0;i<n;i++){
	if(var[i]%2==0){          //ahora de lo anterior solo tomamos los valores que sean pares
		par[i]=var[i];      //se meten los valores pares en otro arreglo
		printf("%d\n",par[i]);        //se imprimen estos valores que gracias a lo anterior van a ser pares ordenados de mayor a menor
	}
  }
  printf("Impares ordenados de mayor a menor:\n");
  for(int i=0;i<n;i++){
	for(int j=i+1;j<n;j++){        
		if(var[i]<var[j]){           //lo mismo que antes, pero a la diferencia es que ahora var[j] es mayor que var[i], esto es para que en vez de ordenar los valores de menor a mayor, se ordenen de mayor a menor
			m=var[j];
			var[j]=var[i];
			var[i]=m;
		}
	}
  }
  for(int i=0;i<n;i++){
	if(var[i]%2!=0){             //al ya tener los valores ordenados de mayor a menor, tomamos solo los valores impares
		imp[i]=var[i];        //se guardan los valores impares ordenados en otro arreglo
		printf("%d\n",imp[i]);     //se imprimen los valores impares ordenados de mayor a menor
	}
  }
	return 0;
}