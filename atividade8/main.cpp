#include <iostream>
#include <string>
#include "pessoa.h"
#include "graph.h"
using namespace std;

int main(){

    Pessoa *julia = new Pessoa(1, "Julia", "julinha");
    Pessoa *joao = new Pessoa(2, "Joao", "jo");
    Pessoa *clara = new Pessoa(3, "Clara", "lara");
    Pessoa *hugo = new Pessoa(4, "Hugo", "hunter");
    Pessoa *pedro = new Pessoa(5, "Pedro", "lince");
    Pessoa *alice = new Pessoa(6, "Alice", "nice");

    Graph *graph = new Graph(100);

    graph->addPessoa(julia);
    graph->addPessoa(joao);
    graph->addPessoa(clara);
    graph->addPessoa(hugo);
    graph->addPessoa(pedro);
    graph->addPessoa(alice);

    graph->addRelation(julia, joao);
    graph->addRelation(julia, clara);
    graph->addRelation(hugo, clara);
    graph->addRelation(alice, clara);
    graph->addRelation(hugo, alice);
    graph->addRelation(julia, alice);
    graph->addRelation(pedro, alice);

    graph->printRelations(julia);
    graph->printRelations(joao);
    graph->printRelations(clara);

    cout<<"----- *Complete Graph with all friendships* -----"<<endl;
    graph->printAllRelations();

    cout<<"----- All Graph vertices *pessoas* -----"<<endl;
    graph->getPageRanks();
    graph->printPessoas();


    return 0;
}