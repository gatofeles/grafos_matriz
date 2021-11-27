#ifndef GRAPH_H 
#define GRAPH_H 

#include <iostream>
#include "queue.h"

class Graph{
    public:
        Graph(int max_size = 1000);
        ~Graph();
        void addPessoa(Pessoa *pessoa);
        void addRelation(Pessoa *pessoa1, Pessoa *pessoa2);
        void printGraph();
        void printPessoas();
        void printRelations(Pessoa *pessoa);
    
    private:
        int max_size;
        Queue *queuePessoas;
        int size;

};

#endif