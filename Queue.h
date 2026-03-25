#ifndef queue_h
#define queue_h
#include "Node.h"

class Queue {
    NodePtr headPtr, tailPtr;
    int size;

public:
    void enqueue(int ord, int qty); // Takes 2 info
    int dequeue();
    Queue();
    ~Queue();
};

void Queue::enqueue(int ord, int qty) {
    NodePtr new_node = new NODE(ord, qty);
    if (new_node) {
        if (size == 0) {
            headPtr = new_node;
        } else {
            tailPtr->set_next(new_node);
        }
        tailPtr = new_node;
        size++;
    }
}

int Queue::dequeue() {
    if (size > 0) {
        NodePtr t = headPtr;
        int total_price = t->get_price();
        headPtr = headPtr->get_next();
        
        if (headPtr == NULL) tailPtr = NULL;
        
        delete t;
        size--;
        return total_price;
    }
    return -1; // Flag for empty queue
}

Queue::Queue() {
    headPtr = NULL;
    tailPtr = NULL;
    size = 0;
}

Queue::~Queue() {
    while (size > 0) dequeue();
}

#endif