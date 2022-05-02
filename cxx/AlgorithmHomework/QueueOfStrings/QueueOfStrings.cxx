#include "QueueOfStrings.hpp"

bool QueueOfStrings::isEmpty(){
  return head == nullptr;
}

void QueueOfStrings::enqueue(const std::string &item) {
    Node *oldFirst = tail;
    tail = new Node();
    tail->data_ = item;
    tail->next_ = nullptr;

    if (this->isEmpty())
        head = tail;
    oldFirst->next_ = tail;
}

void QueueOfStrings::enqueue(std::string &&item) {
    Node *oldFirst = tail;
    tail = new Node();
    tail->data_ = std::move(item);
    tail->next_ = nullptr;

    if (this->isEmpty())
        head = tail;
    oldFirst->next_ = tail;
}

std::string QueueOfStrings::dequeue() {
    std::string res = head->data_;
    Node *oldFirst = head;
    head = head->next_;
    if (this->isEmpty()){
        tail = nullptr;
    }
    delete oldFirst;
    return res;
}

bool QueueOfStrings::isFull() {
    return (head == tail) && head && tail ;
}

int QueueOfStrings::size() {
    // size is O(N)
    // for a List to calculate a size.
    return 0;
}
