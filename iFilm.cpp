#include "Film.hpp"

bool fita::isRebobinado(){
    int Randombool;
    Randombool = std::rand() % 2;
    if(Randombool == 1){
        return true;
    }
    else{
        return false;
    }
}

