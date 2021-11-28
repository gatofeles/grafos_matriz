#ifndef PESSOA_H 
#define PESSOA_H 
#include <iostream>

class Pessoa{
    public:
        int id;
        float pageRank = 0;
        int numberOfFriends = 0;
        std::string name;
        std::string nickname;

        Pessoa(int id, std::string name, std::string nickname){
            this->id = id;
            this->name = name;
            this->nickname = nickname;
        }

        void sayMyName();
};

#endif