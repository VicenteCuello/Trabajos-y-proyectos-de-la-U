#include <stdio.h>     //solo, nombre de usuario timus es Vicente Cuello
#include <stdlib.h>

int main() {
  int lock1,lock2;
  scanf("%d %d",&lock1,&lock2);
  if(0<=lock1 && lock1<=9999 && 0<=lock2 && lock2<=9999){
    if((lock1%2)==0 || (lock2%2)!=0){
      printf("yes");
    }
    else if((lock1%2)!=0 || (lock2%2)==0){
      printf("no");
    }
    
  }

  return 0;
}