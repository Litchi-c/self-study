#include "Stack.h"
#include <string>
#include <cstdlib>
#include <utility>

Stack::Stack() {

}

void Stack::push(std::string const &item) {
    Node *oldFirst = first;
    first = new Node();
    first->data_ = item;
    first->next_ = oldFirst;
}

void Stack::push(std::string &&item) {
    Node *oldFirst = first;
    first = new Node();
    first->data_ = std::move(item);
    first->next_ = oldFirst;
}


std::string Stack::pop() {
    std::string item = first->data_;
    Node *oldFirst = first;
    first = first->next_;
    std::free(oldFirst);
    return item;
}

bool Stack::isEmpty() {
    return first == nullptr;
}

bool Stack::isFull(){
    return false;
}

int Stack::size() {
    return 0;
}
