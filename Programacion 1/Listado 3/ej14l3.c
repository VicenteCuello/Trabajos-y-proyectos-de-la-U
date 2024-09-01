#include <stdio.h>   //con ayuda de Maximiliano López, nombre timus Vicente Cuello
#include <stdlib.h>


int main(){
 char pinguino[20];   //se crea un arreglo almancene n
 int n;
 int e=0;             //se crean 3 variables para los tres tipos de pinguinos
 int l=0;
 int m=0;
 scanf("%d", &n);
 for(int i=0; i<n; i++){
    scanf("%s", pinguino);
    if(pinguino[0]=='E'){        //si el primer caracter de la palabra ingresada es E, la variable e aumentara de valor
        e++;
    }else if(pinguino[0]=='L'){  //si el primer caracter de la palabra ingresada es L, la variable l aumentara de valor
        l++;
    }else if(pinguino[0]=='M'){  //si el primer caracter de la palabra ingresada es M, la variable m aumentara de valor
         m++;
    }
    scanf("%s", pinguino);
  }
 if(e>m && e>l){                 //Si la variable e es mayor a las otras, el programa imprimira Emperor Penguin
    printf("Emperor Penguin");
}
 if(l>m && l>e){
    printf("Little Penguin");    //Si la variable l es mayor a las otras, el programa imprimira Little Penguin
}
 if(m>e && m>l){
    printf("Macaroni Penguin");  //Si la variable m es mayor a las otras, el programa imprimira Macaroni Penguin
}
    return (0);
}   