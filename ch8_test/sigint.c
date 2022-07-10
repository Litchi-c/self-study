#include "include/csapp.h"

void hello(int sig){
    printf("hello");
}

int main(){
    sigset_t mask;
    sigset_t prev_mask; // Save old set.

    Sigemptyset(&mask); // Empty var mask
    Sigaddset(&mask, SIGINT);

    Sigprocmask(SIG_BLOCK, &mask, &prev_mask);
    // SIG_BLOCK: Add the signals in set from blocked(blocked |= set)
    // SIG_UNBLOCK: Remove the signals in set from blocked(blocked &= ~set)
    // SIG_SETMASK: blocked = set

    Sleep(3);
    Sigprocmask(SIG_SETMASK, &prev_mask, NULL);
    // // unblocking the signals in set.
    while(1);

    return 0;
}