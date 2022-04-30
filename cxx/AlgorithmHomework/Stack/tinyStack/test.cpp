#include <iostream>
#include "Stack.h"
int main(){
    Stack s;
    std::string ss;
    while (std::cin >> ss){
        if (ss == "-")
            std::cout << s.pop() << " ";
        else
            s.push(std::move(ss));
    }
    std::cout << std::endl;
    return 0;
}

/*
 * IN:
 * to be or not to - be - - that - - - is
 * OUT:
 * to be not that or be
 * */