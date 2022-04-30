#ifndef __STACKH__
#define __STACKH__

#include <string>

class Stack{
public:
    Stack();
    void push(const std::string &item);
    void push(std::string &&item);
    std::string pop();
    bool isEmpty();
    bool isFull();
    int size();

private:
    struct Node{
        std::string data_;
        Node* next_;
    };
    Node* first = nullptr;


};









#endif // __STACKH__
