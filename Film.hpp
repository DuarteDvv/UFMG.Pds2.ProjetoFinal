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
        filme(){
            codigo = 0;
            titulo = {};
            quantidade = 0;
        }

        void setFilme(int,int,std::string); 

        int getCod();
        std::string getTitulo();
        int getQuantidade();
  
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
        dvd(){
            promocao = false;
            estoque = false;
            lancamento = false;
        }



        void setFilme(int,int,std::string,std::string);
        
        bool isPromo();
        bool isEstoque();
        bool isLanca();
};

#endif
