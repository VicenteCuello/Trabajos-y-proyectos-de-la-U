#include <stdio.h>        //solo
#include <stdlib.h>
#include <math.h>         //se uso la libreria math.h para usar fabs para sacar valor absoluto y sqrt para sacar la raiz cuadrada
  

int main() {
  int n,i;
  printf("Escriba un numero entero:\n");
  scanf("%d",&n);
  printf("Ahora escriba %d numeros:\n",n);
  double var[n];
  for(i=0;i<n;i++){
    scanf("%lf",&var[i]);
  }
  float men;
  men=var[0];
  for(i=0;i<n;i++){
    if(var[i]<men){
      men=var[i];
    }
  }
  printf("El menor numero es %E\n",men);
  float may;
  may=var[0];
  for(i=0;i<n;i++){
    if(may<var[i]){
      may=var[i];
    }
  }
  printf("El numero mayor es %.10f\n",may);
  double prom,promf;
  prom=0;
  for(i=0;i<n;i++){
    prom=prom+var[i];
  }
  promf=prom/n;
  printf("El promedio es %.10lf\n",promf);
  long double med;
  if(n%2==0){
    med=var[((n/2)+((n/2)+1))/n];
  }
  if(n%2!=0){
    med=var[n/2];
  }
  printf("La mediana es %Lf\n",med);
  double d,dm;
  d=0;
  for(i=0;i<n;i++){
    d=d+fabs(var[i]-promf);
  }
  dm=d/n;
  printf("La desviacion media es de %lf\n",dm);
  float e,de;
  e=0;
  for(i=0;i<n;i++){
    e=e+(fabs(var[i]-promf)*fabs(var[i]-promf));
  }
  de=sqrt(e/n);
  printf("La desviacion estandar es de %.3g\n",de);
  short v;
  v=e/(n-1);
  printf("La varianza es %hd\n",v);

  
  
  return 0;
}