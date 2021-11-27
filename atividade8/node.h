#ifndef NODE_H 
#define NODE_H 

#include "pessoa.h"
class Node{
    public:
        Node *next = nullptr;
        Node *prev = nullptr;
        Pessoa *pessoa;

        Node(Pessoa *pessoa){
            this->pessoa = pessoa;
        }


};
#endif