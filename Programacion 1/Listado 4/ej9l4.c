#include <stdlib.h>         //con ayuda de Maximiliano Lopez
#include <stdio.h>
int** matrizzz(int n, int m){                   //se crea una funcion que contengan la matriz y sus elementos
    int **mat1=malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        mat1[i]=malloc(m*sizeof(int));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("Ingrese el elemento de la fila %d y columna %d: ",i,j);
            scanf ("%d",&mat1[i][j]);
        }
    }
    return mat1;
}
void modificarMatriz(int n, int m,int **mat1){          //se crea la funcion que pide el ejercicio
    for(int i=0;i<n;i++){                               //y que reemplaza los 1 por -1
        for(int j=0;j<n;j++){
            if(mat1[i][j]==1){
                mat1[i][j]=-1;
            }
        }
    }
}
void printMat(int n, int m, int **mat1){       //se crea una funcion que imprima el contenido de la matriz
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        printf("%d",mat1[i][j]);
    }
        printf("\n");
    }
}
int **free_mat(int n,int **mat1){            //se crea una funcion que desvincula el puntero de la matriz 
    for(int i=0;i<n;i++){
        free(mat1[i]);
    }
    free(mat1);
    return NULL;
}

int main(){
int n,m;
printf("Ingrese el numero de filas de la matriz:");          //se pide las filas y columnas de la matriz
scanf("%d",&n);
printf("Ingrese el numero de columnas de la matriz:");
scanf("%d",&m);
int** mat1=matrizzz(n,m);                                //con un puntero se vincula a la matriz con la funcion que almcenara sus datos
modificarMatriz(n,m,mat1);                               //se cambian los 1 por -1
printMat(n,m,mat1);                                      //se imprime los valores cambiados de la matriz
free_mat(n,mat1);
    return(0);

}
  