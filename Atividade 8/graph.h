#ifndef GRAPH_H 
#define GRAPH_H 

#include "queue.h"

class Graph {  
 private:  
  int NULL_EDGE; // Constante para aresta nula. 
  int numVertices; // Número de vértices adicionados.
  Pessoa* pessoa; // Array com todos os vértices.
  int getIndex(Pessoa);
 public:
  Graph(int max = 50, int null = 0);  // construtor
  ~Graph(); // destrutor

  void addVertex(Pessoa);
  void addEdge(Pessoa, Pessoa, int);

  int getWeight(Pessoa, Pessoa);
  void getAdjacents(Pessoa, Queue&);
  void clearMarks();
  void markPessoa(Pessoa);
  bool isMarked(Pessoa);
  void printMatrix();
};

#endif
