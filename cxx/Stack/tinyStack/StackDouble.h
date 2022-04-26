#ifndef __STACKH__
#define __STACKH__

#include <string>

class StackDouble{

public:
    StackDouble();
    void push(const double &item);
    void push(double &&item);
    double pop();
    bool isEmpty();
    bool isFull();
    int size();



private:
    struct Node{
        double data_;
        Node* next_;
    };
    Node* first = nullptr;


};


#endif // __STACKH__
