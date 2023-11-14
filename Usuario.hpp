#ifndef USUARIO_
#define USUARIO_
#include <string>
#include <iostream>
#include <list>


class Usuario{
    private:
        std::string nome;
        std::string cpf;
        int acessos;
    
     public:
        Usuario(std::string nome, std::string cpf) : nome(nome), cpf(cpf) {
            this->acessos = 1;
        } 
        
        std::string getCPF();
        std::string getNome(); 
        int getAcessos();
        void AcessAdd();

}; 
#endif