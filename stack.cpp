#include "stack.h"

Stack::Stack() { }

Stack::~Stack() { }

void Stack::push(int data) {
    // 0 : top of the stack
    insert(0, data);
}

int Stack::pop() {
    // 0 : top of the stack
    int data = get(0);
    remove(0);
    return data;
}

int Stack::peek() {
    // 0 : top of the stack
    return get(0);
}

Stack& Stack::operator+=(int data) {
    push(data);
    return *this;
}