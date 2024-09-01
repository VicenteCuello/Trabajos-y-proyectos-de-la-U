#include <stdlib.h>          //con ayuda de compañero Pedro Gajardo
#include <stdio.h>

int main(){
  int n,m,p;
  do{
	printf("Ingrese un numero entero mayor que 0:\n");
	scanf("%d",&n);
  }while(n<0);                                                       //se verifica que n se mayor a 0
  int mat[2][n];
  printf("Escriba %d coordenadas x e y:\n",n);
  for(int i=0;i<n;i++){
	for(int j=0;j<2;j++){
		scanf("%d",&mat[j][i]);              //se crea una matriz de 2 columnas para que se cumpla (x,y) y n filas                       
	}
}
  printf("Las coordenadas ordenadas de menor a mayor son:\n");
  for(int i=0;i<n;i++){
	for(int j=i+1;j<n;j++){             
		if(mat[0][j]==mat[0][i]){               //ordenar los casos para cuando las x sean iguales
			if(mat[1][j]<mat[1][i]){        //se toma que si mat[1][j](sucesor de de mat[1][i]) es menor que mat[1][i] se hace lo que sucede a continuecion  que sirve ya que los x son iguales que se ordenen dependiendo de sus y
				m=mat[0][j];
				mat[0][j]=mat[0][i];
				mat[0][i]=m;            //estos tres pasos sirve para verificar que los x son iguales
				p=mat[1][j];
				mat[1][j]=mat[1][i];
				mat[1][i]=p;            //aqui con los tres pasos sirve para ver la diferencia entre las y, asi la maquina pueda ver que (x,y)  va primero (ej:si tenemos (1,1) y (1,2), se ordena tal que (1,1) vaya primero
			}
		}else{                                  //ordenar los casos en el que los x son distintos
			if(mat[0][j]<mat[0][i]){        //se toma que si mat[0][j](sucesor de de mat[o][i]) es menor que mat[0][i], se aplica la siguiente operacion para se ordenen de menor a mayor dependiendo del x 
				m=mat[0][j];            
				mat[0][j]=mat[0][i];
				mat[0][i]=m;            //con estos tres pasos se ordenan de menor a mayor los x (ej:si tenemos (1,1) y (2,1), (1,1) va ir primero
			}
		}
	}
	printf("%d %d\n",mat[0][i],mat[1][i]);          //se imprimen los (x,y) de los valores entregados ordenados de menor a mayor
  }	
  return 0;
}