#ifndef _FILM
#define _FILM
#include <iostream>
#include <string>

class filme{
    private:
        int codigo;
        std::string titulo;
        int quantidade;
    public:
        void setFilm();

    
  
};
class fita : public filme{
    private:
        bool rebobinado;

    public:
        
        bool isRebobinado();
};

class dvd : public filme{
    private:
        bool promocao;
        bool estoque;
        bool lancamento;
    public:
        void isWhat();
};

#endif
