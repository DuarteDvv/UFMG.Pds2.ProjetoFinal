#ifndef _FILM
#define _FILM
#include <iostream>
#include <string>

class filme{
    private:
        int codigo;
        std::string titulo;
        int quantidade;

    
  
};//utlizar classe abstrata para aluguel

class fita : public filme{
    private:
        bool rebobinado;

    public:
        bool fita::isRebobinado();
};

class dvd : public filme{
    //definir metodo abstrato

};

class lanca : public dvd{

};

class estoque : public dvd{

};

class promocao : public dvd{

};




#endif
