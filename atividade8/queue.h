#ifndef QUEUE_H 
#define QUEUE_H 
#include "node.h"
#include "pessoa.h"

class Queue{
    public:
        void enqueue(Pessoa *pessoa);
        void dequeue();
        bool isEmpty();
        void print();
        bool initialized = false;
        bool empty = false;
        Node *head = nullptr;
        Node *tail = nullptr;       
};

#endif