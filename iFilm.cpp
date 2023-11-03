#include "Film.hpp"
#include <ctime>

bool fita::isRebobinado(){
    std::srand(static_cast<unsigned>(std::time(0))); //Torna mais aleatorio

    int Randombool = rand() % 2; // de 0 a N-1 | N = 2
    if(Randombool == 1){
        return true;
    }
    else{
        return false;
    }
}

