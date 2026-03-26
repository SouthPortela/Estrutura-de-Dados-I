#include <stdio.h>

int down(int n){
  if(n==0){
    return 1;
  }else{
    printf("%d\n", n);
    n--;
    return down(n);
  } 
}

int up(int n){
  if(n!=0){
    return up(n-1);
    printf("%d\n", n);
  }
  else
    return 1;
}

int main(){
  int num = 10;
  printf("Decrescente: \n");
  down(num);
  printf("\n\nCrescente: \n");
  up(num);
  printf("\n\n\n%d", num);
  return 0;
}

/*
int down (int n) {
  if(n == 0) {
    return 1;
  }
  else {
    prinft("%i",n);
    down(n-1);
  }
}
*/
