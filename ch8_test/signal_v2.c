#include "include/csapp.h"

// using SIGCHLD to reaps child process.


void handler1(int sig){
    int old_errno = errno;

    while (waitpid(-1, NULL, 0) > 0){
        Sio_puts("Handler reaped child\n");
    }
    if (errno != ECHILD){
        Sio_error("hhh waitpid error\n");
    }
    Sleep(1);

    errno = old_errno;
}

int main(){
    Signal(SIGCHLD, handler1);
    
    // Parent creates child
    for (int i = 0; i < 3; i++){
        if (Fork() == 0){
            printf("Hello from child %d\n", (int)getpid());
            exit(0);
        }
    }

    // Parent waits for terminal input 
    // and then processes it
    char buf[MAXBUF];
    int n = Read(STDIN_FILENO, buf, sizeof(buf));

    printf("Parent processing input, read %d bytes\n", n);

    while (1)
        ;

    return 0;
}