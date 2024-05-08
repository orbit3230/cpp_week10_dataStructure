#include "list.h"

List::List() : LinkedList() {
}

List::~List() {
    LinkedList::~LinkedList();
}