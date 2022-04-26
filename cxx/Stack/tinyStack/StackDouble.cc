#include "StackDouble.h"
#include <string>
#include <cstdlib>
#include <utility>

StackDouble::StackDouble() = default;

void StackDouble::push(double const &item) {
    Node *oldFirst = first;
    first = new Node();
    first->data_ = item;
    first->next_ = oldFirst;
}

void StackDouble::push(double &&item) {
    Node *oldFirst = first;
    first = new Node();
    first->data_ = std::move(item);
    first->next_ = oldFirst;
}


double StackDouble::pop() {
    double item = first->data_;
    Node *oldFirst = first;
    first = first->next_;
    delete oldFirst;
    return item;
}

bool StackDouble::isEmpty() {
    return first == nullptr;
}

bool StackDouble::isFull(){
    return false;
}

int StackDouble::size() {
    return 0;
}
