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
    this->pageRank =  new float[max_size];

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
    if(!isFriend(pessoa1, pessoa2)){
        for (int i = 0; i < size; i++){
            if (!queuePessoas[i].initialized)
            {
                cout<<"Pessoa não existe"<<endl;
                break;
            }
            if(queuePessoas[i].head->pessoa->name == pessoa1->name){
                queuePessoas[i].enqueue(pessoa2);
                queuePessoas[i].head->pessoa->numberOfFriends++;
            }

            if(queuePessoas[i].head->pessoa->name == pessoa2->name){
                queuePessoas[i].enqueue(pessoa1);
                queuePessoas[i].head->pessoa->numberOfFriends++;
            }
        }
    }

    else{
        cout<<pessoa1->name<<" e "<<pessoa2->name<<" ja sao amigas"<<endl;
    }
    
}

void Graph::printPessoas(){
    for(int i = 0; i<size; i++){
        cout<<queuePessoas[i].head->pessoa->name<<endl;
        cout<<"Page Rank: "<<queuePessoas[i].head->pessoa->pageRank<<endl;
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

void Graph::printAllRelations(){
    for(int i = 0; i < size; i++){
        Node *aux = queuePessoas[i].head;
        cout<<"Amigos de "<<queuePessoas[i].head->pessoa->name<<endl;
        while(aux->next!=nullptr){
                aux = aux->next;
                if(aux!=nullptr)
                    aux->pessoa->sayMyName();
        }
        cout<<"------"<<endl;
    }
}

bool Graph::isFriend(Pessoa *pessoa1, Pessoa *pessoa2){
    for(int i = 0; i < size; i++){

        if(queuePessoas[i].head->pessoa->name == pessoa1->name){

            Node *aux = queuePessoas[i].head;
            while(aux->next!=nullptr){

                aux = aux->next;
                if(aux->pessoa->name == pessoa2->name){

                    return true;
                }

            }
        }

    }

    return false;
}

void Graph::updatePageRank(float *rankings){
    for(int i = 0; i < size; i++){
        queuePessoas[i].head->pessoa->pageRank = rankings[i];
    }
}

int Graph::getPersonPosition(Pessoa *pessoa){
    for(int i = 0; i < size; i++){
        if(queuePessoas[i].head->pessoa->name == pessoa->name){
            return i;
            break;
        }
    }

    return -1;
}

void Graph::getPageRanks(){
    bool firstTime = true;
    float *rankings = new float[size];
    float *auxRanking = new float[size];
    int position;
    float damp = 0.85;
    for(int k = 0; k < 50; k++){

        if(firstTime){
            for(int i = 0; i < size; i++){
                rankings[i] = 1/size;
                auxRanking[i] = 1/size;
                updatePageRank(rankings);
                firstTime = false;
                
            }
        }

        else{
            
                for(int i = 0; i < size; i++){
                    auxRanking[i] = 0;
                    rankings[i] = 0;
                }

                for(int i = 0; i < size; i++){
                    Node *aux = queuePessoas[i].head;
                    float giveAway = queuePessoas[i].head->pessoa->pageRank/queuePessoas[i].head->pessoa->numberOfFriends;
                    //cout<<giveAway<<endl;
                    while(aux->next != nullptr){
                        aux = aux->next;
                        position = getPersonPosition(aux->pessoa);
                        auxRanking[position] += giveAway;

                    }
                }

                for(int i = 0; i < size; i++){
                    rankings[i] = ((1 - damp)/size) + damp*auxRanking[i];
                }

                updatePageRank(rankings);
            }
    }


}


