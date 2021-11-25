#ifndef NODE_H 
#define NODE_H 

#include "pessoa.h"

typedef Pessoa ItemType;

struct Node
{
  ItemType info;
  Node* next;
};

#endif
