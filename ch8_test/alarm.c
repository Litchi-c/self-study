#include "./include/csapp.h"

int main(){
  int res;  
  for (int i = 0; i < 5; i++){
    res = alarm(1);
    printf("%d\n", res);
  } 
  return 0;
} 
