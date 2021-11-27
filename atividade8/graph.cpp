#include <iostream>
#include <string>
#include "queue.h"
#include "pessoa.h"
#include "graph.h"
using namespace std;

Graph::Graph(int max_size)
{
    this->max_size = max_size;
    this->size = 0;
    this->queuePessoas = new Queue[max_size];

}

void Graph::addPessoa(Pessoa *pessoa)
{   
    if (size < max_size)
    {
        queuePessoas[size].initialized = true;
        queuePessoas[size].enqueue(pessoa);
        size++;

    }
    else{
        cout<<"Graph is full!"<<endl;
    }
}

void Graph::addRelation(Pessoa *pessoa1, Pessoa *pessoa2)
{
    for (int i = 0; i < size; i++)
    {
        if (!queuePessoas[i].initialized)
        {
            cout<<"Pessoa não existe"<<endl;
            break;
        }
        if(queuePessoas[i].head->pessoa->name == pessoa1->name){
            queuePessoas[i].enqueue(pessoa2);
        }

        if(queuePessoas[i].head->pessoa->name == pessoa2->name){
            queuePessoas[i].enqueue(pessoa1);
        }
    }
}

void Graph::printPessoas(){
    for(int i = 0; i<size; i++){
        cout<<queuePessoas[i].head->pessoa->name<<endl;
    }
}

void Graph::printRelations(Pessoa *pessoa){
    for(int i = 0; i < size; i++){
        if(queuePessoas[i].head->pessoa->name == pessoa->name){
            Node *aux = queuePessoas[i].head;
            cout<<"Amigos de "<<queuePessoas[i].head->pessoa->name<<endl;
            while(aux!=nullptr){
                aux = aux->next;
                if(aux!=nullptr)
                    aux->pessoa->sayMyName();
            }
            cout<<"------"<<endl;
            break;
        }
    }
}


