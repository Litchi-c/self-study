#include "./include/csapp.h"

int main(){
  pid_t pid;
  int x = 1;

  pid = fork();

  pid = fork();
  if (pid == 0){
    printf("child : x = %d\n", ++x);
    exit(0);
  } 
  
  printf("parent : x = %d\n", --x);
  exit(0);
  
}