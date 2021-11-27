#include <iostream>
#include "pessoa.h"

void Pessoa::sayMyName(){
    
    std::cout << "My name is " << this->name << " and my nickname is " << this->nickname << std::endl;
        
}