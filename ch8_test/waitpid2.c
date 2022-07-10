// waitpid回收子进程，不按顺序

#include "./include/csapp.h"

#define N 10

int main(){

    pid_t pid[N];
    pid_t retpid;

    for (int i = 0; i < N; i++){
        if ((pid[i] = Fork()) == 0)
            exit(100 + i);
    }

    int status;
    int i = 0;
    while ((retpid = waitpid(pid[i++], &status, 0)) > 0)
    {
        if (WIFEXITED(status))
// WIFEXITED Return true  if the child process terminated normally.
// via a call to exit or a return.
            printf("child %d terminated normally with exit status %d\n",
            retpid, WEXITSTATUS(status));
// Returns the exit status of a normally terminated child.
// This status is only defined if WIFEXITED() returned true
        else
            printf("child %d terminated abnormally\n", retpid);
    }

    if (errno != ECHILD)
    {
        unix_error("waitpid error");
// If the calling process has no children, 
//   then waitpid returns −1 and sets errno to ECHILD.
// If the waitpid function was interrupted by a signal, 
//   then it returns −1 and sets errno to EINTR.
    }
    exit(0);
}