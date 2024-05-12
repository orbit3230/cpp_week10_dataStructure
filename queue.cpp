#include "queue.h"

Queue::Queue() { }

Queue::~Queue() { }

void Queue::push(int data) {
    // 0 : front of the queue
    insert(size_, data);
}

int Queue::pop() {
    // 0 : front of the queue
    int data = get(0);
    remove(0);
    return data;
}

int Queue::peek() {
    // 0 : front of the queue
    return get(0);
}

Queue& Queue::operator+=(int data) {
    push(data);
    return *this;
}