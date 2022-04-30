#include<stdio.h> 
#include<stdlib.h> 
int main(int argc,char *argv[]){ 
  printf("location of code :%p\n\n",(void *) main); 
  printf("location of heap:%p \n \t\t %p\n\n",malloc(1),malloc(1)); 
  int x = 114;
  int y = 514; 
  printf("location of stack:%p \n \t\t%p\n",(void *) &x,(void *) &y);
  return x; 
  }


