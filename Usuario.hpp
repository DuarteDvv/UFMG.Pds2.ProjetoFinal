#ifndef USUARIO_
#define USUARIO_
#include <string>
#include <iostream>
#include <list>
#include "Film.hpp"


class Usuario{
    private:
        std::string nome;
        std::string cpf;
        int acessos;

        std::list<filme*> Carrinho;
    
    public:
        Usuario(std::string nome, std::string cpf) : nome(nome), cpf(cpf) {
            this->acessos = 1;
        } 

        ~Usuario() {
        for (auto* filmePtr : Carrinho) {
            delete filmePtr;
        }
        Carrinho.clear();
        }
        
        std::string getCPF();
        std::string getNome(); 
        int getAcessos();
        void AcessAdd();
        void addCarrinho(filme*);
        void ListarCarrinho();
        void recibo(int &);


}; 
#endif


        
 