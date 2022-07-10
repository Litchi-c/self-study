// WARNING: this code is buggy
#include "include/csapp.h"

#define BLOCK(set, old_set) Sigprocmask(SIG_BLOCK, &(set), &(old_set));
#define UNBLOCK(old_set) Sigprocmask(SIG_SETMASK, &(old_set), NULL);


void addjob(pid_t pid){}
void deletejob(pid_t pid){}
void initjob(){}

void handler(int sig){
    int old_errno = errno;
    sigset_t mask_all, prev_all;
    pid_t pid;

    Sigfillset(&mask_all);

    while( (pid = waitpid(-1, NULL, 0)) > 0){
        // reap zombie child
        BLOCK(mask_all, prev_all)
        deletejob(pid);
        UNBLOCK(prev_all)
    }
    
    if (errno != ECHILD)
        Sio_error("waitpid error");
    
    errno = old_errno;
}


int main(int argc, char **argv){
    pid_t pid;
    sigset_t mask_all,prev_all;

    Sigfillset(&mask_all);
    Signal(SIGCHLD, handler);

    initjob(); // init the  job list.

    while (1)
    {
        if ((pid = Fork()) == 0){
            Execve("/bin/date", argv, NULL);
        }

        BLOCK(mask_all, prev_all)
            addjob(pid);
        UNBLOCK(prev_all)
    }
    

}