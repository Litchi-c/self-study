#include "./include/csapp.h"

typedef unsigned long long uint64;
// private function
static uint64 snooze(uint64 secs){
    uint64 ret = Sleep(secs);
    printf("Slept for %lld of %lld secs\n", (secs - ret), secs);
    return ret;
}

int main(int argc, char **args){
    snooze(atoi(args[1]));
    return 0;
}