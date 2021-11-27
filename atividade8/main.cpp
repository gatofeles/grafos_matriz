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

    Graph *graph = new Graph(100);

    graph->addPessoa(julia);
    graph->addPessoa(joao);
    graph->addPessoa(clara);
    graph->addPessoa(hugo);

    graph->addRelation(julia, joao);
    graph->addRelation(julia, clara);

    graph->printRelations(julia);
    graph->printRelations(joao);
    graph->printRelations(clara);

    //graph->printPessoas();


    return 0;
}