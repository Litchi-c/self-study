#ifndef __STACKH__
#define __STACKH__

#include <string>

class QueueOfStrings{
public:
    QueueOfStrings()= default;
    void enqueue(const std::string &item);
    void enqueue(std::string &&item);
    std::string dequeue();
    bool isEmpty();
    bool isFull();
    int size();

private:
    struct Node{
        std::string data_;
        Node* next_;
    };
    Node* head = nullptr;
    Node* tail = nullptr;
};









#endif // __STACKH__
