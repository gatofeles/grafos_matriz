#ifndef GRAPH_H 
#define GRAPH_H 

#include <iostream>
#include "queue.h"

class Graph{
    public:
        Graph(int max_size = 1000);
        void addPessoa(Pessoa *pessoa);
        void addRelation(Pessoa *pessoa1, Pessoa *pessoa2);
        void printPessoas();
        void printRelations(Pessoa *pessoa);
        void printAllRelations();
        void getPageRanks(); 
        
    
    private:   
        int max_size;
        Queue *queuePessoas;
        int size;
        float *pageRank;
        bool isFriend(Pessoa *pessoa1, Pessoa *pessoa2);
        void updatePageRank(float *rankings);
        int getPersonPosition(Pessoa *pessoa);

};

#endif