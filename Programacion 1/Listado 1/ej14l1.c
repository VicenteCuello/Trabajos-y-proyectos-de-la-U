#include <stdio.h>       //ayudado por compañero Nicolas Jarpa, nombre de usuario timus es Vicente Cuello
#include <stdlib.h>

int main() {
  int n,k,op1,op2;
  scanf("%d %d",&n,&k);
  if(k==0 && n==0){                //obviamente si no hay bistecs no se cocina nada
    printf("0");
  }
  else if(n<=k){                   //al ser k el numero de bistecs que caben la parrilla, si la parilla puede contener todos los bistecs significa que siempre se tardara solo dos minutos
    printf("2");
  }
  else if(k<n){                    //para los casos en que la parrilla no pueda con todos los bistecs
    op1=(n*2)%k;                   //operacion para distinguir los casos en que haya numeros pares e impares en k (se multiplica por dos al igual que en op2 para que de una division mas adecuada a lo que pide el ejercicio)
    op2=(n*2)/k;                   //operacion para que en los print escriba en numero de bistecs que caben en la parrilla 
    if(op1==0){                    //si n y k son ambos pares o ambos impares          
      printf("%d",op2);            //al ser ambos pares o impares va dar una cantida logica (que se haria en la vida real de esperar cocinar los bistecs por ambos lados y despues sacarlos) en el caso de los minutos necesarios(ejem: 4 2 = 4)
    }
    else{                          //en el caso en el que n y k uno sea par y el otro impar y viceversa
      printf("%d",op2 + 1);        //se le suma uno para que de en todos los casos en los que la maquina lo pensaria mas ilogica(poner dos bistecs, sacar uno y poner otro,se cose el que siguio en la parrilla y hechas el que sacaste antes y este queda con el que pusiste despues) de hacer bistecs mas rapido (ejem: 3 2=3)
    }
    
  }


  

  return 0;
}