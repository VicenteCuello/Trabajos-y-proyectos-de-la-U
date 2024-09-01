#include <stdio.h>  //solo, nombre de usuario timus es Vicente Cuello
#include <stdlib.h>

int main() {
  int num;
  scanf("%d",&num);
  if(1<=num && num<=4) {
    printf("few");
  }
  else if(5<=num && num<=9) {
    printf("several");
  }
  else if(10<=num && num<=19) {
    printf("pack");
  }
  else if(20<=num && num<=49) {
    printf("lots");
  }
  else if(50<=num && num<=99) {
    printf("horde");
  }
  else if(100<=num && num<=249){
    printf("throng");
  }
  else if(250<=num && num<=499) {
    printf("swarm");
  }
  else if(500<=num && num<=999) {
    printf("zounds");
  }
  else if(1000<=num) {
    printf("legion");
  }
  return 0;
}