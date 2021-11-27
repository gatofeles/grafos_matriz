#include <iostream>
#include "queue.h"
#include "pessoa.h"
using namespace std;

void Queue::enqueue(Pessoa *pessoa){
    Node *novo = new Node(pessoa);
    if(isEmpty()){

        head = novo;
        tail = novo;
        empty = true;
    }else{
        tail->next = novo;
        novo->prev = tail;
        tail = novo;
    }
}

bool Queue::isEmpty(){
    return !empty;
}

void Queue::dequeue(){
    if(isEmpty()){
        std::cout << "Fila vazia" << std::endl;

    }else{
        Pessoa *pessoa = head->pessoa;
        Node *aux = head;
        head = head->next;
        delete aux;
    }
}


