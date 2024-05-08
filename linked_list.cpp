#include <iostream>
#include "linked_list.h"
using namespace std;

// --- public ---
LinkedList::LinkedList() {
    head_ = nullptr;
    size_ = 0;
}

LinkedList::~LinkedList() {
    Node* next = head_;
    while(next != nullptr) {
        Node* delete_node = next;
        next = next->next_;
        delete delete_node;
    }
    // 필요없지만 명확성을 위해
    head_ = nullptr;
    size_ = 0;
}

void LinkedList::print() {
    Node* next = head_;
    // size를 이용한 for문으로도 가능
    while(next != nullptr) {
        cout << next->value_ << " ";
        next = next->next_;
    }
    cout << endl;
}

// --- protected ---
void LinkedList::insert(int index, int value) {
    size_++;
    // ** 잘못된 인덱스에 대한 처리는 생략 **
    // 맨 앞에 삽입하려는 경우 (헤드가 바뀌어야 하는 경우)
    if(index == 0) {
        Node* new_node = new Node(value);
        new_node->next_ = head_;
        head_ = new_node;
        return;
    }
    // 이후에 삽입하려는 모든 경우
    Node* next = head_;
    for(int i = 1 ; i < index ; i++) {
        next = next->next_;
    }
    Node* new_node = new Node(value);
    new_node->next_ = next->next_;
    next->next_ = new_node;
    return;
}

int LinkedList::get(int index) {
    // ** 잘못된 인덱스에 대한 처리는 생략 **
    Node* search = head_;
    for(int i = 0 ; i < index ; i++) {
        search = search->next_;
    }
    int value = search->value_;
    return value;
}

void LinkedList::remove(int index) {
    size_--;
    // ** 잘못된 인덱스에 대한 처리는 생략 **
    // 맨 앞을 지우려는 경우 (헤드가 바뀌어야 하는 경우)
    if(index == 0) {
        Node* delete_node = head_;
        head_ = head_->next_;
        delete delete_node;
        return;
    }
    // 이후를 지우려는 모든 경우
    Node* next = head_;
    for(int i = 1 ; i < index ; i++) {
        next = next->next_;
    }
    Node* delete_node = next->next_;
    next->next_ = delete_node->next_;
    delete delete_node;
    return;
}